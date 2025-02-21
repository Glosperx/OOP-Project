//
// Created by glosper on 2/22/2025.
//

#include "Tile.h"

#include "LuckyBlock.h"
#include "ResourceManager.h"

unsigned int Tile::tileNum = 0;

const std::map<Tile::TileType, sf::Texture*> Tile::textureMap = {
    {LuckyBlock,&ResourceManager::luckyBlockTexture},
    {Empty, &ResourceManager::emptyTexture}
};

Tile::Tile(TileType type_, float pos_x, float pos_y) : type(type_) {
    tileNum++;

    // Set texture
    auto it = textureMap.find(type_);
    if (it != textureMap.end()) {
        this->sprite.setTexture(*it->second);
    } else {
        this->sprite.setTexture(ResourceManager::emptyTexture);
        std::cerr << "Warning: Texture for TileType " << type_ << " not found, using empty texture." << std::endl;
    }

    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

sf::FloatRect Tile::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

Tile::TileType Tile::getType() const {
    return type;
}

void Tile::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

unsigned int Tile::getTileNum() {
    return tileNum;
}

void Tile::setTileNum(unsigned int tileNum_) {
    Tile::tileNum = tileNum_;
}

void Tile::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}