//
// Created by glosper on 02/11/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"

class Enemy;

class Entity
{
protected:
    sf::Vector2f velocity;
    sf::Sprite sprite;
    sf::FloatRect hitbox;
    sf::RectangleShape hitboxShape;
    float speed;

public:
    Entity();
    Entity(const sf::Texture& texture, const sf::Vector2f& position);
    Entity(const sf::Vector2f& initialPosition, float initialSpeed)
        : velocity(0.f, 0.f), speed(initialSpeed) {
        sprite.setPosition(initialPosition);
    }
    virtual ~Entity() = default;
    // bool checkCollision(const Entity& other) const;
    void moveEntity(float dt, Entity& player, std::vector<std::shared_ptr<Enemy>>& enemies);

    void setTexture(const sf::Texture &texture);
    virtual void render(sf::RenderWindow& window) const;
    const sf::FloatRect& getHitbox() const;

    // bool isColliding(const Entity& other) const;
    static bool isColliding(const Entity& entity1, const Entity& entity2);
    bool topCollision(const Entity& other);
    void moveEntity(float dt);
    // virtual void takeDamage()=0;


    sf::Vector2f getVelocity() const;
    bool bottomCollision(const Entity& other);
    bool leftCollision(const Entity& other);
    bool rightCollision(const Entity& other);
    void setVelocity(const sf::Vector2f& vel);
    float getSpeed() const;
    void setSpeed(float _speed);

    virtual void move(const float &dt);
    virtual void update(float &dt);
    friend std::ostream& operator<<(std::ostream& os, const Entity& entity);
};

#endif //ENTITY_H
