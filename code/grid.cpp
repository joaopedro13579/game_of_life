#include"grid.hpp"
#include <SFML/Graphics.hpp>
#include<iostream>

Grid::Grid(unsigned int width, unsigned int height, unsigned int gridSize) : m_width(width), m_height(height), m_gridSize(gridSize)
{
    // Initialize the grid
    initialize();
}

void Grid::draw(sf::RenderWindow &window)
{
    // Draw the grid lines
    for (const auto &line : m_lines)
    {
        window.draw(line);
    }
}
void Grid::initialize()
{
    // Create horizontal lines
    for (unsigned int i = 0; i <= m_height; ++i)
    {
        sf::RectangleShape line(sf::Vector2f(m_width, 1));
        line.setPosition(0, i * m_gridSize);
        line.setFillColor(sf::Color(145, 145, 145));
        m_lines.push_back(line);
    }
    sf::RectangleShape line(sf::Vector2f(m_width, 1));
    line.setPosition(0, m_height - 1);
    m_lines.push_back(line);
    sf::RectangleShape liney(sf::Vector2f(1, m_height * m_gridSize));
    liney.setPosition(m_width - 1, 0);
    liney.setFillColor(sf::Color(145, 145, 145));
    m_lines.push_back(liney);
    // Create vertical lines
    for (unsigned int i = 0; i <= m_width; ++i)
    {
        sf::RectangleShape line(sf::Vector2f(1, m_height * m_gridSize));
        line.setPosition(i * m_gridSize, 0);
        line.setFillColor(sf::Color(145, 145, 145));
        m_lines.push_back(line);
    }
    numberOfCellsH=m_width/m_gridSize;
    numberOfCellV=m_height/m_gridSize;
    std::cout<<numberOfCellsH<<"||"<<numberOfCellV<<std::endl;
}