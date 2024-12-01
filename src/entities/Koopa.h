#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class Koopa : public Enemy {
public:
    Koopa() = default;
    explicit Koopa(const sf::Vector2f& position);
    static void loadTexture();
    Koopa(const sf::Texture& texture, const sf::Vector2f& position);

    // void dealDamage(Player& player) override;
    // void takeDamage() override;
    // void update(float& dt, Player& player) override;

    // virtual Koopa* clone() const override;
    // void handleCollision(Player& player) override;
    // void render(sf::RenderWindow& window) override;

private:
    float hp = 20;  // Adjust HP if needed
    sf::Sprite sprite;
    static sf::Texture koopaTexture;
};
