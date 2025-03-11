//
// Created by glosper on 3/3/2025.
//

#include "Ground.h"

Ground::Ground(const sf::Vector2f& position) {


    m_sprite.setPosition(position);
}

bool Ground::isSolid() const {
    return true;
}

int Ground::getSymbol() const {
    return 1;
}
