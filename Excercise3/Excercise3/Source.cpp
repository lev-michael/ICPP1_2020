#include "Game.h"
#include <iostream>

int main(int argc, char** argv) {
	Game* game = new Game(10);
	Object* o = new Object(1);
	o->SetX(10);
	o->SetY(5);
	StaticObject* so = new StaticObject(2, BarrierType::Rock);
	so->SetX(10);
	so->SetY(10);
	MovingObject* mo = new MovingObject(3, 1.3);
	mo->SetX(1);
	mo->SetY(4);
	Monster* monster = new Monster(4, 2.2, 99, 100);
	monster->SetX(8);
	monster->SetY(3);

	game->insertObject(o);
	game->insertObject(so);
	game->insertObject(mo);
	game->insertObject(monster);

	int* idStatObj = game->findIdOfStaticObjects(0, 20, 0, 20);
	MovingObject** movingObj1 = game->findMovingObjectsInArea(5, 5, 10);
	MovingObject** movingObj2 = game->findMovingObjectsInArea(5, 5, 10, 0, 1);


	return 0;
}