#ifndef ENEMY_CONTAINER_H
#define ENEMY_CONTAINER_H

#include "pch.h"
#include "Player.h"
#include "Enemy.h"

template <typename T>
class EnemyContainer {
public:
    void addEnemy(const std::shared_ptr<T>& enemy) {
        enemies.push_back(enemy);
    }

    std::shared_ptr<T> getEnemy(size_t index) const {
        if (index < enemies.size()) {
            return enemies[index];
        }
        return nullptr;
    }

    void removeEnemy(size_t index) {
        if (index < enemies.size()) {
            enemies.erase(enemies.begin() + index);
        }
    }

    size_t getEnemyCount() const {
        return enemies.size();
    }

    void updateEnemies(float dt, Player& player) {
        for (auto& enemy : enemies) {
            enemy->update(dt, player);
        }
    }

    void renderEnemies(sf::RenderWindow& window) const {
        for (const auto& enemy : enemies) {
            enemy->render(window);
        }
    }

private:
    std::vector<std::shared_ptr<T>> enemies;
};

#endif // ENEMY_CONTAINER_H
