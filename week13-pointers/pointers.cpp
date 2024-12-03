#include <iostream>

using namespace std;

int main() {

    // Normal variable
    int value = 3122024;
    // Pointer
    int* address = nullptr;
    address = &value; // Set the pointer to address of value

    // Showing the value and the address
    cout << value << endl;
    cout << address << endl;

    // Using operators (referencing, dereferencing)
    cout << &value << endl;
    cout << *address << endl;

    

    return 0;
}