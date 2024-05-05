# Makefile for sfml-app



# Source files
SRC := game_engine.cpp

# Object files
OBJ := $(SRC:.cpp=.o)

# Target
TARGET := sfml-app

all: game 

game: $(OBJ)
	g++ $(OBJ) -o game -lsfml-graphics -lsfml-window -lsfml-system
	./game
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -f $(OBJ) game
econsim:
	clear
	g++ econsim_base_classes.cpp tester.cpp -o econsim
	./econsim
	rm -f econsim
clear:
	clear