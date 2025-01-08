#include "SoundManager.h"
#include "ResourceManager.h"
#include "pch.h"

SoundManager::SoundManager() {
    soundPlayer.setBuffer(sf::SoundBuffer());
}

void SoundManager::onNotify(const std::string &event) {
    if (event == "collision_even") {
        soundPlayer.setBuffer(ResourceManager::collision_am_spus_castraveti);
        if (soundPlayer.getStatus() != sf::Sound::Playing) {
            soundPlayer.play();
        }
    } else if (event == "collision_odd") {
        soundPlayer.setBuffer(ResourceManager::collision_castraveti);
        if (soundPlayer.getStatus() != sf::Sound::Playing) {
            soundPlayer.play();
        }
    } else if (event == "player_dead") {
        soundPlayer.setBuffer(ResourceManager::collision_am_spus_castraveti);
        soundPlayer.play();
        stopBackgroundMusic();
    } else if (event == "start_theme") {
        playBackgroundMusic();
    } else if (event == "stop_theme") {
        stopBackgroundMusic();
    } else {
        std::cerr << "Unknown sound event: " << event << std::endl;
    }
}


void SoundManager::playBackgroundMusic() {
    if (ResourceManager::themeSong.getStatus() != sf::Music::Playing) {
        ResourceManager::themeSong.play();
        ResourceManager::themeSong.setLoop(true);
    }
}

void SoundManager::stopBackgroundMusic() {
    if (ResourceManager::themeSong.getStatus() == sf::Music::Playing) {
        ResourceManager::themeSong.stop();
    }
}
