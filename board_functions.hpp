#include <SFML/Graphics.hpp>
#include "palette.hpp"

std::vector<sf::RectangleShape> initialize_board(std::vector<sf::RectangleShape> cell,int scale, palette colors)
{
    int rate = scale * scale;

    for(int i = 0; i < rate; i++)
    {
        for(int b = 0; b < rate ;b++)
        {
            int cell_number = (i * rate) + b;
            cell[cell_number].setSize(sf::Vector2f(scale, scale));
            cell[cell_number].setPosition(sf::Vector2f(b*scale,i*scale));
            cell[cell_number].setFillColor(colors.background);
            cell[cell_number].setOutlineColor(colors.outline);
            cell[cell_number].setOutlineThickness(-0.5);
        }
    }
    return cell;
}
// if 0 then first opertaion... if more then it do other thing...

std::vector<bool> update_board(std::vector<bool> board, int scale)
{
    int rate = scale * scale;
    int amount = 0;

    bool new_board[rate*rate] = {0};

    for(int i = 0; i < rate; i++)
    {
        amount = 0;
        for(int b = 0; b < rate; b++)
        {
            amount = 0;
            int cell_number = (i * rate) + b;


            if(i != 0)
            {
                amount += (int) board[ ( (i - 1) * rate ) + b];
            }
            if(b != 0)
            {
                amount += (int) board[ ( i * rate ) + (b - 1)];
            }
            if(i != rate - 1)
            {
                amount += (int) board[ ( (i + 1) * rate ) + b];
            }
            if(b != rate - 1)
            {
                amount += (int) board[ ( i * rate ) + (b + 1)];
            }
            if(i != 0 && b != 0)
            {
                amount += (int) board[ ( (i - 1) * rate ) + (b - 1)];
            }
            if(i != rate - 1 && b != 0)
            {
                amount += (int) board[ ( (i + 1) * rate ) + (b - 1)];
            }
            if(i != rate - 1 && b != rate - 1)
            {
                amount += (int) board[ ( (i + 1) * rate ) + (b + 1)];
            }
            if(i != 0 && b != rate - 1)
            {
                amount += (int) board[ ( (i - 1) * rate ) + (b + 1)];
            }

                     
            if(amount == 3)
            {
                new_board[cell_number] = 1;
            }
                else if(amount > 3)
            {
                new_board[cell_number] = 0;
            }
            else if(amount == 2)
            {
                new_board[cell_number] = board[cell_number];
            }
            else
            {
                new_board[cell_number] = 0;
            }
        }
    }

    for(int i = 0; i < rate * rate; i++)
    {
        board[i] = new_board[i];
    }  
    return board;
}
//Matthew Curtner 11/28/2021