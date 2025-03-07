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

/*
    The new classes we will write need to be located underneath the random number generator
    but above the main function - otherwise it won't compile
*/

// Character base class - contains the inner data
// and access methods
class Character
{
    string name;
    int health, strength;
    bool npc;   // Is it an NPC?

public:
    // Constructor: initialises the state of the object
    Character(const string& _name, int _health, int _strength)
    {
        name = _name;
        health = _health;
        strength = _strength;
        npc = false;
    }

    // Getters - allow read access to private variables
    string getName() { return name; }
    int getHealth() { return health; }
    int getStrength() { return strength; }
    bool isNpc() { return npc; }

    // Combat methods
    void attack(const Character& adversary) { }
    void receiveDamage(int damage) { }
};

// Derivative classes: actual characters in the game


/*
    Write the classes above this line
*/


int main()
{


    return 0;
}
