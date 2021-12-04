#include <SFML/Graphics.hpp>

int at_position(std::vector<sf::RectangleShape> cell, int scale, sf::Vector2f position)
{
    int rate = scale * scale;

    for(int i = 0; i < rate; i++)
    {
        for(int b = 0; b < rate ;b++)
        {
            int cell_number = (i * rate) + b;
            if(cell[cell_number].getPosition() == position)
            {
                return cell_number;
            }
        }
    }
    return -1;
}