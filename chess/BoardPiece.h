#pragma once
#include "Entity.h"

class BoardPiece : public Entity
{
private:
	sf::Vector2f location;
	sf::RectangleShape square;
	sf::Color color;
public:
	static const int SQUARE_SIZE = 50;
	BoardPiece(sf::Color color, sf::Vector2f loc) : color(color) {
		square.setFillColor(color);
		square.setSize({ (float)SQUARE_SIZE,(float)SQUARE_SIZE });
		location = { SQUARE_SIZE * loc.x, SQUARE_SIZE * loc.y };
		square.setPosition(location);
	}
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	sf::Vector2f getPosition();
};

