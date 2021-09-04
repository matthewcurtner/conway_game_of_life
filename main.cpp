#include "functions.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
//would recommend testing this on openbox, or a wm that floats by default :P
int main()
{
    bool start = 0;
    int scale = 10;
    int rate = scale * scale;
    int window_scale = scale * rate;
    bool board[rate * rate] = {0}; 

    std::cout << board[5] << "\n";
    sf::RenderWindow window(sf::VideoMode(window_scale, window_scale), "CONWAY", sf::Style::Close);
    sf::RectangleShape selector;
    selector.setSize(sf::Vector2f(scale, scale));
    std::vector<sf::RectangleShape> cell(rate * rate);

    //framerate limit@
    window.setFramerateLimit(60);

    selector.setFillColor(sf::Color::Yellow);

    cell = initialize_board(cell, scale);
    while(window.isOpen())
    {
        window.clear();
        sf::Event keyboard;
        while(window.pollEvent(keyboard))
        {
            
            if(keyboard.type == sf::Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                {
                    selector.move(0,-1 * scale);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                {
                    selector.move(0, scale); 
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                {
                    selector.move(-1 * scale, 0);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                {
                    selector.move(scale, 0);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
                {
                    if(cell[at_position(cell, scale, selector.getPosition())].getFillColor() == sf::Color::Black)
                    {
                        cell[at_position(cell, scale, selector.getPosition())].setFillColor(sf::Color::White);
                    }
                    else
                    {
                        cell[at_position(cell, scale, selector.getPosition())].setFillColor(sf::Color::Black);
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    start = !start;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                {
                    cell = initialize_board(cell, scale);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    window.close();
                }
            }
            break;
        }

        for(int i = 0; i < rate; i++)
        {
            for(int b = 0; b < rate; b++)
            {
                int cell_number = (i * rate) + b;
                if(cell[cell_number].getFillColor() == sf::Color::White)
                {
                    board[cell_number] = 1;
                }
                else
                {
                    board[cell_number] = 0;
                }
            }
        }

        //updating board

        if(start)
        {
            bool new_board[rate * rate] = {0};
            int amount = 0;
    
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

                    
                    if(amount == 3) //value should be 3
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
        }

        //array to vector...
        for(int i = 0; i < rate; i++)
        {
            for(int b = 0; b < rate; b++)
            {
                int cell_number = (i * rate) + b;
                if(board[cell_number] == 1)
                {
                    cell[cell_number].setFillColor(sf::Color::White);
                }
                else
                {
                    cell[cell_number].setFillColor(sf::Color::Black);
                }
            }
        }

        for(int i = 0; i < rate; i++)
        {
            for(int b = 0; b < rate; b++)
            {
                int cell_number = (i * rate) + b;
                window.draw(cell[cell_number]);
            }
        }
        
        window.draw(selector);
        window.display();
        
    }

    // this if for debugging the board array...
    /*for(int i = 0; i < rate; i++)
    {   
        std::cout << '\n';
        for(int b = 0; b < rate; b++)
        {
            std::cout << ' ' << board[(i * rate) + b ];
        }        
    }*/
}
