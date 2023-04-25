CC = g++
CFLAGS = -Wall -Werror -O2

.PHONY: all pack clean test run profile

# Prelozi projekt
all:
	powershell.exe -Command "& {New-Item -ItemType Directory -Force -Path '..\build' } ; cd ..\build ; cmake .\.. -G "Ninja"; cmake --build ." ; $(WINDEPLOYQT) kalkulacka.exe

# Instalace (windeployqt)
WINDEPLOYQT = C:\Qt\6.5.0\mingw_64\bin\windeployqt.exe

# Najdenie suboru obsahujuceho Makefile
MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))

# Ulozenie cesty k suboru
SRCDIR := $(patsubst %/Makefile,%,$(MAKEFILE_PATH))
OBJDIR := $(SRCDIR)/objects

# Spracovanie vsetkych .cpp suborov
SOURCES := $(wildcard *.cpp) $(wildcard **/*.cpp) dokumentace.pdf
OBJECTS := $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

# Vytvorenie finalneho programu
TARGET = Kalkulacka

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Pravidlo na spracovanie .cpp suboru na .o subor
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/includes/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Vytvorenie adresara pre .o subory
$(OBJDIR):
	mkdir objects

# zabalí projekt tak, aby mohl být odevzdán
pack:
	powershell.exe -Command "& { \
		cd '..' ; \
		New-Item -ItemType Directory -Force -Path 'xborek12_xhrubo01_xjestr04_xkento00' ; \
		cd 'xborek12_xhrubo01_xjestr04_xkento00' ; \
		New-Item -ItemType Directory -Force -Path 'doc', 'install', 'repo' ; \
		Copy-Item -Path '..\plan', '..\mockup', '..\profiling', '..\debugging.png', \
			'..\CMakeLists.txt', '..\dokumentace.pdf', '..\screenshot.png', '..\hodnoceni.txt', \
			'..\skutecnost.txt', '..\README.md', '..\.gitignore', '..\.git', '..\.editorconfig' \
			-Destination 'repo' -Force -Recurse ; \
		Copy-Item -Path (Get-Item -Path '..\src\*' -Exclude ('html', 'latex')).FullName \
			-Destination 'repo\src' -Force -Recurse ; \
		Copy-Item -Path '..\src\html', '..\src\latex' \
			-Destination 'doc' -Force -Recurse ; \
		New-Item -ItemType Directory -Force -Path '..\build\install-exe' ; \
		Copy-Item -Path '..\build\kalkulacka.exe' -Destination '..\build\install-exe' ; \
		cd '..\build\install-exe' ; \
		$(WINDEPLOYQT) kalkulacka.exe ;\
		ISCC ..\..\inno_setup_script.iss ;\
		cd '..\..' ; \
		Compress-Archive -Path 'xborek12_xhrubo01_xjestr04_xkento00' \
			-DestinationPath 'xborek12_xhrubo01_xjestr04_xkento00.zip' -Force ; \
		Remove-Item -Path 'xborek12_xhrubo01_xjestr04_xkento00' -Recurse -Force -ErrorAction SilentlyContinue \
	}"

# Vycistenie vsetkych nepotrebnych suborov
clean:
	powershell.exe -Command "& { \
		Remove-Item -Path '..\build' -Recurse -Force -ErrorAction SilentlyContinue ; \
		Remove-Item -Path '..\$(OBJDIR)\*.o' -Force -ErrorAction SilentlyContinue ; \
		Remove-Item -Path '..\$(TARGET).exe' -Force -ErrorAction SilentlyContinue \
	}"

#spustí testy matematické knihovny
test:
	./../build/math_test.exe

run:
	./../build/kalkulacka.exe

# spustí generování dokumentace
doc:
	doxygen Doxyfile

# spustí překlad programu pro výpočet směrodatné odchylky na profiling
profile:
	g++ -c profiling.cpp -static-libstdc++
	g++ -c includes/math.cpp -static-libstdc++
	g++ profiling.o math.o -o profile -static-libstdc++
