#include "Game.h"

void Game::gwindow() {
    //fullscreen
    // sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
    sf::VideoMode resolution = sf::VideoMode(1920, 1080);
    window.create(resolution, name);
    window.setFramerateLimit(120);
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
        Mario.update(dt);
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
    os << "Poziția lui Mario: " << game.Mario.getPosition().x << ", " << game.Mario.getPosition().y << std::endl;
    return os;
}

Game::~Game() {
}
