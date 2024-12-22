//
// Created by glosper on 12/7/2024.
//

#include "GameOverMenu.h"
GameOverMenu::GameOverMenu(float width, float height)
	: playAgainButton(300, 300, 200, 50, "Play Again", font, sf::Color::Blue, sf::Color::Green, sf::Color::Red),
	  exitButton(300, 400, 200, 50, "Exit", font, sf::Color::Blue, sf::Color::Green, sf::Color::Red)
{
	background.setSize(sf::Vector2f(width, height));
	background.setFillColor(sf::Color(0, 0, 0, 150));

	loadResources("src/assets/font/TT-Rounds-Neue-Trial-Compressed-Medium-BF6438a17188007.ttf");
	setupGameOverText(width, height);
}
void GameOverMenu::loadResources(const std::string& fontPath){

	if (!font.loadFromFile("src/assets/font/TT-Rounds-Neue-Trial-Compressed-Medium-BF6438a17188007.ttf"))
	{
		throw buttonFontLoadError("Failed to load font");
	}
}
void GameOverMenu::setupGameOverText(float width, float height)
{

	gameOverText.setFont(font);
	gameOverText.setString("Game Over");
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setStyle(sf::Text::Bold);

	sf::FloatRect textBounds = gameOverText.getLocalBounds();
	gameOverText.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
	gameOverText.setPosition(width / 2.0f, height / 2.0f - 100);
}



void GameOverMenu::update(sf::RenderWindow& window)
{
	sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	playAgainButton.update(mousePos);
	exitButton.update(mousePos);
	if (playAgainButton.isPressed(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
	{
		window.close();
	}

	if (exitButton.isPressed(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
	{
		window.close();
	}
}



void GameOverMenu::render(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(gameOverText);
	playAgainButton.render(window);
	exitButton.render(window);
}
