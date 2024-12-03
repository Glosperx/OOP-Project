#include "Player.h"
#include "Goomba.h"
#include "Exceptions.h"

Player::Player(const sf::Vector2f& position)
	: Entity(position, 1500.0f)
{
	// playertexture.loadFromFile("C:/Users/glosper/Documents/GitHub/OOP-Project/assets/textures/amongus1.png");
	// playertexture.loadFromFile("assets/textures/amongus1.png");

	loadResources();

	sprite.setTexture(playertexture);
	sprite.setPosition(position);
	sprite.setScale(0.5f, 0.5f);
	hp = 100;

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setFillColor(sf::Color::Transparent);
	hitboxShape.setOutlineColor(sf::Color::Red);
	hitboxShape.setOutlineThickness(2);
	hitboxShape.setPosition(sprite.getPosition());

	setIsAlive();
}

// Resources loading
void Player::loadResources()
{
	if (!playertexture.loadFromFile("src/assets/textures/amongus1.png"))
	{
		throw resourceLoadError("src/assets/textures/amongus1.png");
	}

	if (!collision_castraveti.loadFromFile("src/assets/audio/ultimul_castravete.wav"))
	{
		throw resourceLoadError("src/assets/audio/ultimul_castravete.wav");
	}

	if (!collision_am_spus_castraveti.loadFromFile("src/assets/audio/am_spus_castraveti.wav"))
	{
		throw resourceLoadError("src/assets/audio/am_spus_castraveti.wav");
	}

	if (!gameOverFont.loadFromFile("src/assets/font/TT-Rounds-Neue-Trial-Compressed-Medium-BF6438a17188007.ttf"))
	{
		throw fontLoadError("src/assets/font/TT-Rounds-Neue-Trial-Compressed-Medium-BF6438a17188007.ttf");
	}
}

void Player::setupGameOverText( sf::RenderWindow& window)
{
	gameOverText.setFont(gameOverFont);
	gameOverText.setString("Game Over");
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setStyle(sf::Text::Bold);

	sf::FloatRect textBounds = gameOverText.getLocalBounds();
	gameOverText.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
	gameOverText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
}

const sf::Text& Player::getGameOverText() const
{
	return gameOverText;
}




void Player::setSpritePosition(float x, float y)
{
	sprite.setPosition(x, y);
}


sf::Vector2f Player::getPosition() const
{
	return sprite.getPosition();
}

const sf::FloatRect& Player::getHitbox() const
{
	return hitbox;
}

void Player::updateHitbox()
{
	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setPosition(sprite.getPosition());
}


void Player::ScreenCollision(float screenWidth, float screenHeight)
{
	sf::Vector2f pos = sprite.getPosition();
	bool collided = false;

	if (pos.x < 0.f)
	{
		pos.x = 0.f;
		collided = true;
	}
	else if (pos.x + hitbox.width > screenWidth)
	{
		pos.x = screenWidth - hitbox.width;
		collided = true;
	}

	if (pos.y < 0.f)
	{
		pos.y = 0.f;
		collided = true;
	}

	else if (pos.y + hitbox.height > screenHeight)
	{
		pos.y = screenHeight - hitbox.height;
		collided = true;
	}

	if (collided)
	{
		hitboxShape.setOutlineThickness(50);

		if (collisionCount % 2)
		{
			castraveti.setBuffer(collision_am_spus_castraveti);
			// collisionCount++;
		}
		else
		{
			castraveti.setBuffer(collision_castraveti);
			// collisionCount++;
		}

		castraveti.play();
		collisionCount++;
		std::cout << collisionCount << std::endl;
	}
	else
	{
		hitboxShape.setOutlineThickness(2);
	}

	sprite.setPosition(pos);
	hitboxShape.setPosition(pos);
}

void Player::moveCharacter(float dt)
{
	if (getIsDead())
	{
		return;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->setVelocity(sf::Vector2f(this->getSpeed(), 0.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->setVelocity(sf::Vector2f(-this->getSpeed(), 0.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->setVelocity(sf::Vector2f(0.f, -this->getSpeed()));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->setVelocity(sf::Vector2f(0.f, this->getSpeed()));
	}
	else
	{
		this->setVelocity({0.f, 0.f});
	}

	sprite.move(velocity * dt);
}

bool Player::handleCollisionWithEnemy(const std::vector<std::shared_ptr<Enemy>>& enemies)
{
	bool collided = false;

	if (getIsDead())
	{
		return false;
	}

	for (const auto& enemy : enemies)
	{
		if (enemy->getIsDead())
		{
			continue;
		}

		if (Entity::isColliding(*this, *enemy))
		{
			collided = true;

			if (auto* goomba = dynamic_cast<Goomba*>(enemy.get()))
			{
				if (topCollision(*goomba))
				{
					goomba->setIsDead(); // Goomba is dead
					std::cout << "Goomba is dead\n";
					continue;
				}
			}

			// Right Collision
			if (rightCollision(*enemy))
			{
				velocity.x = 0.f;
				sprite.setPosition(enemy->getHitbox().left - sprite.getGlobalBounds().width,
				                   sprite.getGlobalBounds().top);
				enemy->dealDamage(*this);
				std::cout << "RIGHT COLLISION\n";
			}
			// Left Collision
			else if (leftCollision(*enemy))
			{
				velocity.x = 0.f;
				sprite.setPosition(enemy->getHitbox().left + enemy->getHitbox().width, sprite.getGlobalBounds().top);
				enemy->dealDamage(*this);
				std::cout << "LEFT COLLISION\n";
			}
			// Bottom Collision
			else if (bottomCollision(*enemy))
			{
				velocity.y = 1.f;
				sprite.setPosition(sprite.getGlobalBounds().left, enemy->getHitbox().top + enemy->getHitbox().height);
				enemy->dealDamage(*this);
				std::cout << "BOTTOM COLLISION\n";
			}
			// Top Collision
			else if (topCollision(*enemy))
			{
				velocity.y = 0.f;
				sprite.setPosition(sprite.getGlobalBounds().left,
				                   enemy->getHitbox().top - sprite.getGlobalBounds().height);
				std::cout << "TOP COLLISION\n";
			}
		}
	}

	return collided;
}


void Player::update(float& dt, float screenWidth, float screenHeight,
                    const std::vector<std::shared_ptr<Enemy>>& enemies)
{
	updateHitbox();

	if (!handleCollisionWithEnemy(enemies))
	{
		moveCharacter(dt);
	}
	ScreenCollision(screenWidth, screenHeight);

	hitboxShape.setPosition(sprite.getPosition());


}


void Player::render(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(hitboxShape);

	if (getIsDead())
	{
		setupGameOverText(window);
		window.draw(gameOverText);
	}
}

void Player::reduceHP(float amount)
{
	hp -= amount;
	if (hp <= 0)
	{
		hp = 0;
		setIsDead();
		std::cout << "Player is dead!\n";
	}
}

float Player::getHP() const
{
	return hp;
}
