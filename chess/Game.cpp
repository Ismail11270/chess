#include "Game.h"
#include "Pawn.h"
#include <iostream>

Game::Game(sf::Vector2f size, std::string title) {
	window = new sf::RenderWindow(sf::VideoMode(size.x,size.y), title, sf::Style::Titlebar | sf::Style::Close);
	background = new Background(sf::Color::Black, size);
	board = new Board(sf::Vector2f(0,0));
	sf::err().rdbuf(NULL);
	isWhiteTurn = true;
}

void Game::start() {
	while (window->isOpen()) {
		sf::Event event;
		
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				onMouseClick(event);
			}
			if (event.type == sf::Event::Resized) {

			}
		}
		
		display();
	}
}

bool Game::onMouseClick(sf::Event event) {
	sf::Vector2f pos({ (float)event.mouseButton.x,(float)event.mouseButton.y });
	//select a move
	if (board->hasSelected()) {
		Figure* figure = board->getSelectedFig();
		BoardPiece* bp = board->getBoardPieceFromPosition(pos);
		if (figure->getPiece() == bp) {
			board->clearSelelctedFig();
			std::cout << "Figure deselected\n";
		}
		else if (bp->isEmpty() && figure->canMove(bp,board)) {
			figure->moveTo(bp);
			isWhiteTurn = !isWhiteTurn;
			board->clearSelelctedFig();
			const char* color = figure->getColor() == sf::Color::White ? "White " : "Black ";
			std::cout << color << figure->getName() << " moved\n";
		}
		else if (!bp->isEmpty()) {
			Figure *destFig = board->getFigureFromPosition(bp->getPosition());
			if (figure->canBeat(destFig,board)) {
				board->removeFigure(destFig);
				figure->moveTo(destFig->getPiece());
				isWhiteTurn = !isWhiteTurn;
				board->clearSelelctedFig();
			}
		}
		
	} 
	//select a figure
	else {
		Figure *fig = board->getFigureFromPosition(pos);
		if (fig != NULL) {
			if (fig->getColor() == sf::Color::White) {
				if (isWhiteTurn) {
					fig->getPiece()->getSquare()->setFillColor(sf::Color::Red);
					board->setSelectedFig(fig);
					const char* color = fig->getColor() == sf::Color::White ? "White " : "Black ";
					std::cout << color << fig->getName() << " selected\n";
				}
			}
			else if (fig->getColor() == sf::Color::Black) {
				if (!isWhiteTurn) {
					fig->getPiece()->getSquare()->setFillColor(sf::Color::Red);
					board->setSelectedFig(fig);
					const char* color = fig->getColor() == sf::Color::White ? "White " : "Black ";
					std::cout << color << fig->getName() << " selected\n";
				}
			}
			return true;
		}
		else {
			std::cout << "No figure selected!" << std::endl;

			return false;
		}
	}
}

void Game::display() {
	window->clear();
	window->draw(*background);
	window->draw(*board);
	window->display();
}


