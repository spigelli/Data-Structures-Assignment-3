# Variables
CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -g
TARGET = main
SOURCES = main.cpp list.cpp node.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Target: clean
clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -rf $(TARGET).dSYM