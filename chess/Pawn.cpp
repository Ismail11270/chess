#include "Pawn.h"
#include <iostream>

void Pawn::moveTo(BoardPiece piece) {
	setPosition(piece);
}

Pawn::Pawn(BoardPiece* piece,sf::Color color) : Figure(piece, color) {
	
	this->texture = new sf::Texture();
	this->texture->loadFromFile("res/pawn_white.png");
	sprite = new sf::Sprite(*this->texture);
	sprite->setColor(color);
	sprite->setScale({ 0.125f,0.125f });
	setPosition(*getPiece());
}

void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*sprite, states);
}

sf::Vector2f Pawn::getPosition() {
	return sprite->getPosition();
}

void Pawn::setPosition(BoardPiece p) {
	sf::Vector2f pos = p.getPosition();
	sf::Vector2f size(sprite->getTextureRect().width * sprite->getScale().x, sprite->getTextureRect().height * sprite->getScale().y);
	std::cout << size.x << " " << size.y << std::endl;

	sprite->setPosition({ pos.x + (BoardPiece::SQUARE_SIZE - size.x) / 2, pos.y + (BoardPiece::SQUARE_SIZE - size.y) / 2 });
}
sf::Sprite* Pawn::getSprite() {
	return sprite;
}

