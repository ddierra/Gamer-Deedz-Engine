#pragma once
#include "SystemBase/Systems.hpp"
#include "Entities/EntityManager.hpp"
#include "Components/Position.hpp"
#include "Components/Velocity.hpp"
#include "Components/UserInput.hpp"
#include "Components/Transform.hpp"

class MovementSystem: public System{
public:
    void update(EntityManager& em, float dt) override;
};