#pragma once
#include "Systems/Systems.hpp"
#include "Components/Position.hpp"
#include "Components/Velocity.hpp"

class MovementSystem: public System{
public:
    void update(EntityManager& em, float dt) override{
        for (Entity e:  entities){
            auto pos = em.getComponent<Position>(e);
            auto vel = em.getComponent<Velocity>(e);
            if(pos && vel){
                pos->x += vel->vx * dt;
                pos->y =+ vel->vy * dt;
            }
        }
    }
};