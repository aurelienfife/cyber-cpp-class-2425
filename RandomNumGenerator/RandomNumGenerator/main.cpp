#include <iostream>
#include <cstdlib> // For the generator function
#include <ctime> // For getting the current time

using namespace std;

// Class "RandomNumberGenerator"
// Think of it as a lego brick you can use several times in several projects
class RandomNumberGenerator
{
	// Attributes
	int lastGeneratedNumber;

public:
	// Constructor -> seeding the generator
	RandomNumberGenerator() {
		lastGeneratedNumber = 0;
		srand(time(0));
	}
	// Function -> generates a random int between 0 (incl)
	// and limit (excl)
	int generate(int limit) {
		int randomNum = rand() % limit;
		// Save
		lastGeneratedNumber = randomNum;

		return randomNum;
	}
	int getLastGeneratedNumber()
	{
		return lastGeneratedNumber;
	}
};

int main()
{
	// Create a random number generator

	// Create a generator like you would create any variable
	RandomNumberGenerator g;

	// Create a few numbers
	for (int i = 0; i < 5; i++) {
		cout << g.generate(101) << endl;
	}

	cout << "The last generated number was: " << g.getLastGeneratedNumber() << endl;

	return 0;
}