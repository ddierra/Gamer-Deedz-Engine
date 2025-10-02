#include "SideBar.hpp"

void SideBar::initialize(float width, float height, float posX, float posY, const sf::Color& bgColor) {
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(bgColor);
    background.setPosition(posX, posY);
}

void SideBar::render(sf::RenderWindow& window) {
    window.draw(background);
    for (const auto& button : buttons) {
        window.draw(button.shape);
        window.draw(button.text);
    }
}

void SideBar::addButton(const Button& button) {
    buttons.push_back(button);

    // stack vertically
    float yOffset = 10.f + (buttons.size() - 1) * (button.shape.getSize().y + 10.f);
    buttons.back().shape.setPosition(background.getPosition().x + 10.f, background.getPosition().y + yOffset);
    buttons.back().text.setPosition(
        buttons.back().shape.getPosition().x + buttons.back().shape.getSize().x / 2.f,
        buttons.back().shape.getPosition().y + buttons.back().shape.getSize().y / 2.f
    );
}

void SideBar::handleInput(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        for (auto& button : buttons) {
            if (button.shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                if (button.onClick) {
                    button.onClick();
                }
            }
        }
    }
}
