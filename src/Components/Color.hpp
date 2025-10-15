#pragma once
#include <SFML/Graphics.hpp>

struct Color{
    sf::Color fillColor;

    Color(const sf::Color& color = sf::Color::White)
        : fillColor(color){}
};

class Color{
    public:
        sf::Color color;
};
