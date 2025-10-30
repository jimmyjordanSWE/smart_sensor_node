# Compiler and flags
CC = gcc
LIBS = -Isrc/libs  # add libraries for gcc here
LDFLAGS :=  # add libraries for linker here 
CFLAGS := -g -Wall -Wextra -std=gnu99 -MMD -MP $(LIBS)

# Source files - now includes both src/*.c and src/libs/*.c
SRC := $(wildcard src/*.c) $(wildcard src/libs/*.c)
OBJ := $(patsubst src/%.c, build/%.o, $(SRC))

# Output binary
OUT := build/server

# Default target
all: $(OUT)

# Link object files into executable
$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile each source file
build/%.o: src/%.c | build
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
build:
	mkdir -p build

# Run program
run: $(OUT)
	./$(OUT)

# Include dependency files
-include $(OBJ:.o=.d)

# Clean build artifacts
.PHONY: all clean run build
clean:
	rm -rf build