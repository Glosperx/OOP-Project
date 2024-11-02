//
// Created by glosper on 02/11/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


class Player:public Entity
{
public:
    Player(const sf::Texture& texture, const sf::Vector2f& position): Entity(texture, position) {};
    ~Player() override = default;
private:
    void update(float &dt) override {
        this->setVelocity({0.f, 0.f});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            this->setVelocity(this->getVelocity() + sf::Vector2f(this->getSpeed(), 0.f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            this->setVelocity(this->getVelocity() - sf::Vector2f(this->getSpeed(), 0.f));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            this->setVelocity(this->getVelocity() - sf::Vector2f(0.f, this->getSpeed()));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            this->setVelocity(this->getVelocity() + sf::Vector2f(0.f, this->getSpeed()));

        move(dt);
    }
};


#endif //PLAYER_H
