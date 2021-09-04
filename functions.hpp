#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
std::vector<sf::RectangleShape> initialize_board(std::vector<sf::RectangleShape> cell,int scale)
{
    int rate = scale * scale;

    for(int i = 0; i < rate; i++)
    {
        for(int b = 0; b < rate ;b++)
        {
            int cell_number = (i * rate) + b;
            cell[cell_number].setSize(sf::Vector2f(scale, scale));
            cell[cell_number].setPosition(sf::Vector2f(b*scale,i*scale));
            cell[cell_number].setFillColor(sf::Color::Black);
            cell[cell_number].setOutlineColor(sf::Color::Black);
            cell[cell_number].setOutlineThickness(-0.5);
        }
    }
    return cell;
}

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
    std::cout << "ERR: PTR not on valid cell\n";
    return -1;
}