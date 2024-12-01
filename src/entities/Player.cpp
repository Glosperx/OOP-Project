#include "Player.h"
#include "Goomba.h"

Player::Player(const sf::Vector2f& position)
    : Entity(position, 1500.0f)
{
    // playertexture.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/assets/textures/amongus1.png");
   // playertexture.loadFromFile("assets/textures/amongus1.png");
    playertexture.loadFromFile("src/assets/textures/amongus1.png");
    collision_castraveti.loadFromFile("src/assets/audio/ultimul_castravete.wav");
    collision_am_spus_castraveti.loadFromFile("src/assets/audio/am_spus_castraveti.wav");


    sprite.setTexture(playertexture);
    sprite.setPosition(position);
    sprite.setScale(0.5f, 0.5f);
    hp=100;

    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setFillColor(sf::Color::Transparent);
    hitboxShape.setOutlineColor(sf::Color::Red);
    hitboxShape.setOutlineThickness(2);
    hitboxShape.setPosition(sprite.getPosition());

    setIsAlive();

}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}
const sf::FloatRect& Player::getHitbox() const {
    return hitbox;
}

void Player::updateHitbox() {
    hitbox = sprite.getGlobalBounds();
    hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxShape.setPosition(sprite.getPosition());
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

    if (getIsDead()) {
        return;
    }

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
//
// void Player::handleCollisionWithEnemy(const std::shared_ptr<Enemy>& enemy) {
//     const sf::FloatRect& playerBounds = sprite.getGlobalBounds();
//     const sf::FloatRect& enemyBounds = enemy->getHitbox();
//
//     // Top collision with enemy
//     if (topCollision(*enemy)) {
//         velocity.y = 0.f;
//         sprite.setPosition(playerBounds.left, enemyBounds.top + enemyBounds.height);
//         std::cout << "TOP COLLISION\n";
//         return;
//     }
//
//     // Bottom collision with enemy
//     if (bottomCollision(*enemy)) {
//         velocity.y = 0.f;
//         sprite.setPosition(playerBounds.left, enemyBounds.top - playerBounds.height);
//         std::cout << "BOTTOM COLLISION\n";
//         return;
//     }
//
//     // Right collision with enemy
//     if (rightCollision(*enemy)) {
//         velocity.x = 0.f;
//         sprite.setPosition(enemyBounds.left - playerBounds.width, playerBounds.top);
//         std::cout << "RIGHT COLLISION\n";
//         return;
//     }
//
//     // Left Collision with enemy
//     if (leftCollision(*enemy)) {
//         velocity.x = 0.f;
//         sprite.setPosition(enemyBounds.left + enemyBounds.width, playerBounds.top);
//         std::cout << "LEFT COLLISION\n";
//         return;
//     }
// }
bool Player::handleCollisionWithEnemy(const std::vector<std::shared_ptr<Enemy>>& enemies) {
    bool collided = false;

    if (getIsDead())
    {
        return false;
    }

    for (const auto& enemy : enemies) {
        if (enemy->getIsDead()) {
            continue;
        }

        if (Entity::isColliding(*this, *enemy)) {
            collided = true;

            if (auto* goomba = dynamic_cast<Goomba*>(enemy.get())) {
                if (topCollision(*goomba)) {
                    goomba->setIsDead(); // Goomba is dead
                    std::cout << "Goomba is dead\n";
                    continue;
                }
            }

            // Right Collision
            if (rightCollision(*enemy)) {
                velocity.x = 0.f;
                sprite.setPosition(enemy->getHitbox().left - sprite.getGlobalBounds().width, sprite.getGlobalBounds().top);
                enemy->dealDamage(*this);
                std::cout << "RIGHT COLLISION\n";
            }
            // Left Collision
            else if (leftCollision(*enemy)) {
                velocity.x = 0.f;
                sprite.setPosition(enemy->getHitbox().left + enemy->getHitbox().width, sprite.getGlobalBounds().top);
                enemy->dealDamage(*this);
                std::cout << "LEFT COLLISION\n";
            }
            // Bottom Collision
            else if (bottomCollision(*enemy)) {
                velocity.y = 1.f;
                sprite.setPosition(sprite.getGlobalBounds().left, enemy->getHitbox().top + enemy->getHitbox().height);
                enemy->dealDamage(*this);
                std::cout << "BOTTOM COLLISION\n";
            }
            // Top Collision
            else if (topCollision(*enemy)) {
                velocity.y = 0.f;
                sprite.setPosition(sprite.getGlobalBounds().left, enemy->getHitbox().top - sprite.getGlobalBounds().height);
                std::cout << "TOP COLLISION\n";
            }
        }
    }

    return collided;
}





void Player::update(float& dt, float screenWidth, float screenHeight,const std::vector<std::shared_ptr<Enemy>>& enemies) {

    updateHitbox();

    if (!handleCollisionWithEnemy(enemies)) {
        moveCharacter(dt);
    }
    ScreenCollision(screenWidth, screenHeight);

    hitboxShape.setPosition(sprite.getPosition());
}



void Player::render(sf::RenderWindow& window) const
{
    window.draw(sprite);
    window.draw(hitboxShape);
}

void Player::reduceHP(float amount)
{
    hp -= amount;
    if (hp <= 0){

        hp = 0;
        setIsDead();
        std::cout << "Player is dead!\n";
    }
}

float Player::getHP() const
{
    return hp;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    // os << "Viteza: " << player.getVelocity().x << ", " << player.getVelocity().y << std::endl;
    return os;
}
