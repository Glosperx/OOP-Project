//
// Created by glosper on 02/11/2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Player.h"


class Enemy:public Entity {
private:
    float hp=100;
    int damage;
public:
    Enemy()=default;
    Enemy(const sf::Texture& texture, const sf::Vector2f& position);
    Enemy(const Enemy& other);
    explicit Enemy(const sf::Texture& texture);
    Enemy& operator=(const Enemy& other);
    ~Enemy();

    virtual void handleCollision(Player& player) = 0;

    virtual void dealDamage(Player& player) ;
    void update(float &dt) override;
    virtual void render(sf::RenderWindow& window);
    friend std::ostream& operator<<(std::ostream& os, const Enemy& enemy);
};



#endif //ENEMY_H
