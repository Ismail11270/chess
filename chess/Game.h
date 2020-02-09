#pragma 
#include "SFML/Graphics.hpp"
#include "Background.h"
#include "Figure.h"
#include <string>

class Game
{
private:
	sf::RenderWindow *window;
	Background *background;
	void display();
	Figure *fig;
public:
	Game(sf::Vector2f, std::string);
	void start();
	~Game() {
		delete window;
		delete background;
	}
};

