#include <iostream>
#include <cstdlib> // For the generator function
#include <ctime> // For getting the current time

using namespace std;


int main()
{
	// W3Schools way

	// Seeding the generator
	srand(time(0));

	// Generating a random int between 0 and 100
	int randomNum = rand() % 101;

	cout << randomNum;

	return 0;
}