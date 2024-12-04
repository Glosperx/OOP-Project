//
// Created by glosper on 02/11/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Enemy.h"
#include "Exceptions.h"


class Player : public Entity
{
public:
	Player() = default ;
	explicit Player(const sf::Vector2f& position);
	virtual ~Player() override = default;

	void update(float& dt, float screenWidth, float screenHeight, const std::vector<std::shared_ptr<Enemy>>& enemies);
	// virtual void update(float &dt) override;
	using Entity::update;
	// void update(float& dt, float screenWidth, float screenHeight, const Entity& otherEntity);
	void render(sf::RenderWindow& window) override;
	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	sf::Vector2f getPosition() const;
	const sf::FloatRect& getHitbox() const;
	void updateHitbox();
	void ScreenCollision(float screenWidth, float screenHeight);
	void moveCharacter(float dt);
	bool handleCollisionWithEnemy(const std::vector<std::shared_ptr<Enemy>>& enemies);

	// void handleCollisionWithEnemy(const std::shared_ptr<Enemy>& enemy);

	void loadResources();

	void setupGameOverText(sf::RenderWindow& window);
	void gameOver();
	[[nodiscard]] float getHP() const;
	void setSpritePosition(float x, float y);

	void reduceHP(float amount);
	const sf::Text& getGameOverText() const;

private:
	float hp = 100;
	sf::Texture playertexture;
	// int collisionCount = 0;
	static int collisionCount;
	sf::Font gameOverFont;
	sf::Text gameOverText;
	sf::SoundBuffer collision_castraveti;
	sf::Sound castraveti;
	sf::SoundBuffer collision_am_spus_castraveti;
};


#endif //PLAYER_H
