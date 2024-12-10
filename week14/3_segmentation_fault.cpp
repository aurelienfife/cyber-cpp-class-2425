#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    // Pointer to a string
    string *name = new string();

    // Read the input
    cout << "What is your name?" << endl;
    getline(cin, *name);


    // Deallocate memory
    delete name;
    name = nullptr;

    // (attempt to) Print the name
    cout << *name << endl;

    return 0;
}