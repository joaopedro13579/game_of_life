#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "grid.hpp"
#include "Board.hpp"

int main()
{
    // Create a window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::Vector2f desktopSize;
    sf::RenderWindow window(sf::VideoMode(desktopMode.width, desktopMode.height), "Game Of Life");
    int coordinates1[2] = {10, 9};
    int coordinates2[2] = {10, 10};
    int coordinates3[2] = {10, 11};
    // Create a grid
    Grid grid(window.getSize().x, window.getSize().y, 8);
    Board board(std::vector<Cell>{Cell(1, coordinates1), Cell(1, coordinates2), Cell(1, coordinates3)});
    // Main loop
    while (window.isOpen())
    {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(85, 85, 85));
        grid.draw(window);
        board.draw(window);
        sf::sleep(sf::milliseconds(500));
        board.gameCycle();

        window.display();
    }

    return 0;
}
/*00 01 02
  10 11 12
  20 21 22*/