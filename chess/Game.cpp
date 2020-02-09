#include "Game.h"

Game::Game(sf::Vector2f size, std::string title) {
	window = new sf::RenderWindow(sf::VideoMode(size.x,size.y), title, sf::Style::Default);
	background = new Background(sf::Color::Black, size);
}

void Game::start() {
	while (1) {
		sf::Texture texture;
		texture.loadFromFile("res/heal.png");
		fig = new Figure(texture);
		display();
	}
}


void Game::display() {
	window->clear();
	window->draw(*background);
	window->draw(*fig);
	window->display();
}

