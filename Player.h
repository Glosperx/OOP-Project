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
    virtual ~Player() override = default;
    // virtual void update(float &dt) override;
    void update(float &dt,float screenWidth, float screenHeight);
    void render(sf::RenderWindow& window);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    sf::Vector2f getPosition() const;
    void ScreenCollision(float screenWidth, float screenHeight);
    void reduceHP(float amount);
private:
    float hp=100;
    sf::Texture playertexture;

};


#endif //PLAYER_H
