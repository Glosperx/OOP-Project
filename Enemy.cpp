//
// Created by glosper on 02/11/2024.
//

#include "Enemy.h"



void Enemy::update(float dt) {
    Entity::update(dt);
}

std::ostream& operator<<(std::ostream& os, const Enemy& enemy) {
    os << "Enemy: Health = " << enemy.health << ", Damage = " << enemy.damage;
    return os;
}