# to run this cmake file go to folder build
# in build run command: cmake ..
# and then: cmake --build .
# to run tests: math_test
include(./.env.cmake OPTIONAL RESULT_VARIABLE LOCAL_ENV)

cmake_minimum_required(VERSION 3.16)
#set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc") todo doplnit ikonku aplikace   
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER  ${GCC_PATH}/bin/g++)
set(CMAKE_C_COMPILER  ${GCC_PATH}/bin/gcc)

project(Kalkulacka)

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
include_directories("src/includes")

add_executable(math_test src/includes/math.cpp tests/math_test.cpp)
target_link_libraries(math_test gtest_main gmock_main)
gtest_discover_tests(math_test)

