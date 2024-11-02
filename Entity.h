//
// Created by glosper on 02/11/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
private:
    sf::Vector2f velocity;
    sf::Sprite sprite;
    sf::FloatRect hitbox;
    float speed;

public:
    Entity();
    Entity(const sf::Texture& texture, const sf::Vector2f& position);
    virtual ~Entity() = default;


    virtual void update(const float& dt);
    void render(sf::RenderWindow& window);
    const sf::FloatRect& getHitbox() const
    {
        return hitbox;
    }

    sf::Vector2f getVelocity() const {
        return this->velocity;
    }

    void setVelocity(const sf::Vector2f& vel) {
        this->velocity = vel;
    }

    float getSpeed() const {
        return this->speed;
    }

    void setSpeed(float spd) {
        this->speed = spd;
    }

    virtual void move(const float &dt);

    virtual void update(float &dt) {
        hitbox = sprite.getGlobalBounds();
    }
};

#endif //ENTITY_H
