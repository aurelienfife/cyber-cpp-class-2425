#include <iostream>
#include <vector>
#include <memory>

using namespace std;


// This is class called program
// It's used to wrap (encapsulate) the program code in a common interface:
// - the run() function
// - getName() giving the name for our menu

class Program {
	string name;
public:
	// Constructor -> purpose is initialise stuff at creation
	Program(const string& _name)
	{
		name = _name;
	}

	string getName() { return name;  }

	virtual void run() = 0; // "pure virtual" function
	// This prevents creating a "Program" object by mistake
	// By marking it as never to created
};

// Inherited classes: program 1, 2, 3
// Taking the class above as is + specifying a name
// and content for the run() function for each program

class Program1: public Program {
public:
	Program1() : Program("Select program 1") {}

	void run()
	{
		cout << "This is program 1" << endl;
	}
};

class Program2 : public Program {
public:
	Program2() : Program("Select program 2") {}

	void run()
	{
		cout << "This is program 2" << endl;
	}
};

class Program3 : public Program {
public:
	Program3() : Program("Select program 3") {}

	void run()
	{
		cout << "This is program 3" << endl;
	}
};


int main()
{
	// First create a list of our 3 programs
	// They need to be shared pointers (shared_ptr<>)
	vector<shared_ptr<Program>> programList;

	// Create 3 programs
	auto p1 = make_shared<Program1>();
	auto p2 = make_shared<Program2>();
	auto p3 = make_shared<Program3>();

	// Add to the vector
	programList.push_back(p1);
	programList.push_back(p2);
	programList.push_back(p3);


	int choice;

	for (int i = 0; i < programList.size(); i++)
	{
		auto p = programList[i];
		cout << i << " " << p->getName() << endl;
	}

	cin >> choice;
	// Running the code -> just call "run"
	programList[choice]->run();

	return 0;
}