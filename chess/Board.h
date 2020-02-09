#pragma once
#include "Entity.h"
#include <vector>
#include "BoardPiece.h"
#include "Figure.h"

class Board :
	public Entity
{
private:
	BoardPiece* boardPieces[8][8];
	std::vector<Figure*> whiteFigures;
	std::vector<Figure*> blackFigures;
public:
	Board(sf::Vector2f);
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	BoardPiece* getBoardPiece(int, int);
	void reset();
	std::vector<Figure*> getWhiteFigures() {
		return whiteFigures;
	}

	std::vector<Figure*> getBlackFigures() {
		return blackFigures;
	}
};

