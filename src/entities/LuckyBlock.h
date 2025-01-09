#ifndef LUCKYBLOCK_H
#define LUCKYBLOCK_H

#include "Entity.h"
#include "Player.h"

class LuckyBlock : public Entity {
public:

	LuckyBlock() = default ;
	explicit LuckyBlock(const sf::Vector2f& position);
	static void loadTexture();
	explicit LuckyBlock(const sf::Texture& texture, const sf::Vector2f& position);

	static void loadResources();

	void handleCollision(Player& player);
	void update(float &dt, Player& player);
	void render(sf::RenderTarget& target);

	virtual ~LuckyBlock();
};

#endif //LUCKYBLOCK_H
