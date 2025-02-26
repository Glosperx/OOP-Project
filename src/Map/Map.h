// //
// // Created by glosper on 2/22/2025.
// //
//
// #ifndef MAP_H
// #define MAP_H
//
// #include "Tile.h"
// #include "pch.h"
// #include "Enemy.h"
// #include "Player.h"
//
//
// class Map {
//     std::vector<std::vector<Tile>> map;
//     // std::vector<std::shared_ptr<Enemy>>& enemies;
//     int width;
//     int height;
//     float tileSize;
//
//     public:
//     Map(int width, int height, float tileSize);
//     void initialize();
//
//     void update(std::vector<std::shared_ptr<Enemy>> &enemies, Player &player);
//     void setTile(int x, int y, Tile::TileType type);
//     Tile getTile(int x, int y) const;
//
//     int getWidth() const;
//     int getHeight() const;
//
//     void render(sf::RenderTarget &target);
// };
//
//
//
// #endif //MAP_H
