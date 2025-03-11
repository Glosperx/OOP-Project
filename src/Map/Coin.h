//
// Created by glosper on 3/3/2025.
//

#ifndef COIN_H
#define COIN_H

#include "Tile.h"

class Coin :public Tile{
    bool isSolid() const override;
    int getSymbol() const override;

};



#endif //COIN_H
