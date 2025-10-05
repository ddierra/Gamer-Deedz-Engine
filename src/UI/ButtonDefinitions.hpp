#pragma once
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <functional>

namespace ButtonDefinitions{
    Button SpawnRectangle(const sf::Font& font, const sf::String& label, std::function<void()> onClick);
    Button SpawnCircle(const sf::Font font, std::function<void()> onClick);
    Button AddComponent(const sf::Font font, std::function<void()> onClick);
    Button RemoveComponent(const sf::Font font, std::function<void()> onClick);
    Button DeleteEntity(const sf::Font font, std::function<void()> onClick);
    Button AddSystem(const sf::Font font, std::function<void()> onClick);
    Button RemoveSystem(const sf::Font font, std::function<void()> onClick);
}