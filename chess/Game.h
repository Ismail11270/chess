#pragma 
#include "SFML/Graphics.hpp"
#include "Background.h"
#include "Figure.h"
#include <string>
#include "Board.h"

class Game
{
private:
	sf::RenderWindow *window;
	Background *background;
	void display();
	sf::Sprite sp;
	Board *board;
	bool onMouseClick(sf::Event);
	bool isWhiteTurn;
public:
	Game(sf::Vector2f, std::string);
	void start();
	~Game() {
		delete window;
		delete background;
		delete board;
	}
};

