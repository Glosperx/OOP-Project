#include "Player.h"

Player::Player(const sf::Vector2f& position)
    : Entity(position, 500.0f)
{
    // playertexture.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/assets/textures/amongus1.png");
   // playertexture.loadFromFile("assets/textures/amongus1.png");
    playertexture.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/src/assets/textures/amongus1.png");
    collision_castraveti.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/src/assets/audio/ultimul_castravete.wav");
    collision_am_spus_castraveti.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/src/assets/audio/am_spus_castraveti.wav");


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

        if (collisionCount % 2) {

            castraveti.setBuffer(collision_am_spus_castraveti);
            // collisionCount++;
        } else {

            castraveti.setBuffer(collision_castraveti);
            // collisionCount++;
        }

        castraveti.play();
         collisionCount++;
        std::cout<<collisionCount<<std::endl;
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
void Player::moveCharacter(float dt) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->setVelocity(sf::Vector2f(this->getSpeed(), 0.f));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->setVelocity(sf::Vector2f(-this->getSpeed(), 0.f));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->setVelocity(sf::Vector2f(0.f, -this->getSpeed()));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->setVelocity(sf::Vector2f(0.f, this->getSpeed()));
    } else {

        this->setVelocity({0.f, 0.f});
    }

    sprite.move(velocity * dt);
}




void Player::update(float& dt, float screenWidth, float screenHeight, const Entity& otherEntity) {

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setPosition(sprite.getPosition());


    bool isColliding = Entity::isColliding(*this, otherEntity);

    if (isColliding) {
        hitboxShape.setOutlineThickness(50);
        // std::cout << "Collision detected!" << std::endl;

        sprite.move(-velocity * dt);
        this->setVelocity({0.f, 0.f});

    } else {
        hitboxShape.setOutlineThickness(2);
    }

    ScreenCollision(screenWidth, screenHeight);
    hitboxShape.setPosition(sprite.getPosition());

    if (!isColliding) {
        moveCharacter(dt);
    }
}



void Player::render(sf::RenderWindow& window) const
{
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
    // os << "Viteza: " << player.getVelocity().x << ", " << player.getVelocity().y << std::endl;
    return os;
}
