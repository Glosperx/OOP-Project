//
// Created by glosper on 02/11/2024.
//

#include "Enemy.h"


Entity::Entity() = default;


Enemy::Enemy(const sf::Texture& texture, const sf::Vector2f& position)
    : Entity(texture, position), hp(100), damage(10) {

    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(0.5f, 0.5f);

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setPosition(sprite.getPosition());

    hitboxShape.setFillColor(sf::Color::Transparent);
    hitboxShape.setOutlineColor(sf::Color::Blue);
    hitboxShape.setOutlineThickness(2);
}
Enemy::Enemy(const sf::Texture& texture) {
}




Enemy::~Enemy() {}
void Enemy::update(float &dt) {
    Entity::update(dt);
    hitbox = sprite.getGlobalBounds();
    hitboxShape.setPosition(sprite.getPosition());
}

void Enemy::render(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(hitboxShape);
}

void Enemy::dealDamage(Player& player) {
    player.reduceHP(damage);
}

std::ostream& operator<<(std::ostream& os, const Enemy& enemy) {
    os << "Enemy: Health = " << enemy.hp << ", Damage = " << enemy.damage;
    return os;
}