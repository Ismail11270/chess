#pragma once
#include "Figure.h"
#define WHITE_PAWN "res/pawn_white.png"
#define BLACK_PAWN "res/pawn_black.png"

class Pawn :
	public Figure
{
public:
	void moveTo(BoardPiece*) override;
	Pawn(BoardPiece*,sf::Color);
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	bool canMove(BoardPiece*) override;
	bool canBeat(Figure*) override;
private:
	sf::Sprite *sprite;
	sf::Texture *texture;
	sf::Vector2f getPosition() override;
	void setPosition(BoardPiece) override;
	sf::Sprite* getSprite() override;
	const char* getName() override;
};

