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
    void update(float dt, float screen_width, float screen_height);
    // virtual void update(float &dt) override;
    using Entity::update;
    void update(float& dt, float screenWidth, float screenHeight, const Entity& otherEntity);
    void render(sf::RenderWindow& window) const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    sf::Vector2f getPosition() const;
    const sf::FloatRect& getHitbox() const;
    void ScreenCollision(float screenWidth, float screenHeight);
    void moveCharacter(float dt);

    [[nodiscard]] float getHP() const;

    void reduceHP(float amount);
private:
    float hp=100;
    sf::Texture playertexture;
    int collisionCount=0;
     sf::SoundBuffer collision_castraveti;
     sf::Sound castraveti;
     sf::SoundBuffer collision_am_spus_castraveti;

};


#endif //PLAYER_H
