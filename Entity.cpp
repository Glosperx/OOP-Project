#include "Entity.h"

// Constructor

Entity::Entity(const sf::Texture& texture, const sf::Vector2f& position)
    : velocity(0.0f, 0.0f), speed(300.0f) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    hitbox = sprite.getGlobalBounds();
}

void Entity::move(const float &dt) {
    sprite.move(velocity * dt);
    hitbox = sprite.getGlobalBounds();
}

void Entity::update(float &dt) {
    hitbox = sprite.getGlobalBounds();
}
void Entity::setTexture(const sf::Texture &texture) {
    this->sprite.setTexture(texture);
}

void Entity::render(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

const sf::FloatRect& Entity::getHitbox() const {
    return hitbox;
}

void Entity::setVelocity(const sf::Vector2f& _velocity) {
    this->velocity = _velocity;
}

sf::Vector2f Entity::getVelocity() const {
    return this->velocity;
}

float Entity::getSpeed() const {
    return this->speed;
}

void Entity::setSpeed(float _speed) {
    this->speed = _speed;
}

std::ostream& operator<<(std::ostream& os, const Entity& entity)
{
    os<<"Entitatea exista: "<<std::endl;
    return os;
}
