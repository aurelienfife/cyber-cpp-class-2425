/* Example of inheritance */
#include <iostream>

using namespace std;

// Class vehicle, that will be inherited
class Vehicle
{
protected: // -> private but accessible in inherited mode
    // Properties
    string make, model;
    int year, mileage;

public:
    Vehicle(string _make, string _model, int _year)
    {
        make = _make;
        model = _model;
        year = _year;
        mileage = 0;
    }

    void drive(int miles)
    {
        mileage += miles;
    }

    void reverse(int miles)
    {
        mileage += miles;
    }

    int getMileage() { return mileage; }
    string getMake() { return make; }
    string getModel() { return model; }
};

class Car: public Vehicle
{
    // Properties specific to Car
    bool convertible;

public:
    // New constructor for car
    // It will call the constructor for vehicle first
    // Then set up the convertible value
    Car(string _make, string _model, int _year, bool _convertible): 
    Vehicle(_make, _model, _year)
    {
        convertible = _convertible;
    }

    bool isConvertible() { return convertible; }

    void retractRoof() {
        cout << "Retracting roof" << endl;
    }
};

class Motorbike: public Vehicle
{
    public:
    Motorbike(string _make, string _model, int _year): Vehicle(_make, _model, _year) { }

    void reverse(int miles) { cout << "Motorbikes cannot reverse" << endl; }
};

int main()
{
    // Vehicle v("Volvo", "Estate", 1990);

    // v.drive(1000);
    // cout << v.getMake() << " " << v.getModel() << " " << v.getMileage() << " miles" << endl;

    // v.drive(2000);
    // cout << v.getMake() << " " << v.getModel() << " " << v.getMileage() << " miles" << endl;

    // Car c("BMW", "M4", 2020, true);

    // c.drive(1000);
    // c.drive(2000);
    // if(c.isConvertible())
    // {
    //     cout << c.getMake() << " " << c.getModel() << " is convertible" << endl;
    //     cout << " and has " << c.getMileage() << " miles" << endl;
    // }
    // c.retractRoof();

    Motorbike m("Honda", "CBR", 2015);
    m.reverse(1);

    return 0;
}