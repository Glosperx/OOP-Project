//
// Created by glosper on 02/11/2024.
//

#include "Game.h"

void Game::gwindow() {

    window.create(sf::VideoMode(800, 600), "SuperMario");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

}

Game::Game()
{
    this->gwindow();
}
Game::~Game()
{

}

