#include <iostream>

using namespace std;

// Car class
// make, model, year, mileage

class Car
{
    // Private properties
    string *make, *model;
    int year, mileage;

public:
    // Constructor
    Car(string _make, string _model, int _year) {
        make = new string(_make);
        model = new string(_model);
        year = _year;
        mileage = 0;
    }

    // If needed, you need a destructor
    ~Car() {
        delete make;
        delete model;
    }

    // Public methods
    void drive(int miles) {
        mileage += miles; 
    }

    int getMileage() { return mileage; }
};

int main()
{
    // Car
    Car *tankar = new Car("Fiat", "500", 2016);

    // Array with different drives (mileages)
    int drives[5] = {32, 60, 200, 30, 59};

    for(int miles: drives) {
        tankar->drive(miles);
        cout << "The new mileage is: " << tankar->getMileage() << endl;
    }

    // Delete the object
    delete tankar;

    return 0;
}