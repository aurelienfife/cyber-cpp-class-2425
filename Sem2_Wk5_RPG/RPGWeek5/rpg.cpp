#include <iostream>
#include <cstdlib> // For the generator function
#include <ctime> // For getting the current time
#include <memory> // For smart pointers
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





// Character base class - contains the inner data
// and access methods
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
    virtual void attack(shared_ptr<Character> adversary) { }
    virtual void receiveDamage(int damage) { }
};

// Derivative classes: actual characters in the game
class Knight : public Character
{

    RandomNumberGenerator r;

public:
    // New constructor
    Knight(const string& _name) : Character(_name, 100, 100) { }

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

    auto k = make_shared<Knight>("Curtis");
    auto t = make_shared<Troll>("Stewart");

    // Test code
    //cout << k->getName() << " " << k->getHealth() << endl;

    bool death = false;
    // Test loop
    for(int i = 0; i < 10; i++)
    {
        // Test knight attacking itself
        k->attack(t);
        t->attack(k);
        // Display new HP
        cout << k->getHealth() << endl;
        cout << k->getHealth() << endl;

        
        if (k->getHealth() <= 0)
        {
            cout << k->getName() << " is dead." << endl;
            death = true;
        }
        if (t->getHealth() <= 0)
        {
            cout << t->getName() << " is dead." << endl;
            death = true;
        }
        if (death)
            break;

        Sleep(100);
    }

    return 0;
}
