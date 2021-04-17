#ifndef GAME_H
#define GAME_H

#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include <list>
#include <iterator> 
using namespace std;

class Game {
public:
	Game(unsigned int numOfShapes, int gridMaxX, int gridMaxY, int maxLength);
	void generateShapes();
	void showList();
	void addShapeToList(Shape& s);
	void startGame();
	void moveAllShapes();

protected:
	list <Shape*> shapes;
	const int GRID_MAX_X;
	const int GRID_MAX_Y;
	const int MAX_LEN;
	int numOfShapes;

};



#endif
#pragma once