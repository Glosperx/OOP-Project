#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Exceptions.h"

class Button
{
private:
	sf::RectangleShape buttonShape;
	sf::Text buttonText;
	sf::Font buttonFont;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;


	bool pressed;

public:
	Button(float x, float y, float width, float height, const std::string& text, const sf::Font& font,
	       const sf::Color& idleColor, const sf::Color& hoverColor, const sf::Color& pressedColor);
	void loadResources(const std::string& fontPath);

	bool isPressed(const sf::Vector2f& mousePos) const;

	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget& target);
};

#endif // BUTTON_H
