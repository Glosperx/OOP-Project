//
// Created by glosper on 2/22/2025.
//

#ifndef TILE_H
#define TILE_H
#include "pch.h"
#include "ResourceManager.h"
// const unsigned int TILE_SIZE = 40;
const int TILE_SIZE = 32;

class Tile {

public:
    virtual bool isSolid() const =0;
    virtual int getSymbol() const =0;

    virtual sf::FloatRect getGlobalBounds() const;
    virtual void draw(sf::RenderWindow& window) const;
    virtual ~Tile() = default;

protected:
    sf::Sprite m_sprite;
};



#endif //TILE_H
