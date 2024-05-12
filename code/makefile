game:
	g++ -c gameEngine.cpp grid.cpp cellClass.cpp
	g++ gameEngine.o grid.o cellClass.o -o game -lsfml-graphics -lsfml-window -lsfml-system
	./game
	make clean
	clear
clean:
	rm -f game
	rm -f gameEngine.o
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