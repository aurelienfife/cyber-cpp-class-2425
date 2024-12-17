#include "character.h"

using namespace std;

Character::Character(const string& _name, int _healthPoints)
{
	name = _name;
	healthPoints = _healthPoints;
}

string Character::getName()
{
	return name;
}
