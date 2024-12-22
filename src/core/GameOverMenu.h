//
// Created by glosper on 12/7/2024.
//

#ifndef GAMEOVERMENU_H
#define GAMEOVERMENU_H
#include "Button.h"

class GameOverMenu {
private:
	sf::RectangleShape background;
	sf::Text gameOverText;
	Button playAgainButton;
	Button exitButton;
	sf::Font font;

public:
	GameOverMenu(float width, float height);

	void setupGameOverText(float width, float height);
	void update(sf::RenderWindow& window);
	void loadResources(const std::string& fontPath);
	void handleInput(sf::RenderWindow& window, bool& restartGame, bool& exitGame);
	void render(sf::RenderWindow& window);
};


#endif //GAMEOVERMENU_H
