#include "Rook.h"
#include <iostream>
#include "Board.h"

Rook::Rook(BoardPiece* piece, sf::Color color) : Figure(piece, color) {
	this->texture = new sf::Texture();
	this->texture->loadFromFile("res/rook_white.png");
	sprite = new sf::Sprite(*this->texture);
	sprite->setColor(color);
	sprite->setScale({ 0.125f,0.125f });
	setPosition(*getPiece());
}

void Rook::moveTo(BoardPiece *piece) {
	getPiece()->resetColor();
	getPiece()->setEmpty(true);
	setPosition(*piece);
	setPiece(piece);
	getPiece()->setEmpty(false);
}


void Rook::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*sprite, states);
}

sf::Vector2f Rook::getPosition() {
	return sprite->getPosition();
}


void Rook::setPosition(BoardPiece p) {
	sf::Vector2f pos = p.getPosition();
	sf::Vector2f size(sprite->getTextureRect().width * sprite->getScale().x, sprite->getTextureRect().height * sprite->getScale().y);
	sprite->setPosition({ pos.x + (BoardPiece::SQUARE_SIZE - size.x) / 2, pos.y + (BoardPiece::SQUARE_SIZE - size.y) / 2 });
}
sf::Sprite* Rook::getSprite() {
	return sprite;
}

const char* Rook::getName() {
	return "ROOK";
}

bool Rook::canMove(BoardPiece* bp,Entity* b) {
	bool white = getColor() == sf::Color::White;
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = bp->getId();
	Board *board = dynamic_cast<Board*>(b);
	//legal rook move
	if (current.x == destination.x ) {
		//next check for obstacles on the way
		int i = current.y > destination.y ? destination.y : current.y;
		int max = current.y > destination.y ? current.y : destination.y;
		i++;
		for (i; i < max; i++) {
			if (!board->getBoardPiece(current.x,i)->isEmpty()) {
				return false;
			}
		}
		return true;
	}
	else if (current.y == destination.y) {
		//next check for obstacles on the way
		int i = current.x > destination.x ? destination.x : current.x;
		int max = current.x > destination.x ? current.x : destination.x;
		i++;
		for (i; i < max - 1; i++) {
			if (!board->getBoardPiece(i,current.y)->isEmpty()) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Rook::canBeat(Figure* fig, Entity* b) {
	if (this->getColor() == fig->getColor()) return false;
	Board* board = dynamic_cast<Board*>(b);
	if (canMove(fig->getPiece(),board)) {
		return true;
	}
	return false;
}
