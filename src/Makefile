CC = g++
CFLAGS = -Wall -Werror -O2

# Najdenie suboru obsahujuceho Makefile
MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))

# Ulozenie cesty k suboru
SRCDIR := $(patsubst %/Makefile,%,$(MAKEFILE_PATH))
OBJDIR := $(SRCDIR)/objects

# Spracovanie vsetkych .cpp suborov
SOURCES := $(wildcard *.cpp) $(wildcard **/*.cpp)
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

# Vycistenie vsetkych nepotrebnych suborov
.PHONY: clean
clean:
	del $(TARGET).exe $(subst /,\, $(OBJDIR))\*.o