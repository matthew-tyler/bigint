# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17
DEBUGFLAGS = -g
SRCDIR = src
BINDIR = bin
OBJDIR = obj
OUTPUTNAME = rational_thinking
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all 

# Find all source files in the src directory
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Generate object file names from the source files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
# Set the name of the output binary
TARGET = $(BINDIR)/$(OUTPUTNAME)

# Default target
all: $(TARGET)

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into the final binary
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Create the necessary directories
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Clean up generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Run the program after making it
run: all
	$(TARGET)

# Run the program after making it
test: all
	$(TARGET) test

# Debug target
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: all

# Valgrind target
valgrind: all
	valgrind $(VALGRIND_FLAGS) $(TARGET)

.PHONY: all clean debug valgrind
