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

// Pass by value (default)
void increase(int num)
{
    num += 2;
    cout << num << endl;
}

// Note the & symbol -> reference to the original
void increase_by_reference(int& num) 
{
    num += 2;
    cout << num << endl;
}

// Function manipulating a string
// To avoid duplicating complex data unnecessarily (strings, arrays etc)
// You can pass a read-only reference to the original
string add_exclamation_marks(const string& message)
{
    string newString = "!!!!" + message + "!!!!";
    return newString;
}

int main()
{

    // When passing a parameter, you don't work on the actual
    // variable, but on a new variable that is a copy of the original
    int a = 8;
    cout << a << endl;
    increase(a);
    cout << a << endl;

    cout << "----------" << endl;

    // You can, however, pass a REFERENCE to the original
    // Passing by reference
    a = 8;
    cout << a << endl;
    increase_by_reference(a);
    cout << a << endl;

    // Create a string
    string quote = "I'll be back.";
    cout << add_exclamation_marks(quote) << endl;



    return 0;
}