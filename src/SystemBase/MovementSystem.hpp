#pragma once
#include "SystemBase/Systems.hpp"
#include "Entities/EntityManager.hpp"
#include "Components/Position.hpp"
#include "Components/Velocity.hpp"

class MovementSystem: public System{
public:
    void update(EntityManager& em, float dt) override;
};