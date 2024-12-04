#include "Button.h"


// Constructor
Button::Button(float x, float y, float width, float height, const std::string& text, const sf::Font& font,
               const sf::Color& idleColor, const sf::Color& hoverColor, const sf::Color& pressedColor)
	: idleColor(idleColor), hoverColor(hoverColor), pressedColor(pressedColor), pressed(false)
{
	buttonShape.setPosition(x, y);
	buttonShape.setSize(sf::Vector2f(width, height));
	buttonShape.setFillColor(idleColor);

	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(24);
	buttonText.setFillColor(sf::Color::White);

	loadResources("src/assets/font/TT-Rounds-Neue-Trial-Compressed-Medium-BF6438a17188007.ttf");

	// Center the text
	sf::FloatRect textRect = buttonText.getLocalBounds();
	buttonText.setOrigin(textRect.width / 2, textRect.height / 2);
	buttonText.setPosition(x + width / 2, y + height / 2 - 5);
}

void Button::loadResources(const std::string& fontPath)
{
	if (!buttonFont.loadFromFile(fontPath))
	{
		throw buttonFontLoadError(fontPath);
	}
	buttonText.setFont(buttonFont);
}


// Check if the button is pressed
bool Button::isPressed([[maybe_unused]]const sf::Vector2f& mousePos) const
{
	return pressed;
}

// Update function
void Button::update(sf::Vector2f mousePos)
{
	sf::FloatRect mouseHitbox(mousePos.x, mousePos.y, 1, 1); // Hitbox-ul mouse-ului (punct)

	pressed = false;

	if (buttonShape.getGlobalBounds().intersects(mouseHitbox))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonShape.setFillColor(pressedColor);
			pressed = true;
		}
		else
		{
			buttonShape.setFillColor(hoverColor);
		}
	}
	else
	{
		buttonShape.setFillColor(idleColor);
	}
}


// Render function
void Button::render(sf::RenderTarget& target)
{
	target.draw(buttonShape);
	target.draw(buttonText);
}
