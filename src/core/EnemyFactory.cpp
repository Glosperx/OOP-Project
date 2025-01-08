#include "EnemyFactory.h"

std::unique_ptr<Enemy> EnemyFactory::createEnemy(const std::string& enemyType, const sf::Vector2f& position) {
    if (enemyType == "Goomba") {
        return std::make_unique<Goomba>(position);
    } else if (enemyType == "Koopa") {
        return std::make_unique<Koopa>(position);
    } else {
        return nullptr;
    }
}
