//
// Created by glosper on 02/11/2024.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

class Game {
private:
    void gwindow();

    sf::RenderWindow window;
    sf::Event event{};
    sf::Clock clock;
    std::string name;
    Player Mario;
    Enemy enemy1;

public:
    explicit Game(std::string name = "SuperMario");
    Game(const Game& other);
    Game &operator=(const Game &other);
    virtual ~Game();

    void update();
    void render();
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};
#endif //GAME_H
