//
// Created by glosper on 12/1/2024.
//

#include "Koopa.h"
#include "Player.h"


void Koopa::dealDamage(Player& player) {
    float damage = 15;
    player.reduceHP(damage);
    std::cout << "Koopa dealt " << damage << " damage! Player's health: " << player.getHP() << "\n";
}