//
// Created by glosper on 02/11/2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"


class Enemy:public Entity {
private:
    float health;
    int damage;
public:
    Enemy()=default;
    Enemy(const sf::Texture& texture, const sf::Vector2f& position);
    Enemy(const Enemy& other);
    Enemy& operator=(const Enemy& other);
    ~Enemy();
    void update(float dt);
    friend std::ostream& operator<<(std::ostream& os, const Enemy& enemy);
};



#endif //ENEMY_H
