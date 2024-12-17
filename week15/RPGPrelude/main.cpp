#include <iostream>
#include <memory>
#include "character.h"

using namespace std;

int main()
{
	cout << "test" << endl;

	auto c = make_unique<Character>("Stewart", 66);

	cout << c->getName() << endl;

	return 0;
}
