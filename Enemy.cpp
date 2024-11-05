//
// Created by glosper on 02/11/2024.
//

#include "Enemy.h"

Enemy::Enemy(const sf::Texture& texture, const sf::Vector2f& position)
    : Entity(texture, position), hp(100), damage(10) {
}


Enemy::~Enemy() {}
void Enemy::update(float dt) {
    Entity::update(dt);
}

void Enemy::dealDamage(Player& player) {
    player.reduceHP(damage);
}

std::ostream& operator<<(std::ostream& os, const Enemy& enemy) {
    os << "Enemy: Health = " << enemy.hp << ", Damage = " << enemy.damage;
    return os;
}