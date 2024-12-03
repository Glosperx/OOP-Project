//
// Created by glosper on 14/11/2024.
//

#include "Goomba.h"
#include "Game.h"
#include "Enemy.h"

sf::Texture Goomba::goombaTexture;

// Loads the Goomba texture
void Goomba::loadTexture()
{
	if (!goombaTexture.loadFromFile("src/assets/textures/goomba1.png"))
	{
		throw std::runtime_error("Failed to load Goomba texture");
	}
}

// Goomba Constructor
Goomba::Goomba(const sf::Vector2f& position) : Enemy(goombaTexture, position)
{
	sprite.setTexture(goombaTexture);
	sprite.setPosition(position);
	sprite.setScale(0.5f, 0.5f);

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setFillColor(sf::Color::Transparent);
	hitboxShape.setOutlineColor(sf::Color::Blue);
	hitboxShape.setOutlineThickness(2);
	hitboxShape.setPosition(sprite.getPosition());

	setIsAlive(); // Set the Goomba s alive status
}

Goomba* Goomba::clone() const
{
	return new Goomba(*this);
}

void Goomba::dealDamage(Player& player)
{
	player.reduceHP(20);
	std::cout << "Player s health" << player.getHP() << "\n";
}

//
// void Goomba::takeDamage() {
//     reduceHP(10);
//     std::cout << "Goomba's health: " << getHP() << "\n";
// }
//
// void Goomba::handleCollision(Player& player) {
//     if (player.topCollision(*this)) {
//         setIsDead();
//         sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
//         hitbox = sf::FloatRect(0, 0, 0, 0);
//         hitboxShape.setSize(sf::Vector2f(0, 0));
//         std::cout << "Top collision\n";
//     }
//     else if (player.bottomCollision(*this)) {
//         player.setVelocity(sf::Vector2f(player.getVelocity().x, 0.f));
//         player.setSpritePosition(player.getSprite().getGlobalBounds().left, this->getHitbox().top + this->getHitbox().height);
//         std::cout << "Bottom collision\n";
//     }
//     else if (player.leftCollision(*this)) {
//         player.setVelocity(sf::Vector2f(0.f, player.getVelocity().y));
//         player.setSpritePosition(this->getHitbox().left + this->getHitbox().width, player.getSprite().getGlobalBounds().top);
//         std::cout << "Left collision\n";
//     }
//     else if (player.rightCollision(*this)) {
//         player.setVelocity(sf::Vector2f(0.f, player.getVelocity().y));
//         player.setSpritePosition(this->getHitbox().left - player.getSprite().getGlobalBounds().width, player.getSprite().getGlobalBounds().top);
//         std::cout << "Right collision\n";
//     }
// }


void Goomba::handleCollision(Player& player)
{
	if (player.topCollision(*this))
	{
		setIsDead();
		sprite.setTextureRect(sf::IntRect(0, 0, 0, 0)); // Ascunde Goomba
		hitbox = sf::FloatRect(0, 0, 0, 0);
		hitboxShape.setSize(sf::Vector2f(0, 0));
		// std::cout << "Goomba died\n";
	}
}


void Goomba::update([[maybe_unused]] float& dt, Player& player)
{
	if (getIsDead())
	{
		hitbox = sf::FloatRect(0, 0, 0, 0);
		hitboxShape.setSize(sf::Vector2f(0, 0));
		return;
	}

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setPosition(sprite.getPosition());

	handleCollision(player);
}


void Goomba::render(sf::RenderWindow& window)
{
	if (getIsDead())
	{
		return;
	}

	window.draw(sprite);
	window.draw(hitboxShape);
}
