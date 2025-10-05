#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <vector>
#include <cstdint>
#include <any>

using Entity = std::uint32_t;

class EntityManager {
public:
    std::vector<Entity> entities;
    Entity createEntity(){
        entities.emplace_back();
        return entities.back();
    }
    
    void destroyEntity(Entity e);

    template<typename Component, typename... Args>
    void addComponent(Entity e, Args&&... args) {
        components[typeid(Component)][e] = Component(std::forward<Args>(args)...);
    }

    template<typename Component>
    Component* getComponent(Entity e) {
        auto it = components[typeid(Component)].find(e);
        if (it != components[typeid(Component)].end()) {
            return std::any_cast<Component>(&it->second);
        }
        return nullptr;
    }

    template<typename Component>
    bool hasComponent(Entity e) {
        return components[typeid(Component)].count(e) > 0;
    }

    template<typename... Component>
    std::vector<Entity> getEntitiesWith() {
        std::vector<Entity> result;

        if constexpr (sizeof...(Component) == 0) {
            return result; // No components specified
        }
        
        using First = std::tuple_element_t<0, std::tuple<Component...>>;
        auto& baseMap = components[typeid(First)];
        for(auto& pair : baseMap) {
            Entity entity = pair.first;
            
            if((hasComponent<Component>(entity) && ...)) {
                result.push_back(entity);
            }
        }
        return result;
    }

private:
    Entity nextEntity = 0;
    std::unordered_map<std::type_index, std::unordered_map<Entity, std::any>> components;
};
