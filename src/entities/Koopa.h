#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class Koopa : public Enemy
{
public:
	Koopa() = default;
	Koopa(const sf::Vector2f& position);
	virtual Koopa* clone() const override;
	static void loadTexture();
	Koopa(const sf::Texture& texture, const sf::Vector2f& position);


	void dealDamage(Player& player) override;
	void handleCollision(Player& player) override;

	void update(float& dt, Player& player);
	void render(sf::RenderWindow& window);

private:
	float hp = 20; // Adjust HP if needed
	sf::Sprite sprite;
	static sf::Texture koopaTexture;
	sf::FloatRect hitbox;
	sf::RectangleShape hitboxShape;
};
