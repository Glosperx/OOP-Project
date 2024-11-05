//
// Created by glosper on 02/11/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
protected:
    sf::Vector2f velocity;
    sf::Sprite sprite;
    sf::FloatRect hitbox;
    float speed;

public:
    Entity();
    Entity(const sf::Texture& texture, const sf::Vector2f& position);
    Entity(const sf::Vector2f& initialPosition, float initialSpeed)
        : velocity(0.f, 0.f), speed(initialSpeed) {
        sprite.setPosition(initialPosition);
    }
    virtual ~Entity() = default;
    void setTexture(const sf::Texture &texture);
    virtual void update(const float& dt);
    void render(sf::RenderWindow& window) const;
    const sf::FloatRect& getHitbox() const;
    sf::Vector2f getVelocity() const;
    void setVelocity(const sf::Vector2f& vel);
    float getSpeed() const;
    void setSpeed(float _speed);
    virtual void move(const float &dt);
    virtual void update(float &dt) {
        hitbox = sprite.getGlobalBounds();
    }
    friend std::ostream& operator<<(std::ostream& os, const Entity& entity);
};

#endif //ENTITY_H
