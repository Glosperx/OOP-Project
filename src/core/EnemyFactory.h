#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "pch.h"
#include "Enemy.h"
#include "Goomba.h"
#include "Koopa.h"

class EnemyFactory {
public:
    static std::unique_ptr<Enemy> createEnemy(const std::string& enemyType, const sf::Vector2f& position);
};

#endif // ENEMYFACTORY_H
