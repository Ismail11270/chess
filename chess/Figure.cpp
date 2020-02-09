#include "Figure.h"

Figure::Figure(sf::Texture texture) {
	sprite = new sf::Sprite(texture);
	sprite->setPosition(400, 400);
}

void Figure::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*sprite);
}
