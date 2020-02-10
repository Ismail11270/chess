#include "Pawn.h"
#include <iostream>
#include <cmath>

void Pawn::moveTo(BoardPiece *piece) {
	getPiece()->resetColor();
	getPiece()->setEmpty(true);
	setPosition(*piece);
	setPiece(piece);
	getPiece()->setEmpty(false);
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
	sprite->setPosition({ pos.x + (BoardPiece::SQUARE_SIZE - size.x) / 2, pos.y + (BoardPiece::SQUARE_SIZE - size.y) / 2 });
}
sf::Sprite* Pawn::getSprite() {
	return sprite;
}

const char* Pawn::getName() {
	return "PAWN";
}

bool Pawn::canMove(BoardPiece* bp, Entity* board) {
	bool white = false;
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = bp->getId();
	if (getColor() == sf::Color::White) {
		white = true;
	}
	int dist = destination.y - current.y;
	if (!firstMove && abs(dist) > 1) return false;
	if (white && current.x == destination.x && dist > 0 && dist < 3)
	{
		firstMove = false;
		return true;
	}
	else if (!white && current.x == destination.x && dist < 0 && dist > -3)
	{
		firstMove = false;
		return true;
	}
	return false;
}

bool Pawn::canBeat(Figure* fig, Entity* board) {
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = fig->getPiece()->getId();
	bool isWhite = getColor() == sf::Color::White;

	if (isWhite && (current.y + 1) == destination.y &&
		((current.x + 1) == destination.x || (current.x - 1) == destination.x)) {
		return true;
	}
	else if (!isWhite && (current.y - 1) == destination.y &&
		((current.x + 1) == destination.x || (current.x - 1) == destination.x)) {
		return true;
	}
	return false;
}
