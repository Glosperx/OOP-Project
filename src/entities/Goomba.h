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
    explicit Goomba(const sf::Vector2f& position);
    static void loadTexture();
    Goomba(const sf::Texture& texture, const sf::Vector2f& position);
    void dealDamage(Player& player) override;
    void takeDamage();
    void update(float &dt, Player& player);

    void handleCollision(Player& player) override;
    void render(sf::RenderWindow& window) override;
    bool getIsDead() const;

private:
    float hp=10;
    bool isDead;
    sf::Sprite sprite;
    static sf::Texture goombaTexture;
};





#endif //GOOMBA_H
