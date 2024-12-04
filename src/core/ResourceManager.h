#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "pch.h"
#include "Exceptions.h"

class ResourceManager
{
public:
	static sf::Texture playertexture;
	static sf::SoundBuffer collision_castraveti;
	static sf::SoundBuffer collision_am_spus_castraveti;
	static sf::Font gameOverFont;

	static void loadResources();
};

#endif // RESOURCEMANAGER_H
