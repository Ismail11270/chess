#include "Board.h"
#include "Pawn.h"

Board::Board(sf::Vector2f intial_pos) {
	bool white = true;
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			sf::Color color;
			if (white) {
				color = sf::Color(76, 76, 79);
			}
			else {
				color = sf::Color(156, 89, 22);
			}
			white = !white;
			boardPieces[i][j] = new BoardPiece(color, { (float)i,(float)j });
		}
		white = !white;
	}
	reset();
}


void Board::draw(sf::RenderTarget& targ, sf::RenderStates states) const {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			boardPieces[i][j]->draw(targ, states);
		}
	}
	for (int i = 0; i < whiteFigures.size(); i++) {
		whiteFigures.at(i)->draw(targ, states);
	}
	for (int i = 0; i < blackFigures.size(); i++) {
		blackFigures.at(i)->draw(targ, states);
	}
}

BoardPiece* Board::getBoardPiece(int i, int j) {
	return boardPieces[i][j];
}

Figure* Board::getFigureFromPosition(sf::Vector2f pos) {
	Figure *fig;
	for (int i = 0; i < whiteFigures.size(); i++) {
		fig = whiteFigures.at(i);
		if (fig->getPiece()->getSquare()->getGlobalBounds().contains(pos)) {
			return fig;
		}
	}
	for (int i = 0; i < blackFigures.size(); i++) {
		fig = blackFigures.at(i);
		if (fig->getPiece()->getSquare()->getGlobalBounds().contains(pos)) {
			return fig;
		}
	}
	return NULL;
}
BoardPiece* Board::getBoardPieceFromPosition(sf::Vector2f pos) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (boardPieces[i][j]->getSquare()->getGlobalBounds().contains(pos)) {
				return boardPieces[i][j];
			}
		}
	}
	return NULL;
}

void Board::reset() {
	whiteFigures.clear();
	blackFigures.clear();
	//adding pawns to the board
	for (int i = 0; i < 8; i++) {
		whiteFigures.push_back(new Pawn(boardPieces[i][1], sf::Color::White));
		boardPieces[i][1]->setEmpty(false);
		blackFigures.push_back(new Pawn(boardPieces[i][6], sf::Color::Black));
		boardPieces[i][6]->setEmpty(false);
	}
}

void Board::clearSelelctedFig() {
	selected = false;
	selectedFig->getPiece()->resetColor();
	selectedFig = NULL;
	
}

void Board::removeFigure(Figure* fig) {
	if (fig->getColor() == sf::Color::White) {
		for (int i = 0; i < whiteFigures.size(); i++) {
			if (whiteFigures.at(i) == fig) {
				whiteFigures.erase(whiteFigures.begin() + i);
			}
		}
	}
	else {
		for (int i = 0; i < blackFigures.size(); i++) {
			if (blackFigures.at(i) == fig) {
				blackFigures.erase(blackFigures.begin() + i);
			}
		}
	}
}
