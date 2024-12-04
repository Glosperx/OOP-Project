#include "ResourceManager.h"
#include "Exceptions.h"

sf::Texture ResourceManager::playertexture;
sf::SoundBuffer ResourceManager::collision_castraveti;
sf::SoundBuffer ResourceManager::collision_am_spus_castraveti;
sf::Font ResourceManager::gameOverFont;

void ResourceManager::loadResources()
{
	try {
		if (!playertexture.loadFromFile("src/assets/textures/amongus1.png"))
		{
			throw resourceLoadError("src/assets/textures/amongus1.png");
		}

		if (!collision_castraveti.loadFromFile("src/assets/audio/ultimul_castravete.wav"))
		{
			throw resourceLoadError("src/assets/audio/ultimul_castravete.wav");
		}

		if (!collision_am_spus_castraveti.loadFromFile("src/assets/audio/am_spus_castraveti.wav"))
		{
			throw resourceLoadError("src/assets/audio/am_spus_castraveti.wav");
		}

		if (!gameOverFont.loadFromFile("src/assets/font/TT-Rounds-Neue-Trial-Compressed-Medium-BF6438a17188007.ttf"))
		{
			throw fontLoadError("src/assets/font/TT-Rounds-Neue-Trial-Compressed-Medium-BF6438a17188007.ttf");
		}
	}
	catch (const gameError& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

