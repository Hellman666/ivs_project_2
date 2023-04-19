CC = g++
CFLAGS = -Wall -Werror -O2

.PHONY: all pack clean run profile help

# Prelozi projekt
#TODO: prelozeni programu pro profiling
all:
	powershell.exe -Command "& {New-Item -ItemType Directory -Force -Path '..\build'} ; cd ..\build ; cmake .\.. -G "Ninja"; cmake --build ."

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

#TODO zabalit tak, aby odpovidalo strukture pro odevzdani
# ta by mela asi vypadat takto? xborek12_xhrubo01_xjestr04_xkento00.zip/xborek12_xhrubo01_xjestr04_xkento00/doc, /install, /repo
pack:
	powershell.exe -Command "& { \
		Compress-Archive -Path '..\mockup', '..\plan', '..\profiling', '..\src', \
		'..\debugging.png', '..\dokumentace.pdf', '..\screenshot.png', '..\hodnoceni.txt', \
		'..\skutecnost.txt', '..\README.md', '..\.gitignore', '..\.editorconfig' \
		-DestinationPath '..\xborek12_xhrubo01_xjestr04_xkento00.zip' -Force \
	}"

# Vycistenie vsetkych nepotrebnych suborov
clean:
	powershell.exe -Command "& { \
		Remove-Item -Path '..\build' -Recurse -Force -ErrorAction SilentlyContinue ; \
		Remove-Item -Path '..\$(OBJDIR)\*.o' -Force -ErrorAction SilentlyContinue ; \
		Remove-Item -Path '..\$(TARGET).exe' -Force -ErrorAction SilentlyContinue \
	}"

# Vypise napovedu s popisem, co je potreba udelat pred supstenim programu
help:
	powershell.exe -Command "& { \
		Write-Output 'Pred spustenim programu je potreba:'; \
	}"
