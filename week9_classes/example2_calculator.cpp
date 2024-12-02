#include <iostream>

using namespace std;

// Calculator: takes two integers
// And allows operations...
class Calculator {
    int a,b; // Private
public:
    // Classes have two special functions
    // The constructor
    // The destructor

    // Constructor: taking two ints
    Calculator(int _a, int _b) {
        a = _a;
        b = _b;
    }

    // Functions: make calculations
    int add() { return a + b; }
    int sub() { return a - b; }
    int mul() { return a * b; }
    int div() { return a / b; }

};

int main()
{
    // Create calculator objects
    Calculator c1(5,6);
    Calculator c2(7,8);
    Calculator c3(11,9);

    cout << c1.add() << endl;
    cout << c1.sub() << endl;
    cout << c1.mul() << endl;
    cout << c1.div() << endl;

    return 0;
}
