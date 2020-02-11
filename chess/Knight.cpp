#include "Knight.h"

Knight::Knight(BoardPiece* piece, sf::Color color) :
	Figure(piece, color, sf::Color::White == color ? WHITE_KNIGHT : BLACK_KNIGHT) {
}

const char* Knight::getName() {
	return "KNIGHT";
}

bool Knight::canMove(BoardPiece* bp, Entity* brd) {
	return false;
}

bool Knight::canBeat(Figure* fig, Entity* brd) {
	return false;
}