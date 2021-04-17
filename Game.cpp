#include "Game.h"
#include <iostream>
#include <time.h>  
#include <thread>
#include <chrono>

Game::Game(unsigned int shapes, int gridX, int gridY, int maxLength) :
	numOfShapes(shapes),
	GRID_MAX_X(gridX),
	GRID_MAX_Y(gridY),
	MAX_LEN(maxLength)
{
	generateShapes();
}

void Game::addShapeToList(Shape& s) {
	shapes.push_back(&s);
}


bool compare(const Shape* s1, const Shape* s2) {
	if (s1->getPosX() < s2->getPosX())
		return true;
	else return false;
}

void Game::showList() {
	if (shapes.size() == 0) {
		cout << "Empty list" << endl;
		return;
	}

	list<Shape*>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); ++it) {
		cout << **it << " ";
	}
	cout << '\n';
}

void Game::generateShapes() {
	srand(time(NULL));
	for (int i = 0; i < numOfShapes; i++) {
		int sh = rand() % 2;
		int x = (rand() % (GRID_MAX_X*2)) - GRID_MAX_X;
		int y = (rand() % (GRID_MAX_Y*2)) - GRID_MAX_Y;
		int l = rand() % MAX_LEN + 1;
		if (sh == 0) {
			Circle *c = new Circle(l, x, y);
			this->shapes.push_back(c);
		}
		else {
			Square *s = new Square(l, x, y);
			this->shapes.push_back(s);
		}
	}
	this->shapes.sort(compare);
}

void Game::moveAllShapes() {
	list<Shape*>::iterator it;
	if (shapes.size() == 0) {
		cout << "No more shapes left..." << endl;
		return;
	}

	for (it = shapes.begin(); it != shapes.end(); ++it) {
		int moveX = rand() % 4;
		int moveY = rand() % 4;
		Shape* s = (*it);
		//cout << "moveX: " << moveX << endl;
		//cout << "moveY: " << moveY << endl;
		s->moveShape(moveX, moveY);

		if (s->getPosX() > GRID_MAX_X)
			s->setPosX(-GRID_MAX_X);
		if (s->getPosX() < -GRID_MAX_X)
			s->setPosX(GRID_MAX_X);
		if (s->getPosY() > GRID_MAX_Y)
			s->setPosY(-GRID_MAX_Y);
		if (s->getPosY() < -GRID_MAX_Y)
			s->setPosY(GRID_MAX_Y);
	}
}


void Game::startGame() {
	while(shapes.size() > 1){
		list<Shape*>::iterator next, current;
		current = shapes.begin();
		next = shapes.begin();
		next++;

		cout << endl << "=== Current shapes list: " << '(' << shapes.size() << " shapes)" << " === " << endl;
		showList();
		cout << "===                      === " << endl << endl;

		for (next; next != shapes.end(); ++next) {
			Shape* s1 = (*current);
			Shape* s2 = (*next);

			double shapeHalfLenghtsSum = (double)s1->getLength() / 2 + (double)s2->getLength() / 2;
			int distanceX = abs(s2->getPosX() - s1->getPosX());
			int distanceY = abs(s2->getPosY() - s1->getPosY());

			cout << *s1 << "    --- Comparing ---    " << *s2 << endl;
			cout << "distanceX:" << distanceX << ' ';
			cout << "distanceY:" << distanceY << ' ';
			cout << "shapelenghts:" << shapeHalfLenghtsSum << endl;
		
			// Are shapes close enough on X and Y axis to collide?
			if (shapeHalfLenghtsSum >= distanceX && shapeHalfLenghtsSum >= distanceY) {
				cout << "Checking collision..." << s1->isCollision(*s2) << endl;
				if (s1->isCollision(*s2)) {
					Shape *ptr1 = (*next);
					Shape* ptr2 = (*current);
					cout << "Collision found!" << endl;
					next = shapes.erase(next);
					current = shapes.erase(current); // points at next
					delete ptr1;
					delete ptr2;

					if (next == shapes.end()) // went through the list and deleted last shape
						break;
					if (current != shapes.begin())
						current--;

					cout << endl <<  "=== List after collision: === " << endl;
					showList();
				}
			}
			else {
				current++;
				next = current;
			}
		}
		cout << "Moving all shapes..." << endl;
		moveAllShapes();
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Increase to slow down the console output
	}
}