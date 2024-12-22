// //
// // Created by glosper on 12/8/2024.
// //
//
// #include "LuckyBlock.h"
// #include "ResourceManager.h"
//
// LuckyBlock::LuckyBlock(const sf::Texture& texture, const sf::Vector2f& position)
// 	: Entity(texture, position) { // Transmite textura către clasa de bază Entity
// 	sprite.setPosition(position);
// 	sprite.setScale(0.5f, 0.5f);
//
// 	// Configurarea hitbox-ului
// 	hitbox = sprite.getGlobalBounds();
// 	hitboxShape.setSize(sf::Vector2f(hitbox.width, hitbox.height));
// 	hitboxShape.setFillColor(sf::Color::Transparent);
// 	hitboxShape.setOutlineColor(sf::Color::Yellow);
// 	hitboxShape.setOutlineThickness(2);
// 	hitboxShape.setPosition(sprite.getPosition());
// }
//
// void LuckyBlock::loadResources() {
// 	ResourceManager::loadResources(); // Încarcă resursele global
// }
//
