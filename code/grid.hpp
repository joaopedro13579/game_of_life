#include <SFML/Graphics.hpp>

class Grid {
public:
    Grid(unsigned int width, unsigned int height, unsigned int gridSize) ;
    void draw(sf::RenderWindow& window);
    double numberOfCellsH;
    double numberOfCellV;
private:
    unsigned int m_width;  
    unsigned int m_height;    
    unsigned int m_gridSize;  
    std::vector<sf::RectangleShape> m_lines; 
    void initialize();
};