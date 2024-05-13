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
    Board board(std::vector<Cell>{});
    bool pause=false;
    // Main loop
    while (window.isOpen())
    {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed){
                window.close();
            }else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition(window);
                board.setLive(position.x/8,position.y/8);
            }else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                pause=!pause;
            }
        }
        window.clear(sf::Color(85, 85, 85));
        grid.draw(window);
        board.draw(window);
        if (pause==false)
        {
            board.gameCycle();
        }else
        {
            sf::RectangleShape pause(sf::Vector2f(40,100));
            pause.setFillColor(sf::Color(255,255,255,128));
            pause.setPosition((desktopMode.width/2)-50, desktopMode.height/10);
            sf::RectangleShape pause2(sf::Vector2f(40,100));
            pause2.setFillColor(sf::Color(255,255,255,128));
            pause2.setPosition((desktopMode.width/2)+40, desktopMode.height/10);
            window.draw(pause);
            window.draw(pause2);
        }
        
        sf::sleep(sf::milliseconds(100));


        window.display();
    }

    return 0;
}
/*00 01 02
  10 11 12
  20 21 22*/