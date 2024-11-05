//
// Created by glosper on 02/11/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


class Player:public Entity
{
public:

    Player()=default ;
    Player(const sf::Vector2f& position);
    ~Player() override = default;
    void update(float &dt);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    sf::Vector2f getPosition() const;
    void reduceHP(float amount);
private:
    float hp=100;
    sf::Texture playertexture;

};


#endif //PLAYER_H
