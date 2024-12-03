#include <iostream>

using namespace std;

// Put Hello World! in a class
class HelloWorld
{
    // Data in the class, private
    string hello = "Hello, World!";
    // Public interface of the class
    // i.e. functions designed to interact
public:
    void display()
    {
        cout << hello << endl;
    }
};

int main() {

    HelloWorld h;
    h.display();
    
    return 0;
}