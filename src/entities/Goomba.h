#ifndef GOOMBA_H
#define GOOMBA_H
#include "Enemy.h"
#include "Player.h"

class Goomba : public Enemy
{
public:
	Goomba() = default;

	void loadTexture(const sf::Texture& texture);

	explicit Goomba(const sf::Vector2f& position);
	void loadResources();

	Goomba(const sf::Texture& texture, const sf::Vector2f& position);

	void dealDamage(Player& player) override;
	void takeDamage();
	// void update(float& dt, Player& player);

	virtual Goomba* clone() const override;
	void handleCollision(Player& player) override;
	void render(sf::RenderWindow& window) override;
	void update(float& dt, Player& player) override;

private:
	float hp = 10;
	sf::Sprite sprite;
};

#endif //GOOMBA_H
