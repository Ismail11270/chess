#include "Game.h"
#include "Pawn.h"

Game::Game(sf::Vector2f size, std::string title) {
	window = new sf::RenderWindow(sf::VideoMode(size.x,size.y), title, sf::Style::Default);
	background = new Background(sf::Color::Black, size);
	board = new Board(sf::Vector2f(0,0));
	
}

void Game::start() {
	while (window->isOpen()) {
		sf::Event event;
		
		display();
	}
}


void Game::display() {
	window->clear();
	window->draw(*background);
	window->draw(*board);
	window->display();
}

