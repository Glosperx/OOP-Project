//
// Created by glosper on 02/11/2024.
//

#include "Entity.h"

//Constructor
Entity::Entity() : velocity(0.0f, 0.0f), hitbox(),speed(200.0f) {

}
Entity::Entity(const sf::Texture& texture, const sf::Vector2f& position)
    : velocity(0.0f, 0.0f), speed(200.0f) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    hitbox = sprite.getGlobalBounds();
}
void Entity::move(const float &dt) {
    sprite.move(velocity * dt);
    hitbox = sprite.getGlobalBounds();
}
void Entity::update(const float &dt) {

}

void Entity::render(sf::RenderWindow& window) {
    window.draw(sprite);
}