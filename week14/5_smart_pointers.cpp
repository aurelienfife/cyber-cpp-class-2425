#include <iostream>
#include <memory>

using namespace std;

// Car class
// make, model, year, mileage

class Car
{
    // Private properties
    shared_ptr<string> make, model;
    int year, mileage;

public:
    // Constructor
    Car(string _make, string _model, int _year) {
        make = make_shared<string>(_make);
        model = make_shared<string>(_model);
        year = _year;
        mileage = 0;
    }

    // Public methods
    void drive(int miles) {
        mileage += miles; 
    }

    int getMileage() { return mileage; }
};

int main()
{

    auto tankar = make_unique<Car>("Fiat", "500", 2016);
    // Car
    // Car tankar("Fiat", "500", 2016);

    // Array with different drives (mileages)
    int drives[5] = {32, 60, 200, 30, 59};

    for(int miles: drives) {
        tankar->drive(miles);
        cout << "The new mileage is: " << tankar->getMileage() << endl;
    }

    return 0;
}