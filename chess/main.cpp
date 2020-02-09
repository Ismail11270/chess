#include "SFML/Graphics.hpp"
#include "Background.h"
#include "Game.h"

#define WINDOW_SIZE_X 800
#define WINDOW_SIZE_Y 800

int main() {
	Game game({ WINDOW_SIZE_X,WINDOW_SIZE_Y }, "chess");
	game.start();
}