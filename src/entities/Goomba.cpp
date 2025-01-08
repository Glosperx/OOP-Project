//
// Created by glosper on 14/11/2024.
//

#include "Goomba.h"
#include "Game.h"
#include "Enemy.h"
#include "ResourceManager.h"


// Loads the Goomba texture
// void Goomba::loadTexture()
// {
// 	if (!goombaTexture.loadFromFile("src/assets/textures/goomba1.png"))
// 	{
// 		throw std::runtime_error("Failed to load Goomba texture");
// 	}
// }

// Goomba Constructor
Goomba::Goomba(const sf::Vector2f& position) : Enemy(position)
{
	sprite.setTexture(ResourceManager::goombaTexture);
	sprite.setPosition(position);
	sprite.setScale(0.5f, 0.5f);

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setFillColor(sf::Color::Transparent);
	hitboxShape.setOutlineColor(sf::Color::Blue);
	hitboxShape.setOutlineThickness(2);
	hitboxShape.setPosition(sprite.getPosition());

	setIsAlive(); // Set Goomba alive status
}

void Goomba::loadResources()
{
	ResourceManager::loadResources();
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


void Goomba::handleCollision(Player& player)
{
	if (player.topCollision(*this))
	{
		setIsDead();
		sprite.setTextureRect(sf::IntRect(0, 0, 0, 0)); // Hide Goomba
		hitbox = sf::FloatRect(0, 0, 0, 0);
		hitboxShape.setSize(sf::Vector2f(0, 0));
		// std::cout << "Goomba died\n";
	}
}


void Goomba::update([[maybe_unused]] float& dt, Player& player)
{

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setPosition(sprite.getPosition());

	if (getIsDead())
	{
		hitbox = sf::FloatRect(0, 0, 0, 0);
		hitboxShape.setSize(sf::Vector2f(0, 0));
		return;
	}

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
