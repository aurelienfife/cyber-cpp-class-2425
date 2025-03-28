#include <iostream>

using namespace std;

// Individual programs
void program1() {
	cout << "This is program 1" << endl;
}

void program2() {
	cout << "This is program 2" << endl;
}

void program3() {
	cout << "This is program 3" << endl;
}


void displayMenu() {

	int input; // 

	cout << "1 - Run program 1" << endl;
	cout << "2 - Run program 2" << endl;
	cout << "3 - Run program 3" << endl;
	cout << "Make your selection: ";
	// Read user selection (keyboard)
	cin >> input;

	switch (input)
	{
	case 1:
		program1();
		break;
	case 2:
		program2();
		break;
	case 3:
		program3();
		break;
	default:
		cout << "Command not recognised" << endl;
		break;
	}

}



int main()
{

	// Run the menu indefinitely
	while (true)
	{
		displayMenu();
	}

	return 0;
}