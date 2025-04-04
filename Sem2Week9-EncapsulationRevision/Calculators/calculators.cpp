#include <iostream>

using namespace std;


class Addition {

private:
	int num1, num2;
public:
	// Constructor function
	Addition(int a, int b)
	{
		// When object is created, 
		// Takes a and b, saves them into num1 and num2
		num1 = a;
		num2 = b;
	}

	// Don't want num1 and num2 to change after creation
	// But we may want to have read-only access to them
	// So we create two getters
	int getNum1() { return num1;  }
	int getNum2() { return num2;  }

	// The actual code
	void calculate()
	{
		cout << "adding: " << num1 + num2 << endl;
	}

};         //  Note the semicolon here


int main()
{

	Addition a(7, 8);
	a.calculate();

	Addition b(5, 6);
	b.calculate();


	return 0;
}

