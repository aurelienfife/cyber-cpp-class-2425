/* Example of inheritance */
#include <iostream>

using namespace std;

// Class vehicle, that will be inherited
class Vehicle 
{
    // Properties
    string make, model;
    int year, mileage;

public:
    Vehicle(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
        mileage = 0;
    }

    void drive(int miles) 
    {
        mileage += miles;
    }
};

int main()
{
    return 0;
}