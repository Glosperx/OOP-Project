//
// Created by glosper on 2/22/2025.
//

#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include "pch.h"
#include "Enemy.h"
#include "Player.h"

#include "Ground.h"
#include "Coin.h"
#include "Block.h"
#include "LuckyBlock.h"


class Map {
    std::vector<std::vector<Tile>> map;
    // std::vector<std::shared_ptr<Enemy>>& enemies;
    int width;
    int height;
    float tileSize;

    public:



    Map(int width, int height);
    void initialize();

    int getWidth() const;
    int getHeight() const;

    void render(sf::RenderTarget &target);

    ~Map() = default;
};



#endif //MAP_H
