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
	Figure* selectedFig = NULL;
	bool selected = false;
public:
	Board(sf::Vector2f);
	BoardPiece** getPieces() { return *boardPieces; }
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	BoardPiece* getBoardPiece(int, int);
	void reset();
	std::vector<Figure*> getWhiteFigures() {
		return whiteFigures;
	}

	std::vector<Figure*> getBlackFigures() {
		return blackFigures;
	}

	Figure* getFigureFromPosition(sf::Vector2f);
	BoardPiece* getBoardPieceFromPosition(sf::Vector2f);
	bool hasSelected() { return selected; }
	void setSelectedFig(Figure* fig) { selectedFig = fig; selected = true; }
	Figure* getSelectedFig() { return selectedFig; }
	void clearSelelctedFig();
	void removeFigure(Figure*);

};

