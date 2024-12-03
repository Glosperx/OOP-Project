#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height)
	: playButton(300, 200, 200, 50, "Play", font, sf::Color::Blue, sf::Color::Green, sf::Color::Red),
	  quitButton(300, 300, 200, 50, "Quit", font, sf::Color::Blue, sf::Color::Green, sf::Color::Red)
{
	background.setSize(sf::Vector2f(width, height));
	loadResources();
}

void Menu::loadResources()
{
	if (!backgroundTexture.loadFromFile("src/assets/textures/castle.png"))
	{
		throw menuBackroundLoadError("src/assets/textures/castle.png");
	}

	background.setTexture(&backgroundTexture);
	if (!backgroundMusic.openFromFile("src/assets/audio/theme_song.wav"))
	{
		throw musicLoadError("src/assets/audio/theme_song.wav");
	}

}
void Menu::startBackgroundMusic()
{

	backgroundMusic.setLoop(true);
	backgroundMusic.play();
}

void Menu::stopBackgroundMusic()
{
	backgroundMusic.stop();
}






void Menu::handleInput(sf::RenderWindow& window, bool& isPlaying)
{
	sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

	playButton.update(mousePos);
	quitButton.update(mousePos);

	if (playButton.isPressed(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
	{
		isPlaying = true;
	}
	else if (quitButton.isPressed(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
	{
		window.close();
	}
}

void Menu::update(sf::RenderWindow& window)
{
	sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	playButton.update(mousePos);
	quitButton.update(mousePos);
}

void Menu::render(sf::RenderWindow& window)
{
	window.draw(background);
	playButton.render(window);
	quitButton.render(window);
}
