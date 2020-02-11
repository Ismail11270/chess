#include "King.h"

King::King(BoardPiece* piece, sf::Color color) : 
	Figure(piece, color, sf::Color::White == color ? WHITE_KING : BLACK_KING) {
}

const char* King::getName() {
	return "KING";
}

bool King::canMove(BoardPiece* piece, Entity* brd) {
	return false;
}

bool King::canBeat(Figure* fig, Entity* brd) {
	return false;
}