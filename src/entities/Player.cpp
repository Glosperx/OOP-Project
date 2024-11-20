#include "Player.h"

Player::Player(const sf::Vector2f& position)
    : Entity(position, 1500.0f)
{
    // playertexture.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/assets/textures/amongus1.png");
    playertexture.loadFromFile("assets/textures/amongus1.png");
    //playertexture.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/src/assets/textures/amongus1.png");


    sprite.setTexture(playertexture);
    sprite.setPosition(position);
    sprite.setScale(0.5f, 0.5f);

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setFillColor(sf::Color::Transparent);
    hitboxShape.setOutlineColor(sf::Color::Red);
    hitboxShape.setOutlineThickness(2);
    hitboxShape.setPosition(sprite.getPosition());
}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}
const sf::FloatRect& Player::getHitbox() const {
    return hitbox;
}

void Player::ScreenCollision(float screenWidth, float screenHeight) {
    sf::Vector2f pos = sprite.getPosition();
    bool collided = false;

    if (pos.x < 0.f) {
        pos.x = 0.f;
        collided = true;
    }
    else if (pos.x + hitbox.width > screenWidth) {
        pos.x = screenWidth - hitbox.width;
        collided = true;
    }

    if (pos.y < 0.f) {
        pos.y = 0.f;
        collided = true;
    }

    else if (pos.y + hitbox.height > screenHeight) {
        pos.y = screenHeight - hitbox.height;
        collided = true;
    }

    if (collided) {
        hitboxShape.setOutlineThickness(50);
    } else {
        hitboxShape.setOutlineThickness(2);
    }

    sprite.setPosition(pos);
    hitboxShape.setPosition(pos);
}

// bool Entity::checkCollision(const Entity& other) const {
//     return hitbox.intersects(other.getHitbox());
// }
//


void Player::update(float &dt,float screenWidth, float screenHeight) {
    this->setVelocity({0.f, 0.f});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->setVelocity(this->getVelocity() + sf::Vector2f(this->getSpeed(), 0.f));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->setVelocity(this->getVelocity() - sf::Vector2f(this->getSpeed(), 0.f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->setVelocity(this->getVelocity() - sf::Vector2f(0.f, this->getSpeed()));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->setVelocity(this->getVelocity() + sf::Vector2f(0.f, this->getSpeed()));

    move(dt);


    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setPosition(sprite.getPosition());

    ScreenCollision(screenWidth, screenHeight);

}
void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(hitboxShape);
}

void Player::reduceHP(float amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
}
float Player::getHP() const
{
    return hp;
}


std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Viteza: " << player.getVelocity().x << ", " << player.getVelocity().y << std::endl;
    return os;
}
