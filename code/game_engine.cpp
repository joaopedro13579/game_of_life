#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(
        sf::VideoMode(640, 480),
        "Hello World"); 
    sf::RectangleShape background(sf::Vector2(60.f,48.f));
    background.setFillColor(sf::Color(100, 250, 50));
    while (window.isOpen()) 
    {
        sf::RectangleShape background(sf::Vector2(60.f,48.f));
        background.setFillColor(sf::Color(100, 250, 50));
        window.draw(background);
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type ==
            sf::Event::Closed)
                window.close();
        window.clear();
        window.display();
    }
    return 0;
}