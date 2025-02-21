//
// Created by glosper on 2/22/2025.
//

#ifndef TILE_H
#define TILE_H
#include "pch.h"
#include "ResourceManager.h"
const unsigned int TILE_SIZE = 40;

class Tile {

public:
    enum TileType {
        Ground,
        Pipe,
        Empty,
        Wall,
        Cloud,
        EndSign,
        Bush,
        LuckyBlock
    };

    const static sf::Color WALL_COLOR;

    /// Constructor
    Tile(TileType type_, float pos_x = 0, float pos_y = 0);

    /// Functions
    sf::FloatRect getGlobalBounds() const;
    TileType getType() const;
    static unsigned int getTileNum();
    static void setTileNum(unsigned int tileNum);
    void setPosition(float x, float y);
    void render(sf::RenderTarget& target);

private:
    sf::Sprite sprite;
    TileType type;
    static unsigned int tileNum;
    static const std::map<TileType, sf::Texture*> textureMap;
};



#endif //TILE_H
