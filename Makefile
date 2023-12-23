# Makefile for a C program using OpenMP

# Compiler
CC = gcc

# Compiler flags
# -Wall turns on most compiler warnings
# -fopenmp enables OpenMP
CFLAGS = -Wall -fopenmp

# The build target executable
TARGET = simple

# Source files
SRC = simple.c

# Object files
OBJ = $(SRC:.c=.o)

# Build target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# To create object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets
.PHONY: clean
