#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Game {
private:
    void gwindow();
    std::vector<std::shared_ptr<Enemy>> enemies;
    sf::RenderWindow window;
    sf::Event event{};
    sf::Clock clock;
    std::string name;
    Player Mario;

    const float screenWidth = 1920.f;
    const float screenHeight = 1080.f;

public:
    Game();
    explicit Game(std::string name = "SuperMario");
    Game(const Game& other);
    Game& operator=(const Game& other);
    virtual ~Game();

    void update();
    void render();
    float getScreenWidth() const { return screenWidth; }
    float getScreenHeight() const { return screenHeight; }

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif // GAME_H
