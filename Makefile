# Makefile for Maze Problem Solver

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS = -lm

# Programs
PROGRAMS = maze_basic maze_optimized maze_advanced

# Default target
all: $(PROGRAMS)

# Basic version
maze_basic: MAZE\ Problem\ solver.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Optimized version
maze_optimized: maze_solver_optimized.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Advanced version with benchmarks
maze_advanced: maze_solver_advanced.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Run the optimized version
run: maze_optimized
	./maze_optimized

# Run the advanced version
run_advanced: maze_advanced
	./maze_advanced

# Clean build artifacts
clean:
	rm -f $(PROGRAMS) *.o

# Help
help:
	@echo "Available targets:"
	@echo "  make all          - Build all programs"
	@echo "  make maze_basic   - Build basic version"
	@echo "  make maze_optimized - Build optimized version"
	@echo "  make maze_advanced - Build advanced version with benchmarks"
	@echo "  make run          - Build and run optimized version"
	@echo "  make run_advanced - Build and run advanced version"
	@echo "  make clean        - Remove build artifacts"
	@echo "  make help         - Show this help message"

.PHONY: all run run_advanced clean help
