#include "Entity.h"
#include "Enemy.h"

Entity::Entity(const sf::Texture& texture, const sf::Vector2f& position)
	: velocity(0.0f, 0.0f), speed(300.0f), isDead(false)
{
	sprite.setTexture(texture);
	sprite.setPosition(position);

	hitbox = sprite.getGlobalBounds();
	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
	hitboxShape.setPosition(sprite.getPosition());

	setIsAlive();
}

Entity::Entity(const Entity& other)
	: velocity(other.velocity), speed(other.speed), isDead(other.isDead)
{
	sprite = other.sprite;
	hitbox = other.hitbox;
	hitboxShape = other.hitboxShape;
}


void Entity::swap(Entity& other)
{
	std::swap(sprite, other.sprite);
	std::swap(hitbox, other.hitbox);
	std::swap(hitboxShape, other.hitboxShape);
	std::swap(velocity, other.velocity);
	std::swap(speed, other.speed);
	std::swap(isDead, other.isDead);
}

Entity& Entity::operator=(Entity other)
{
	std::swap(*this, other);
	return *this;
}


void Entity::setSpeed(float _speed)
{
	this->speed = _speed;
}

void Entity::move(const float& dt)
{
	sprite.move(velocity * dt);
	hitbox = sprite.getGlobalBounds();
	hitboxShape.setPosition(sprite.getPosition());
}

void Entity::update([[maybe_unused]] float& dt)
{
	hitbox = sprite.getGlobalBounds();
	hitboxShape.setPosition(sprite.getPosition());
}

void Entity::setTexture(const sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::render(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(hitboxShape);
}

const sf::FloatRect& Entity::getHitbox() const
{
	return hitbox;
}

const sf::Sprite& Entity::getSprite() const
{
	return sprite;
}

bool Entity::isColliding(const Entity& entity1, const Entity& entity2)
{
	const sf::FloatRect& rect1 = entity1.getHitbox();
	const sf::FloatRect& rect2 = entity2.getHitbox();

	return ((rect1.left < rect2.left + rect2.width) &&
		(rect1.left + rect1.width > rect2.left) &&
		(rect1.top < rect2.top + rect2.height) &&
		(rect1.top + rect1.height > rect2.top));
}

bool Entity::topCollision(const Entity& other) const
{
	const sf::FloatRect& rect1 = sprite.getGlobalBounds();
	const sf::FloatRect& rect2 = other.sprite.getGlobalBounds();

	if (rect1.top + rect1.height > rect2.top &&
		rect1.top < rect2.top &&
		rect1.left < rect2.left + rect2.width &&
		rect1.left + rect1.width > rect2.left)
	{
		return true;
	}
	return false;
}


bool Entity::bottomCollision(const Entity& other) const
{
	const sf::FloatRect& rect1 = sprite.getGlobalBounds();
	const sf::FloatRect& rect2 = other.sprite.getGlobalBounds();

	if (rect1.top < rect2.top + rect2.height &&
		rect1.top + rect1.height > rect2.top + rect2.height &&
		rect1.left < rect2.left + rect2.width &&
		rect1.left + rect1.width > rect2.left)
	{
		return true;
	}
	return false;
}

bool Entity::rightCollision(const Entity& other) const
{
	const sf::FloatRect& rect1 = sprite.getGlobalBounds();
	const sf::FloatRect& rect2 = other.sprite.getGlobalBounds();

	if (rect1.left < rect2.left &&
		rect1.left + rect1.width > rect2.left &&
		rect1.top < rect2.top + rect2.height &&
		rect1.top + rect1.height > rect2.top)
	{
		return true;
	}
	return false;
}


bool Entity::leftCollision(const Entity& other) const
{
	const sf::FloatRect& rect1 = sprite.getGlobalBounds();
	const sf::FloatRect& rect2 = other.sprite.getGlobalBounds();

	if (rect1.left < rect2.left + rect2.width &&
		rect1.left + rect1.width > rect2.left + rect2.width &&
		rect1.top < rect2.top + rect2.height &&
		rect1.top + rect1.height > rect2.top)
	{
		return true;
	}
	return false;
}

bool Entity::getIsDead() const
{
	return isDead;
}

void Entity::setIsDead()
{
	isDead = true;
}

void Entity::setIsAlive()
{
	isDead = false;
}


void Entity::setVelocity(const sf::Vector2f& _velocity)
{
	this->velocity = _velocity;
}

sf::Vector2f Entity::getVelocity() const
{
	return this->velocity;
}

float Entity::getSpeed() const
{
	return this->speed;
}

//
// std::ostream& operator<<(std::ostream& os, const Entity& entity) {
//     os << "Entitatea exista: " << std::endl;
//     return os;
// }
