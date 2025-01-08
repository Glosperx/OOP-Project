#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "pch.h"

class ResourceManager {
public:
	static sf::Texture playertexture;
	static sf::Texture luckyBlockTexture;
	static sf::Sprite backgroundSprite;
	static sf::Texture backgroundTexture;
	static sf::SoundBuffer collision_castraveti;
	static sf::SoundBuffer collision_am_spus_castraveti;
	static sf::Font gameOverFont;
	static sf::Music themeSong;
	static sf::Texture goombaTexture;
	static sf::Texture koopaTexture;

	static void loadResources();
};

#endif // RESOURCEMANAGER_H
