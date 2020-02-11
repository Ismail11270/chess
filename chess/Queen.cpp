#include "Queen.h"

Queen::Queen(BoardPiece* piece, sf::Color color) :
	Figure(piece, color, sf::Color::White == color ? WHITE_QUEEN : BLACK_QUEEN) {
}

const char* Queen::getName() {
	return "QUEEN";
}

bool Queen::canMove(BoardPiece* bp, Entity* brd) {
	return false;
}

bool Queen::canBeat(Figure* fig, Entity* brd) {
	return false;
}