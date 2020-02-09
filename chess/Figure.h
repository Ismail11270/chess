#pragma once
#include "BoardPiece.h"

class Figure :
	public Entity
{
private:
	BoardPiece *piece;
	sf::Color color;
public:
	Figure( BoardPiece*, sf::Color);
	virtual void moveTo(BoardPiece) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setPosition(BoardPiece) = 0;
	sf::Color getColor();
	virtual sf::Sprite* getSprite() = 0;
	BoardPiece* getPiece() {
		return piece;
	}
};

