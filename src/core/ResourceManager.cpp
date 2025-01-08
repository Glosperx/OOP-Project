#include "ResourceManager.h"
#include "Exceptions.h"

sf::Texture ResourceManager::playertexture;
sf::Texture ResourceManager::luckyBlockTexture;
sf::Texture ResourceManager::backgroundTexture;
sf::Sprite ResourceManager::backgroundSprite;
sf::SoundBuffer ResourceManager::collision_castraveti;
sf::SoundBuffer ResourceManager::collision_am_spus_castraveti;
sf::Font ResourceManager::gameOverFont;
sf::Music ResourceManager::themeSong;

sf::Texture ResourceManager::goombaTexture;
sf::Texture ResourceManager::koopaTexture;
void ResourceManager::loadResources()
{
    try {
        if (!playertexture.loadFromFile("src/assets/textures/amongus1.png"))
        {
            throw resourceLoadError("src/assets/textures/amongus1.png");
        }
        if (!luckyBlockTexture.loadFromFile("src/assets/textures/lucky_block.png")) {
            throw resourceLoadError("src/assets/textures/lucky_block.png");
        }
        if (!backgroundTexture.loadFromFile("src/assets/backround/sky2.png")) {
            throw resourceLoadError("src/assets/backround/sky2.png");
        }

        backgroundSprite.setTexture(backgroundTexture);

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

        if (!themeSong.openFromFile("src/assets/audio/supermario_soundtrack.wav"))
        {
            throw resourceLoadError("src/assets/audio/supermario_soundtrack.wav");
        }
        if (!goombaTexture.loadFromFile("src/assets/textures/goomba1.png"))
        {
            throw resourceLoadError("src/assets/textures/goomba1.png");
        }

        if (!koopaTexture.loadFromFile("src/assets/textures/koopa.png"))
        {
            throw resourceLoadError("src/assets/textures/koopa.png");
        }

    }
    catch (const gameError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
