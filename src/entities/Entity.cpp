#include "Entity.h"
#include "Enemy.h"

Entity::Entity(const sf::Texture& texture, const sf::Vector2f& position)
    : velocity(0.0f, 0.0f), speed(300.0f) {
    sprite.setTexture(texture);
    sprite.setPosition(position);

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setPosition(sprite.getPosition());
}


void Entity::setSpeed(float _speed) {
    this->speed = _speed;
}

void Entity::move(const float &dt) {
    sprite.move(velocity * dt);
    hitbox = sprite.getGlobalBounds();
    hitboxShape.setPosition(sprite.getPosition());
}

void Entity::update(float &dt) {
    hitbox = sprite.getGlobalBounds();
    hitboxShape.setPosition(sprite.getPosition());
}

void Entity::setTexture(const sf::Texture &texture) {
    this->sprite.setTexture(texture);
}

void Entity::render(sf::RenderWindow& window) const {
    window.draw(sprite);
    window.draw(hitboxShape);
}

const sf::FloatRect& Entity::getHitbox() const {
    return hitbox;
}

bool Entity::isColliding(const Entity& entity1, const Entity& entity2) {
    const sf::FloatRect& rect1 = entity1.getHitbox();
    const sf::FloatRect& rect2 = entity2.getHitbox();

    return ((rect1.left < rect2.left + rect2.width) &&
            (rect1.left + rect1.width > rect2.left) &&
            (rect1.top < rect2.top + rect2.height) &&
            (rect1.top + rect1.height > rect2.top));
}

bool Entity::topCollision(const Entity& other) {
    const sf::FloatRect& rect1 = sprite.getGlobalBounds();
    const sf::FloatRect& rect2 = other.sprite.getGlobalBounds();

    return (rect1.top + rect1.height > rect2.top &&
            rect1.top < rect2.top &&
            rect1.left < rect2.left + rect2.width &&
            rect1.left + rect1.width > rect2.left);
}

bool Entity::bottomCollision(const Entity& other) {
    const sf::FloatRect& rect1 = sprite.getGlobalBounds();
    const sf::FloatRect& rect2 = other.sprite.getGlobalBounds();

    return (rect1.top < rect2.top + rect2.height &&
            rect1.top + rect1.height > rect2.top + rect2.height &&
            rect1.left < rect2.left + rect2.width &&
            rect1.left + rect1.width > rect2.left);
}

bool Entity::leftCollision(const Entity& other) {
    const sf::FloatRect& rect1 = sprite.getGlobalBounds();
    const sf::FloatRect& rect2 = other.sprite.getGlobalBounds();

    return (rect1.left + rect1.width > rect2.left &&
            rect1.left < rect2.left &&
            rect1.top < rect2.top + rect2.height &&
            rect1.top + rect1.height > rect2.top);
}

bool Entity::rightCollision(const Entity& other) {
    const sf::FloatRect& rect1 = sprite.getGlobalBounds();
    const sf::FloatRect& rect2 = other.sprite.getGlobalBounds();

    return (rect1.left < rect2.left + rect2.width &&
            rect1.left + rect1.width > rect2.left + rect2.width &&
            rect1.top < rect2.top + rect2.height &&
            rect1.top + rect1.height > rect2.top);
}


// void Entity::moveEntity(float dt, Entity& player, std::vector<std::shared_ptr<Enemy>>& enemies) {
//     sf::Vector2f currentPosition = sprite.getPosition();
//     sprite.setPosition(currentPosition);
//
//     bool playerCollided = false;
//
//     for (auto& enemyPtr : enemies) {
//         if (Entity::isColliding(player, *enemyPtr)) {
//
//             player.velocity = sf::Vector2f(0, 0);
//             player.hitboxShape.setOutlineThickness(50);
//             std::cout << "Player collided with enemy!" << std::endl;
//             playerCollided = true;
//         }
//     }
//
//     if (!playerCollided) {
//         player.hitboxShape.setOutlineThickness(2);
//     }
//
//     sprite.setPosition(currentPosition);
//     hitboxShape.setPosition(currentPosition);
// }





void Entity::setVelocity(const sf::Vector2f& _velocity) {
    this->velocity = _velocity;
}

sf::Vector2f Entity::getVelocity() const {
    return this->velocity;
}

float Entity::getSpeed() const {
    return this->speed;
}


std::ostream& operator<<(std::ostream& os, const Entity& entity) {
    os << "Entitatea exista: " << std::endl;
    return os;
}
