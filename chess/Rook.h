#pragma once
#include "Figure.h"
class Rook :
	public Figure
{
public:
	Rook(BoardPiece*, sf::Color);
	void moveTo(BoardPiece*) override;
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	bool canMove(BoardPiece*,Entity*) override;
	bool canBeat(Figure*, Entity*) override;
	sf::Vector2f getPosition() override;
	void setPosition(BoardPiece) override;
	sf::Sprite* getSprite() override;
	const char* getName() override;
private:
	sf::Sprite *sprite;
	sf::Texture *texture;
};

