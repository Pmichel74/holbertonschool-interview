CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89

# Executable names
TARGET = heap_insert
EXAMPLES = exemples_commentes

# Source files
SOURCES = 0-binary_tree_node.c 1-heap_insert.c binary_tree_print.c 1-main.c
EXAMPLE_SOURCES = 0-binary_tree_node.c 1-heap_insert.c binary_tree_print.c exemples_commentes.c

# Object files
OBJECTS = $(SOURCES:.c=.o)
EXAMPLE_OBJECTS = $(EXAMPLE_SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Build the examples executable
examples: $(EXAMPLES)

$(EXAMPLES): $(EXAMPLE_OBJECTS)
	$(CC) $(CFLAGS) -o $(EXAMPLES) $(EXAMPLE_OBJECTS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	rm -f $(OBJECTS) $(EXAMPLE_OBJECTS) $(TARGET) $(EXAMPLES)

# Rebuild everything
re: clean all

# Test the main program
test: $(TARGET)
	./$(TARGET)

# Test with detailed examples
test-examples: $(EXAMPLES)
	./$(EXAMPLES)

# Check Betty coding style
betty: 
	./betty_check.sh

# Show help
help:
	@echo "Available targets:"
	@echo "  all          - Build the main executable (default)"
	@echo "  examples     - Build the detailed examples program"
	@echo "  clean        - Remove object files and executables"
	@echo "  re           - Clean and rebuild"
	@echo "  test         - Build and run the main program"
	@echo "  test-examples - Build and run the detailed examples"
	@echo "  betty        - Check Betty coding style"
	@echo "  help         - Show this help message"

.PHONY: all examples clean re test test-examples betty help
