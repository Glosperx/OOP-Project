//
// Created by glosper on 3/3/2025.
//

#ifndef BLOCK_H
#define BLOCK_H


#include "Tile.h"

class Block : public Tile {
public:
    bool isSolid() const override;
    int getSymbol() const override;
};



#endif //BLOCK_H
