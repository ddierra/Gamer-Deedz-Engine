#pragma once
#include <vector>
#include "Entities/EntityManager.hpp"

class System{
public:
    virtual ~System() = default;

    virtual void update(EntityManager& em, float dt) = 0;

    std::vector<Entity> entities;
};