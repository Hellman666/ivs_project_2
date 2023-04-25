# to run this cmake file go to folder build
# in build run command: cmake ..
# and then: cmake --build .
# to run tests: math_test
cmake_minimum_required(VERSION 3.5)

include(./.env.cmake OPTIONAL RESULT_VARIABLE LOCAL_ENV)
# example of ./.env.cmake
#
# STRING(STRIP "C:/Qt/6.5.0/mingw_64" QT_MINGW_PATH)
#

set(CMAKE_GENERATOR "Ninja")
set(CMAKE_BUILD_TYPE "Debug")
set(QT_QMAKE_EXECUTABLE "${QT_MINGW_PATH}/bin/qmake.exe")
set(CMAKE_PREFIX_PATH "${QT_MINGW_PATH}/lib/cmake")

project(Kalkulacka VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/img/icon.ico")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(PROJECT_SOURCES
        src/ui/main.cpp
        src/ui/mainwindow.cpp
        src/ui/mainwindow.h
        src/ui/mainwindow.ui
        src/ui/help.h
        src/ui/help.cpp
        src/ui/resource.qrc

        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(kalkulacka
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET kalkulacka APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(kalkulacka SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(kalkulacka
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(kalkulacka PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(kalkulacka PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS kalkulacka
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(kalkulacka)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test targets
enable_testing()

include(GoogleTest)
include_directories("src/includes/")

add_executable(math_test ./src/includes/math.cpp ./src/tests/math_test.cpp)
target_link_libraries(math_test gtest_main gmock_main)
gtest_discover_tests(math_test)



