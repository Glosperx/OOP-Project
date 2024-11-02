//
// Created by glosper on 02/11/2024.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
private:
    void gwindow();

    sf::RenderWindow window;
    sf::Event event{};
    sf::Clock clock;

public:
    Game();
    Game(const Game& other);
    Game &operator=(const Game &other);
    virtual ~Game();

    void update();
    void render();
};
#endif //GAME_H
