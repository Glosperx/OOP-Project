#include "pch.h"
#include "Game.h"
#include "Goomba.h"
#include "Enemy.h"
#include "Koopa.h"
#include "Player.h"
#include "Button.h"
#include "Exceptions.h"
#include "Menu.h"

float Game::getScreenWidth() const
{
	return screenWidth;
}

float Game::getScreenHeight() const
{
	return screenHeight;
}

void Game::gwindow()
{
	//fullscreen
	// sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
	sf::VideoMode resolution = sf::VideoMode(screenWidth, screenHeight, 32);
	window.create(resolution, name);
	window.setFramerateLimit(120);
	window.setVerticalSyncEnabled(true);
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	if (!backgroundTexture.loadFromFile("src/assets/backround/sky2.png"))
	{
		throw backroundLoadError("src/assets/backround/sky2.png");
	}
	backgroundSprite.setTexture(backgroundTexture);


	if (!soundtrack.openFromFile("src/assets/audio/supermario_soundtrack.wav"))
	{
		throw soundtrackLoadError("src/assets/audio/supermario_soundtrack.wav");
	}

	Goomba::loadTexture();
	Koopa::loadTexture();

	for (int i = 0; i < 3; ++i)
	{
		enemies.push_back(std::make_shared<Goomba>(sf::Vector2f(500.0f + i * 400.0f, 300.0f)));
		enemies.push_back(std::make_shared<Koopa>(sf::Vector2f(800.0f + i * 400.0f, 800.0f)));
	}

	// enemies.push_back(std::make_shared<Goomba>(sf::Vector2f(500.0f, 300.0f)));
	// enemies.push_back(std::make_shared<Goomba>(sf::Vector2f(800.0f, 300.0f)));

	Menu menu(screenWidth, screenHeight);
	bool isPlaying = false;
	sf::Clock clock;
	menu.startBackgroundMusic();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float dt = clock.restart().asSeconds();

		// // playButton.update(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		// menu.startBackgroundMusic();
		menu.handleInput(window, isPlaying);
		if (isPlaying)
		{
			menu.stopBackgroundMusic();
			if (soundtrack.getStatus() != sf::Music::Playing)
			{
				soundtrack.play();
				soundtrack.setLoop(true);
			}
			// if (soundtrack.getStatus() == sf::Music::Playing)
			// {
			// 	std::cout << "Music is already playing" << std::endl;
			// }
			// else if (soundtrack.getStatus() == sf::Music::Stopped)
			// {
			// 	std::cout << "Music is stopped" << std::endl;
			// }
			// else if (soundtrack.getStatus() == sf::Music::Paused)
			// {
			// 	std::cout << "Music is paused" << std::endl;
			// }

			// window.clear(sf::Color::White);
			window.clear();
			window.draw(backgroundSprite);


			Mario.update(dt, screenWidth, screenHeight, enemies);
			for (auto& enemy : enemies)
			{
				enemy->handleCollision(Mario);
			}


			for (auto& enemy : enemies)
			{
				enemy->update(dt);
				enemy->render(window);
			}

			if (Mario.getIsDead())
			{
				soundtrack.stop();
				Mario.setupGameOverText(window);
				window.draw(Mario.getGameOverText());
			}

			// playButton.render(window);
			// window.clear();
			Mario.render(window);
			window.display();
		}
		else
		{
			window.clear();

			menu.update(window);
			menu.render(window);

			window.display();
		}
	}
}


Game::Game(std::string name) : name(name), Mario({50.0f, 50.0f})
{
	gwindow();
}


Game::~Game()
{
}
