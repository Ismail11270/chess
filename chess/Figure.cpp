#include "Figure.h"
#include "Game.h"



Figure::Figure(BoardPiece* piece, sf::Color color) {
	this->piece = piece;
	this->color = color;
}

sf::Color Figure::getColor() {
	return color;
}


