# Makefile for sfml-app

# Compiler
CC := g++

# Compiler flags for compilation
CFLAGS := -c

# Compiler flags for linking
LDFLAGS := -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRC := game_engine.cpp

# Object files
OBJ := $(SRC:.cpp=.o)

# Target
TARGET := sfml-app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
