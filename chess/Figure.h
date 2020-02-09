#pragma once
#include "Entity.h"
class Figure :
	public Entity
{
private:
	sf::Sprite *sprite;
public:
	Figure(sf::Texture);
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

