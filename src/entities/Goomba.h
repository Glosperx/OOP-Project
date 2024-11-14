//
// Created by glosper on 14/11/2024.
//

#ifndef GOOMBA_H
#define GOOMBA_H
#include "Enemy.h"
#include "Player.h"


class Goomba :public Enemy{
    public:
    Goomba()=default ;
    Goomba(const sf::Texture& texture, const sf::Vector2f& position);
    void dealDamage(Player& player) override;

private:
    sf::Sprite sprite;

};



#endif //GOOMBA_H
