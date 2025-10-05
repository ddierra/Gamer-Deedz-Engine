#include "UI/InputManager.hpp"
#include <SFML/Graphics.hpp>
#include "Entities/EntityManager.hpp"
#include <iostream>
#include "Components/Velocity.hpp"
#include "Components/Position.hpp"
#include "SystemBase/MovementSystem.hpp"
#include "Components/Transform.hpp"
#include "Components/UserInput.hpp"
#include "Engine.hpp"


int main() {
    Engine engine;
    engine.run();
    return 0;
}