#include "pch.h"
#include "Game.h"
#include "Goomba.h"

float Game::getScreenWidth() const
{
    return screenWidth;
}
float Game::getScreenHeight() const
{
    return screenHeight;
}

void Game::gwindow() {
    //fullscreen
    // sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
    sf::VideoMode resolution = sf::VideoMode(screenWidth, screenHeight, 32);
    window.create(resolution, name);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);


    // sf::Texture enemyTexture1;
    // sf::Texture enemyTexture2;
    // sf::Texture enemytexture3;
    //
    // enemyTexture1.loadFro
    // mFile("assets/textures/goomba1.png");
    // enemyTexture2.loadFromFile("assets/textures/amongus1.png");
    // enemytexture3.loadFromFile("assets/textures/amongus1.png");
    Goomba::loadTexture();
    for (int i = 0; i < 3; ++i) {

        enemies.push_back(std::make_shared<Goomba>(sf::Vector2f(500.0f + i * 400.0f, 300.0f)));
    }
    // enemies.push_back(std::make_shared<Goomba>(sf::Vector2f(500.0f, 300.0f)));
    // enemies.push_back(std::make_shared<Goomba>(sf::Vector2f(800.0f, 300.0f)));

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::cout << Mario;

        float dt = clock.restart().asSeconds();
        window.clear(sf::Color::White);

        // for (auto& enemy : enemies) {
        //     enemy->moveEntity(dt, Mario, enemies);
        // }

        // Game.cpp
        for (auto& enemy : enemies) {
                enemy->handleCollision(Mario);
                Mario.update(dt, screenWidth, screenHeight, *enemy);

        }

        for (auto& enemy : enemies) {
                enemy->update(dt);
                enemy->render(window);

        }

        // window.clear();
        Mario.render(window);

        window.display();
    }
}

Game::Game(std::string name) : name(name), Mario({50.0f, 50.0f}) {
    gwindow();
}
std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Numele jocului: " << game.name << std::endl;
    os << "Pozitia lui Mario: " << game.Mario.getPosition().x << ", " << game.Mario.getPosition().y << std::endl;
    return os;
}

Game::~Game() {
}