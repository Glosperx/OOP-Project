#ifndef LUCKYBLOCK_H
#define LUCKYBLOCK_H

#include "../entities/Entity.h"
#include "../entities/Player.h"

class LuckyBlock : public Entity {
public:

	LuckyBlock() = default ;
	explicit LuckyBlock(const sf::Vector2f& position);
	explicit LuckyBlock(const sf::Texture& texture, const sf::Vector2f& position);

	static void loadResources();

	void handleCollision(Player& player);
	void update(float dt, Player& player);
	void render(sf::RenderTarget& target);

	virtual ~LuckyBlock();

private:
	sf::Sprite sprite;
	sf::FloatRect hitbox;
	sf::RectangleShape hitboxShape;
	static sf::Texture luckyBlockTexture;
};

#endif //LUCKYBLOCK_H
