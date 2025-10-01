#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>

struct Button {
    sf::RectangleShape shape;
    sf::Text text;
    std::function<void()> onClick;

    Button(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& label, const sf::Font& font, std::function<void()> callback)
        : onClick(callback) {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(sf::Color(100, 100, 100));

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::White);
        // Center the text within the button
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
    }
};

class button {
public:
    void render(sf::RenderWindow& window);
    void addButton(const Button& button);
    void handleInput(sf::RenderWindow& window);
private:
    std::vector<Button> buttons;
};