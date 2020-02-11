#include "Bishop.h"

Bishop::Bishop(BoardPiece* piece, sf::Color color) :
	Figure(piece, color, sf::Color::White == color ? WHITE_BISHOP : BLACK_BISHOP) {
}

const char* Bishop::getName() {
	return "BISHOP";
}

bool Bishop::canMove(BoardPiece* bp, Entity* brd) {
	return false;
}

bool Bishop::canBeat(Figure* fig, Entity* brd) {
	return false;
}