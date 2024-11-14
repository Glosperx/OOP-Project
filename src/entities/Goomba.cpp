//
// Created by glosper on 14/11/2024.
//

#include "Goomba.h"

Goomba::Goomba(const sf::Texture& texture, const sf::Vector2f& position)
{
    sprite.setScale(0.5f, 0.5f);
}

void Goomba::dealDamage(Player& player)
{
    player.reduceHP(10);
    std::cout<<"Player s health"<<player.getHP()<<"\n";
}

