#include "Board.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int Board::neighbours(int *coordinates)
{
    int x = coordinates[0];
    int y = coordinates[1];
    int count = 0;
    if (x == 0 && y == 0)
    {
        count = board[x][y + 1] + board[x + 1][y] + board[x + 1][y + 1];
        return count;
    }
    else if (x == 241 && y == 0)
    {
        count = board[x][y + 1] + board[x - 1][y] + board[x - 1][y + 1];
        return count;
    }
    else if (x == 0 && y == 131)
    {
        count = board[x][y - 1] + board[x + 1][y] + board[x + 1][y - 1];
        return count;
    }
    else if (x == 0)
    {
        count = board[x][y + 1] + board[x][y - 1] + board[x + 1][y + 1] + board[x + 1][y - 1] + board[x + 1][y];
        return count;
    }
    else if (x == 241)
    {
        count = board[x][y + 1] + board[x][y - 1] + board[x - 1][y + 1] + board[x - 1][y - 1] + board[x - 1][y];
        return count;
    }
    else if (y == 0)
    {
        count = board[x + 1][y] + board[x - 1][y] + board[x + 1][y + 1] + board[x + 1][y + 1] + board[x - 1][y + 1];
        return count;
    }
    else if (y == 131)
    {
        count = board[x + 1][y] + board[x - 1][y] + board[x][y - 1] + board[x + 1][y - 1] + board[x - 1][y - 1];
        return count;
    }
    else
    {
        count = board[x][y + 1] + board[x][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x - 1][y - 1] + board[x + 1][y] + board[x + 1][y - 1] + board[x + 1][y + 1];
        return count;
    }
};
Board::Board(std::vector<Cell> cells)
{
    for (int i = 0; i < cells.size(); i++)
    {
        board[cells[i].getCoord()[0]][cells[i].getCoord()[1]] = 1;
    }
};
void Board::gameCycle()
{
    rectangles.clear();
    double current[240][130];
    for (int i = 0; i < 240; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            current[i][j] = board[i][j];
        }
    }
    int coordinates[2];
    for (int i = 0; i < 240; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            coordinates[0] = i;
            coordinates[1] = j;
            if ((neighbours(coordinates) == 2 && board[i][j] == 1) || neighbours(coordinates) == 3)
            {
                current[i][j] = 1;
                sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(5, 5));
                rectangle.setPosition((i * 8) + 2, (j * 8) + 2);
                rectangle.setFillColor(sf::Color(255, 255, 255));
                rectangles.push_back(rectangle);
            }
            else
            {
                current[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < 240; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            board[i][j] = current[i][j];
        }
    }
};
void Board::draw(sf::RenderWindow &win)
{
    for (int i = 0; i < rectangles.size(); i++)
    {
        win.draw(rectangles[i]);
    }
};
void Board::setLive(int x, int y)
{
    if (board[x][y] == 0)
    {
        board[x][y] = 1;
        sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(5, 5));
        rectangle.setPosition((x * 8) + 2, (y * 8) + 2);
        rectangle.setFillColor(sf::Color(255, 255, 255));
        rectangles.push_back(rectangle);
    }
    else
    {
        board[x][y] = 0;
    }
};