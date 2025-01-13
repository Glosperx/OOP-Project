//
// Created by glosper on 12/3/2024.
//

#ifndef MENU_H
#define MENU_H
#include "Button.h"


class Menu
{
private:
	sf::RectangleShape background;
	sf::Texture backgroundTexture;
	Button playButton;
	Button quitButton;
	sf::Font font;
	sf::Music backgroundMusic;

public:
	Menu(float width, float height);
	void loadResources();
	void startBackgroundMusic();
	void stopBackgroundMusic();
	void handleInput(sf::RenderWindow& window, bool& isPlaying);
	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
};


#endif //MENU_H
