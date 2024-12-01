//
// Created by glosper on 12/1/2024.
//

#ifndef KOPPA_H
#define KOPPA_H
#include <Enemy.h>


class Koopa :public Enemy{
public:
    void dealDamage(Player& player) override;
};



#endif //KOPPA_H
