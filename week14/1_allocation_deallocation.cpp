#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Pointer to a string
    string *name;

    // Allocate the memory
    name = new string();

    // Act with the pointer normally
    cout << "What is your name?" << endl;
    cin >> *name;

    cout << "Hello " << *name << endl;

    // When no longer needed, clear the memory
    delete name;

    return 0;
}