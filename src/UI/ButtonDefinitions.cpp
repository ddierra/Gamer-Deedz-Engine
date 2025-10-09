#include "ButtonDefinitions.hpp"

namespace ButtonDefinitions{
    
    Button SpawnRectangle(const sf::Font& font, const sf::String& label, std::function<void()> onClick){
        return Button(
            sf::Vector2f(120.f, 40.f),
            sf::Vector2f(10.f, 10.f),
            "Spawn Rectangle",
            font,
            onClick
            );
        }

    Button SpawnCircle(const sf::Font& font, const sf::String& label, std::function<void()> onClick){
        return Button(
            sf::Vector2f(120.f, 40.f),
            sf::Vector2f(10.f, 60.f),
            "Spawn Circle",
            font,
            onClick
            );
        }

    Button AddComponent(const sf::Font font, std::function<void()> onClick){
        return Button(
            sf::Vector2f(120.f, 40.f),
            sf::Vector2f(10.f, 110.f),
            "Add Component",
            font,
            onClick
            );
        }

    Button RemoveComponent(const sf::Font font, std::function<void()> onClick){
        return Button(
            sf::Vector2f(120.f, 40.f),
            sf::Vector2f(10.f, 160.f),
            "Remove Component",
            font,
            onClick
            );
        }

    Button DeleteEntity(const sf::Font font, std::function<void()> onClick){
        return Button(
            sf::Vector2f(120.f, 40.f),
            sf::Vector2f(10.f, 210.f),
            "Delete Entity",
            font,
            onClick
            );
        }

    Button AddSystem(const sf::Font font, std::function<void()> onClick){
        return Button(
            sf::Vector2f(120.f, 40.f),
            sf::Vector2f(10.f, 260.f),
            "Add System",
            font,
            onClick
            );
        }

    Button RemoveSystem(const sf::Font font, std::function<void()> onClick){
        return Button(
            sf::Vector2f(120.f, 40.f),
            sf::Vector2f(10.f, 310.f),
            "Remove System",
            font,
            onClick
            );
        }
    }