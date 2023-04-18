# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17
SRCDIR = src
BINDIR = bin
OBJDIR = obj

# Find all source files in the src directory
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Generate object file names from the source files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
# Set the name of the output binary
TARGET = $(BINDIR)/my_program

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

.PHONY: all clean