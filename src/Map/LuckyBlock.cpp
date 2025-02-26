//
// Created by glosper on 12/8/2024.
//

#include "LuckyBlock.h"
#include "ResourceManager.h"


sf::Texture LuckyBlock::luckyBlockTexture;

LuckyBlock::LuckyBlock(const sf::Vector2f& position)
	: Entity(luckyBlockTexture, position) {

	sprite.setTexture(ResourceManager::luckyBlockTexture);
	sprite.setPosition(position);
	sprite.setScale(1.5f, 1.5f);

	// Hitbox
	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setFillColor(sf::Color::Transparent);
	hitboxShape.setOutlineColor(sf::Color::Yellow);
	hitboxShape.setOutlineThickness(2);
	hitboxShape.setPosition(sprite.getPosition());

	setIsAlive();
}

void LuckyBlock::loadResources() {
	ResourceManager::loadResources();
}


void LuckyBlock::handleCollision(Player& player) {
	if (player.bottomCollision(*this)) {

		setIsDead();
		sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));//Hide texture
		hitbox = sf::FloatRect(0, 0, 0, 0); // Disable hitbox
		hitboxShape.setSize(sf::Vector2f(0, 0)); // Hide hitbox
	}
}

void LuckyBlock::update([[maybe_unused]] float dt, Player& player)
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


void LuckyBlock::render(sf::RenderTarget& window)
{
	if (getIsDead())
	{
		return;
	}

	window.draw(sprite);
	window.draw(hitboxShape);
}

LuckyBlock::~LuckyBlock() {

}
