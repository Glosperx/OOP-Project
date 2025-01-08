#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "Observer.h"
#include "pch.h"
#include "ResourceManager.h"

class SoundManager : public Observer {
public:
    SoundManager();
    ~SoundManager() override = default;

    void onNotify(const std::string& event) override;
    void playBackgroundMusic();
    void stopBackgroundMusic();
    void pauseBackgroundMusic();

private:
    sf::SoundBuffer soundBuffer;
    sf::Sound soundPlayer;
    sf::Music backgroundMusic;
};

#endif // SOUNDMANAGER_H
