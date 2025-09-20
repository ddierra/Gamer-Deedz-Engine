#pragma once
#include <SFML/System/Vector2.hpp>

struct TransformComponent{
    sf::Vector2f position{0.f, 0.f};
    float rotation = 0.f; // in degrees
    sf::Vector2f scale{1.f, 1.f};
};