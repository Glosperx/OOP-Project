//
// Created by glosper on 12/1/2024.
//

#include "Koopa.h"
#include "Player.h"

sf::Texture Koopa::koopaTexture;

void Koopa::loadTexture()
{
	if (!koopaTexture.loadFromFile("src/assets/textures/koopa.png"))
	{
		throw std::runtime_error("Failed to load Goomba texture");
	}
}

Koopa::Koopa(const sf::Vector2f& position): Enemy(koopaTexture, position)
{
	sprite.setTexture(koopaTexture);
	sprite.setPosition(position);
	sprite.setScale(0.1f, 0.1f);

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setFillColor(sf::Color::Transparent);
	hitboxShape.setOutlineColor(sf::Color::Blue);
	hitboxShape.setOutlineThickness(2);
	hitboxShape.setPosition(sprite.getPosition());

	setIsAlive(); //Koopa alive
}

Koopa* Koopa::clone() const
{
	return new Koopa(*this);
}


void Koopa::dealDamage(Player& player)
{
	float damage = 15;
	player.reduceHP(damage);
	std::cout << "Koopa dealt " << damage << " damage! Player's health: " << player.getHP() << "\n";
}


void Koopa::handleCollision(Player& player)
{
	if (player.topCollision(*this))
	{
		setIsDead();
		sprite.setTextureRect(sf::IntRect(0, 0, 0, 0)); // Hide Koopa
		hitbox = sf::FloatRect(0, 0, 0, 0);
		hitboxShape.setSize(sf::Vector2f(0, 0));
		std::cout << "KOOPA died\n";
	}
}

void Koopa::update([[maybe_unused]] float& dt, Player& player)
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


void Koopa::render(sf::RenderWindow& window)
{
	if (getIsDead())
	{
		return;
	}

	window.draw(sprite);
	window.draw(hitboxShape);
}
