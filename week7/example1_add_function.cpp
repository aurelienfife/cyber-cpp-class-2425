#include <iostream>
#include <string>

using namespace std;

// Default value for message provided
int input_int(string message = "Enter an integer please: ")
{
    string num_input;
    cout << message;
    getline(cin, num_input);
    return stoi(num_input);
}



void add_and_print(int a, int b)
{
    cout << "Total: " << a + b << endl;
}

void add_and_print(double a, double b)
{
    cout << "Total: " << a + b << endl;
}



int main()
{

    // Example 1. using our function for integer
    int num1 = input_int("Enter first number");
    int num2 = input_int("Enter second number");

    add_and_print(num1, num2);

    // Example 2. - just to illustrate empty brackets
    int num3 = input_int();

    // Example 3. - Demo of overloads
    add_and_print(7,8);
    add_and_print(8.7, 6.5);

    return 0;
}