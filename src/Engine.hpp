#pragma once
#include <SFML/Graphics.hpp>
#include "UI/InputManager.hpp"
#include "Entities/EntityManager.hpp"
#include "Components/Velocity.hpp"
#include "Components/Position.hpp"
#include "SystemBase/MovementSystem.hpp"
#include "Components/Transform.hpp"
#include "Components/UserInput.hpp"
#include <iostream>
#include "UI/SideBar.hpp"
#include "UI/Button.hpp"
#include "UI/ButtonDefinitions.hpp"

class Engine {
public:
    void run();
};
