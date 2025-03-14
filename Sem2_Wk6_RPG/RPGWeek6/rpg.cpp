#include <iostream>
#include <cstdlib> // For the generator function
#include <ctime> // For getting the current time
#include <memory> // For smart pointers
#include <vector>
#include <Windows.h>

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
// This class is abstract: it cannot be allocated as an object
// Unless it is via the inheritance method (Troll, Knight etc)

class Character
{
    // Protected -> private except for inheritance purposes
protected:

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
    // updated to receive a pointer instead 
    virtual void attack(shared_ptr<Character> adversary) = 0; // Prevents creation of Character object
    virtual void receiveDamage(int damage) = 0; 
};

// Derivative classes: actual characters in the game
class Knight : public Character
{

    RandomNumberGenerator r;

public:
    // New constructor
    Knight(const string& _name) : Character(_name, 100, 100) {}

    // Overload of attack
    void attack(shared_ptr<Character> adversary)
    {
        int diceRoll = r.generate(strength + 1);

        //cout << "dice roll result " << diceRoll << endl;

        if (diceRoll < 50) { // Miss
            adversary->receiveDamage(0);
        }
        else
        {
            adversary->receiveDamage(diceRoll);
        }
    }

    // Damage received from attacker
    void receiveDamage(int damage)
    {
        //cout << damage << endl;
        // Remove 25% of the actual damage from HP
        health -= damage / 4;
    }
};

// Derivative classes: actual characters in the game
class Troll : public Character
{

    RandomNumberGenerator r;

public:
    // New constructor
    Troll(const string& _name) : Character(_name, 100, 100)
    {
        npc = true;
    }

    // Overload of attack
    void attack(shared_ptr<Character> adversary)
    {
        int diceRoll = r.generate(strength + 1);

        //cout << "dice roll result " << diceRoll << endl;

        if (diceRoll < 50) { // Miss
            adversary->receiveDamage(0);
        }
        else
        {
            adversary->receiveDamage(diceRoll);
        }
    }

    // Damage received from attacker
    void receiveDamage(int damage)
    {
        //cout << damage << endl;
        // Remove 25% of the actual damage from HP
        health -= damage / 4;
    }
};


/*
    Write the classes above this line
*/


int main()
{
    // List of players
    // These are pointers to generic characters
    vector<shared_ptr<Character>> characterList;

    // For now I create 3 Knights, but the menu could include
    // The choice of character class
    for (int i = 0; i < 3; i++)
    {
        string name;
        cout << "Name your next character: " << endl;
        cin >> name;

        // Create a new Knight with the chosen name
        auto c = make_shared<Knight>(name);

        // Add the Knight to the character list
        characterList.push_back(c);
    }

    // Create the Troll
    auto t = make_shared<Troll>("Keith");

    // Flag for when a character dies
    bool death = false;

    // The whole thing repeats until a character is killed
    while (!death)
    {
        // Every character attacks the troll and gets attacked back
        for (auto c : characterList)
        {
            // Character attacks troll
            c->attack(t);
            // Troll attacks character
            t->attack(c);
            cout << c->getName() << ": " << c->getHealth() << endl;
            cout << t->getName() << ": " << t->getHealth() << endl;

            if (c->getHealth() <= 0 || t->getHealth() <= 0)
            {
                death = true;
            }
        }
    }

    cout << "Game Over!" << endl;


    return 0;
}