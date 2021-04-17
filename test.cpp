#include "Square.h"
#include "Circle.h"
#include "Game.h"
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	cout << "========= Testing Shape classes =========" << endl;
	
	cout << "========= Square =========" << endl;
	Square sq(10, 4, 2);
	cout << sq << endl;
	cout << "Moving shape by 1,1" << endl;
	sq.moveShape(1, 1);
	cout << sq << endl;

	
	cout << "========= Circle  =========" << endl;
	Circle cl(10, 3, 3);
	cout << cl << endl;
	cout << "Moving shape by -1, -3" << endl;
	cl.moveShape(-1, -3);
	cout << cl << endl;
	
	cout << "========= Testing Shape collisions =========" << endl;
	
	cout << "========= Two Squares =========" << endl;
	Square s1(2, 0, 0);
	Square s2(2, 2, 2);
	cout << "(1) Expected: 1   Got: " << s1.isCollision(s2) << endl;
	s2.moveShape(1, 0);
	cout << "(2) Expected: 0   Got: " << s1.isCollision(s2) << endl;
	
	cout << "========= Two Circles =========" << endl;
	Circle c1(2, 0, 0);
	Circle c2(2, 3, 0);
	cout << "(3) Expected: 0   Got: " << c1.isCollision(c2) << endl;
	c2.moveShape(-1, 0);
	cout << "(4) Expected: 1   Got: " << c1.isCollision(c2) << endl;
	
	cout << "========= Circle - Square =========" << endl;

	Circle c3(2, 0, 0);
	Square s3(2, 2, 0);
	cout << "(5) Expected: 1   Got: " << c3.isCollision(s3) << endl;
	s3.moveShape(1, 0);
	cout << "(6) Expected: 0   Got: " << c3.isCollision(s3) << endl;
	s3.moveShape(-1, 0);

	cout << "========= Square - Circle =========" << endl;
	cout << "(7) Expected: 1   Got: " << s3.isCollision(c3) << endl;
	s3.moveShape(1, 0);
	cout << "(6) Expected: 0   Got: " << s3.isCollision(c3) << endl;


	cout << "========= Testing Game class =========" << endl;
	Game game(30, 10, 10, 6);
	
	// Uncomment the line below to test the game class.
	//game.startGame();
	// To slow down the console output change the sleep time in the Game.cpp startGame() method	
}
