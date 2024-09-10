#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    // // Variables
    // int age = 42;
    // string name = "jim";

    // cout << age << " is " << sizeof(age) << " bytes " << endl;


    string pass = "password123";
    string userPassword;
    

    cout << "Enter your password :";
    getline(cin, userPassword);

    if (userPassword == pass)
    {
        cout << "Password is correct" << endl;
    }
    else
    {
        cout << "Password is incorrect" << endl;
    }
    
    string ageInput;
    int age;
    cout << "how old are you?";
    getline(cin, ageInput); // Get a string
    age = stoi(ageInput);

    return 0;


}
