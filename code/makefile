game:
	g++ -c gameEngine.cpp grid.cpp cellClass.cpp Board.cpp
	g++ gameEngine.o grid.o cellClass.o Board.o -o game -lsfml-graphics -lsfml-window -lsfml-system
	./game
	make clean
	clear
clean:

	rm -f gameEngine.o
	rm -f grid.o
	rm -f cellClass.o
	rm -f Board.o
econsim:
	clear
	g++ econsim_base_classes.cpp tester.cpp -o econsim
	./econsim
	rm -f econsim
clear:
	clear
teste:
	g++ -c teste.cpp cellClass.cpp
	g++ teste.o cellClass.o -o teste -lsfml-graphics -lsfml-window -lsfml-system
	./teste
	rm -f teste
	rm -f teste.o