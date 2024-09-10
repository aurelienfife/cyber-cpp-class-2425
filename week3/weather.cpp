/*
    Weather Adviser: Write a program that suggests clothing 
    based on temperature input. For example, if the temperature
    is below 20°C, suggest a jacket.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Needing a string and an int for temperature
    string tempInput;
    int temperature;

    // Asking the question
    cout << "What is the temperature outside? " << endl;

    // Reading the input as a string and converting to int
    getline(cin, tempInput);
    temperature = stoi(tempInput);

    // Recommendations based on three options
    if (temperature <= 5) {
        cout << "You'll need a jumper big man" << endl;
    }
    else if (temperature <= 16) {
        cout << "You'll need a jaicket" << endl;
    }
    else {
        cout << "TAPS AFF!" << endl;
    }

    return 0;
}
