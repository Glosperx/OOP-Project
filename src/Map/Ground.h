//
// Created by glosper on 3/3/2025.
//

#ifndef GROUND_H
#define GROUND_H
#include "Tile.h"
#include "ResourceManager.h"

class Ground :public Tile{

public:
    Ground(const sf::Vector2f& position);
    bool isSolid() const override;
    int getSymbol() const override;

};



#endif //GROUND_H
