#include "Tile.h"

void Tile::draw(sf::RenderWindow& window) const {
    window.draw(m_sprite);
}

sf::FloatRect Tile::getGlobalBounds() const {
    return m_sprite.getGlobalBounds();
}