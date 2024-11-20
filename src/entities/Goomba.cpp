//
// Created by glosper on 14/11/2024.
//

#include "Goomba.h"
#include "Game.h"
#include "Enemy.h"

Goomba::Goomba(const sf::Texture& texture, const sf::Vector2f& position)
    : Enemy(texture,position){

    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(1.0f, 1.0f);

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setFillColor(sf::Color::Transparent);
    hitboxShape.setOutlineColor(sf::Color::Blue);
    hitboxShape.setOutlineThickness(2);
    hitboxShape.setPosition(sprite.getPosition());
}

void Goomba::dealDamage(Player& player)
{
    player.reduceHP(10);
    std::cout<<"Player s health"<<player.getHP()<<"\n";
}
void Goomba::update(float dt) {

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setPosition(sprite.getPosition());
}

void Goomba::render(sf::RenderWindow& window)
{

    window.draw(sprite);
    window.draw(hitboxShape);
}

