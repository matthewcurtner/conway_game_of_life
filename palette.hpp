#include <SFML/Graphics.hpp>

struct palette
{
    sf::Color foreground = sf::Color::White;
    sf::Color background = sf::Color::Black;
    sf::Color outline = sf::Color::Black;
    sf::Color selector = sf::Color::Yellow;
    
    void set_defaults()
    {
        foreground = sf::Color::White;
        background = sf::Color::Black;
        outline = sf::Color::Black;
        selector = sf::Color::Yellow;
    }
    void set_colors(sf::Color Foreground, sf::Color Background, sf::Color Outline, sf::Color Selector)
    {
        foreground = Foreground;
        background = Background;
        outline = Outline;
        selector = Selector;
    }
};