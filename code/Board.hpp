#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cell.hpp"
class Board
{
private:
    std::vector<sf::RectangleShape> rectangles;

public:
    double board[240][130];
    int neighbours(int *coordinates);
    Board(std::vector<Cell> cells);
    void gameCycle();
    void draw(sf::RenderWindow &win);
    void setLive(int x,int y);
};