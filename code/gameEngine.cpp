#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cell.hpp"
#include "grid.hpp"

class Board
{
private:
    std::vector<sf::RectangleShape> rectangles;

public:
    double board[240][130];
    int neighbours(int *coordinates)
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

    }
    Board(std::vector<Cell> cells)
    {
        for (int i = 0; i < cells.size(); i++)
        {
            board[cells[i].getCoord()[0]][cells[i].getCoord()[1]] = 1;
        }
    }
    void gameCycle()
    {
        double current[240][130];
        for (int i = 0; i < 240; i++)
        {
            for (int j = 0; j < 130; j++)
            {
               current[i][j]= board[i][j];
            }
        }
        int coordinates[2];
        for (int i = 0; i < 240; i++)
        {
            for (int j = 0; j < 130; j++)
            {
                coordinates[0] = i;
                coordinates[1] = j;
                if ((neighbours(coordinates) == 2&&current[i][j]==1)||neighbours(coordinates) == 3)
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
    }
    void draw(sf::RenderWindow &win)
    {
        for (int i = 0; i < rectangles.size(); i++)
        {
            win.draw(rectangles[i]);
        }
        rectangles.clear();
    }
};

int main()
{
    // Create a window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::Vector2f desktopSize;
    sf::RenderWindow window(sf::VideoMode(desktopMode.width, desktopMode.height), "SFML Grid");
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