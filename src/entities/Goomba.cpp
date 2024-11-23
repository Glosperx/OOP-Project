//
// Created by glosper on 14/11/2024.
//

#include "Goomba.h"
#include "Game.h"
#include "Enemy.h"

sf::Texture Goomba::goombaTexture;

void Goomba::loadTexture() {
    if (!goombaTexture.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/src/assets/textures/goomba1.png")) {
        throw std::runtime_error("Failed to load Goomba texture");
    }
}

Goomba::Goomba(const sf::Vector2f& position) : Enemy(goombaTexture, position),isDead(false) {
    sprite.setTexture(goombaTexture);
    sprite.setPosition(position);
    sprite.setScale(0.5f, 0.5f);

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setFillColor(sf::Color::Transparent);
    hitboxShape.setOutlineColor(sf::Color::Blue);
    hitboxShape.setOutlineThickness(2);
    hitboxShape.setPosition(sprite.getPosition());
}
bool Goomba::getIsDead() const {
    return isDead;
}

void Goomba::dealDamage(Player& player)
{
    player.reduceHP(10);
    std::cout<<"Player s health"<<player.getHP()<<"\n";
}
//
// void Goomba::takeDamage() {
//     reduceHP(10);
//     std::cout << "Goomba's health: " << getHP() << "\n";
// }
//


void Goomba::handleCollision(Player& player) {
        if (player.topCollision(*this)) {
            std::cout << "Player a sarit pe Goomba!\n";

            isDead = true;
            sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
            // hitboxShape.setOutlineThickness(100);

        } else if (player.bottomCollision(*this)) {
            std::cout << "Player a fost lovit de jos!\n";

            // player.reduceHP(10);
        } else if (player.leftCollision(*this)) {
            std::cout << "Player a fost lovit din stanga!\n";

            // player.reduceHP(10);
        } else if (player.rightCollision(*this)) {
            std::cout << "Player a fost lovit din dreapta!\n";

            // player.reduceHP(10);
        }
    }

void Goomba::update([[maybe_unused]] float &dt,Player& player) {

    if (isDead) {
        hitbox = sf::FloatRect(0, 0, 0, 0);
        hitboxShape.setSize(sf::Vector2f(0, 0));
        return;
    }

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setPosition(sprite.getPosition());

    handleCollision(player);
}



void Goomba::render(sf::RenderWindow& window)
{

    if (isDead) {
        return;
    }

    window.draw(sprite);
    window.draw(hitboxShape);
}

