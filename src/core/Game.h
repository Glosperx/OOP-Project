#ifndef GAME_H
#define GAME_H

#include "pch.h"
#include "Enemy.h"
#include "Player.h"

class Game
{
private:
	void gwindow();
	std::vector<std::shared_ptr<Enemy>> enemies;
	sf::RenderWindow window;
	sf::Event event{};
	sf::Clock clock;
	std::string name;
	Player Mario;
	sf::Music soundtrack;


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
	float getScreenWidth() const;
	float getScreenHeight() const;

	friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif // GAME_H
