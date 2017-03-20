# Variables
# Advanced settings
CC = g++
CSTD = c++11
CFLAGS = -g
OPTIMIZE = -O3
ALLFLAGS = -std=$(CSTD) -Wall -pedantic $(OPTIMIZE) $(CFLAGS)
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LINKER_FLAGS = -lSDL2 -lSDL2_image# Add your linker files here

# File name settings
EXE = moonlander.out # Executable file

# Special settings
# This enables the macro for printing debug messages. just set debug to empty to
# disable.
DEBUG = -D DEBUG_PRINT

# Compilation
build/$(EXE): $(OBJ_FILES)
	$(CC) $(ALLFLAGS) -o $@ $^ $(LIBRARIES) $(INCLUDES) $(LINKER_FLAGS) $(DEBUG)

obj/%.o: src/%.cpp src/%.h
	$(CC) $(ALLFLAGS) -c -o $@ $< $(LIBRARIES) $(INCLUDES) $(LINKER_FLAGS) $(DEBUG)

# Utilities
run:
	@./build/$(EXE)

clean:
	rm -f obj/*.o build/*.out build/*.exe


.PHONY: clean run debug
