#pragma once
#include <string>

using namespace std;

class Character
{
	// Private data
	string name;
	int healthPoints;

public:
	Character(const string& _name, int _healthPoints);

	string getName();
};

