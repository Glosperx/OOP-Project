//
// Created by glosper on 12/8/2024.
//

#include "LuckyBlock.h"
#include "Player.h"
#include "ResourceManager.h"

LuckyBlock::LuckyBlock(const sf::Vector2f& position) {
	sprite.setTexture(ResourceManager::luckyBlockTexture);
	sprite.setPosition(position);

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setFillColor(sf::Color::Transparent);
	hitboxShape.setOutlineColor(sf::Color::Yellow);
	hitboxShape.setOutlineThickness(2);
	hitboxShape.setPosition(sprite.getPosition());
}

void LuckyBlock::loadResources() {
	ResourceManager::loadResources();
}

void LuckyBlock::handleCollision(Player& player) {
	if (player.bottomCollision(*this)) {
		sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
		hitbox = sf::FloatRect(0, 0, 0, 0);
		hitboxShape.setSize(sf::Vector2f(0, 0));

		std::cout << "LuckyBlock activated!\n";
	}
	else if (player.topCollision(*this)) {
		player.setPosition(player.getPosition().x, hitbox.top - player.getHitbox().height);
	} else if (player.rightCollision(*this)) {
		player.setPosition(hitbox.left - player.getHitbox().width, player.getPosition().y);
	} else if (player.leftCollision(*this)) {
		player.setPosition(hitbox.left + hitbox.width, player.getPosition().y);
	}
}

void LuckyBlock::update([[maybe_unused]] float &dt, Player& player) {
	handleCollision(player);

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setPosition(sprite.getPosition());
}

void LuckyBlock::render(sf::RenderTarget& target) {
	target.draw(sprite);
	target.draw(hitboxShape);
}

LuckyBlock::~LuckyBlock() {}