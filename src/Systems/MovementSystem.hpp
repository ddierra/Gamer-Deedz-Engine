#pragma once
#include "Systems.hpp"

class MovementSystem: public System{
public:
    void update(EntityManager& em, float dt) override;
};