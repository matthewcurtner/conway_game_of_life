#include "board_functions.hpp"
#include "at_position.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
//#include "palette.hpp"

int main()
{
    bool start = 0;
    int scale = 10;
    int rate = scale * scale;
    int window_scale = scale * rate;
    
    std::vector<bool> board(rate * rate);
    std::vector<sf::RectangleShape> cell(rate * rate);

    std::cout << board[5] << "\n";
    sf::RenderWindow window(sf::VideoMode(window_scale, window_scale), "CONWAY", sf::Style::Close);
    sf::RectangleShape selector;
    selector.setSize(sf::Vector2f(scale, scale));
    
    //colors

    sf::Color foreground = sf::Color::White;
    sf::Color background = sf::Color::Black;
    sf::Color outline = sf::Color::Black;
    sf::Color selector_color = sf::Color::Yellow;


    palette colors;

    colors.set_colors(foreground, background, outline, selector_color);
    //colors.set_defaults();

    

    //framerate limit@
    window.setFramerateLimit(60);

    selector.setFillColor(colors.selector);

    cell = initialize_board(cell, scale, colors);
    while(window.isOpen())
    {
        window.clear();
        sf::Event keyboard;
        while(window.pollEvent(keyboard))
        {
            //give these keys some names that can be changed in config.
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
                    if(cell[at_position(cell, scale, selector.getPosition())].getFillColor() == colors.background)
                    {
                        cell[at_position(cell, scale, selector.getPosition())].setFillColor(colors.foreground);
                    }
                    else
                    {
                        cell[at_position(cell, scale, selector.getPosition())].setFillColor(colors.background);
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    start = !start;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                {
                    cell = initialize_board(cell, scale, colors);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    window.close();
                }
            }
            break;
        }

        //turn into a function called sync_board or something...
        for(int i = 0; i < rate; i++)
        {
            for(int b = 0; b < rate; b++)
            {
                int cell_number = (i * rate) + b;
                if(cell[cell_number].getFillColor() == colors.foreground)
                {
                    board[cell_number] = 1;
                }
                else
                {
                    board[cell_number] = 0;
                }
            }
        }

        
        //Updates the board when the start button is toggled
        if(start)
        {
            board = update_board(board, scale);
        }

        //array to vector...
        for(int i = 0; i < rate; i++)
        {
            for(int b = 0; b < rate; b++)
            {
                int cell_number = (i * rate) + b;


                if(board[cell_number] == 1)
                {
                    cell[cell_number].setFillColor(colors.foreground);
                }
                else
                {
                    cell[cell_number].setFillColor(colors.background);
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

}
//Matthew Curtner 11/28/2021