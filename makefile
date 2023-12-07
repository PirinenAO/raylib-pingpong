# Compiler
CC = g++

# Directories
INCLUDE = ./include/
SRC = ./src/

# Compiler flags
CFLAGS = -c -I$(INCLUDE) -lraylib

# Source files
SOURCES := $(wildcard $(SRC)*.cpp)

# Object files
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))

# Executable name
EXECUTABLE = pingpong

# Build all rule
all: $(EXECUTABLE)

# Linking rule
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ -lraylib

# Compilation rule
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

# Clean rule
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
