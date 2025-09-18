 #pragma once
 #include "MovementSystem.hpp"
 #include "Components/Position.hpp"
 #include "Components/Velocity.hpp"
 
 void MovementSystem::update(Entitymanager& em, float dt){
    for (Entity e:  entities){
        auto pos = em.getComponent<Position>(e);
        auto vel = em.getComponent<Velocity>(e);
        if(pos && vel){
            pos->x += vel->vx * dt;
            pos->y =+ vel->vy * dt;
        }
    }
}