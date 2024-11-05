//
// Created by glosper on 02/11/2024.
//

#include "Player.h"



Player::Player(const sf::Vector2f& position)
    : Entity(position, 500.0f)
{
    playertexture.loadFromFile("amongus1.png");


    sprite.setTexture(playertexture);
    sprite.setPosition(position);
    sprite.setScale(0.5f, 0.5f);
    hitbox = sprite.getGlobalBounds();
}
    sf::Vector2f Player::getPosition() const {
        return sprite.getPosition();
    }
void Player::update(float &dt) {

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

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << "Viteza: " << player.getVelocity().x << ", " << player.getVelocity().y << std::endl;
    return os;
}