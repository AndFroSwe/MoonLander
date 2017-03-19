# Variables
CC = g++
CSTD = c++11
CFLAGS = -g
OPTIMIZE = -O3
ALLFLAGS = -std=$(CSTD) -Wall -pedantic $(OPTIMIZE) $(CFLAGS)
CPP_FILES := $(wildcard src/*.cpp)
LINKER_FLAGS = # Add your linker files here
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

# Compilation
build/main.exe: $(OBJ_FILES)
	$(CC) $(ALLFLAGS) -o $@ $^ $(LIBRARIES) $(INCLUDES) $(LINKER_FLAGS)
obj/%.o: src/%.cpp
	$(CC) $(ALLFLAGS) -c -o $@ $< $(LIBRARIES) $(INCLUDES) $(LINKER_FLAGS)

# Utilities
clean:
	rm -f obj/*.o build/*.out build/*.exe

.PHONY: clean
