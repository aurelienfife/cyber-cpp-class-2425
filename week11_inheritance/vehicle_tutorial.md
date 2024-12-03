# Step-by-Step Tutorial to Create the Vehicle Programme in C++

This tutorial explains how to create a C++ programme demonstrating inheritance using a `Vehicle` base class and derived classes `Car` and `Motorbike`.

## Step 1: Set Up the Programme
Begin by including the required header and using the `std` namespace:
```cpp
#include <iostream>
using namespace std;
```

## Step 2: Define the `Vehicle` Class
Create a base class `Vehicle` with properties and methods common to all vehicles.
1. **Add protected properties**:
   - `make`, `model` (string): For vehicle details.
   - `year` (int): The manufacturing year.
   - `mileage` (int): Tracks distance travelled.
2. **Implement the constructor**:
   - Initialise `make`, `model`, and `year`.
   - Set `mileage` to `0`.
3. **Define methods**:
   - `drive(int miles)`: Increases `mileage` by `miles`.
   - `reverse(int miles)`: Also increases `mileage`.
   - Getters: `getMileage()`, `getMake()`, `getModel()`.

Code:
```cpp
class Vehicle {
protected:
    string make, model;
    int year, mileage;

public:
    Vehicle(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
        mileage = 0;
    }

    void drive(int miles) {
        mileage += miles;
    }

    void reverse(int miles) {
        mileage += miles;
    }

    int getMileage() { return mileage; }
    string getMake() { return make; }
    string getModel() { return model; }
};
```

## Step 3: Define the `Car` Class
Derive the `Car` class from `Vehicle` and add specific properties and methods.
1. **Add property**:
   - `convertible` (bool): Indicates if the car is convertible.
2. **Constructor**:
   - Call the `Vehicle` constructor for shared properties.
   - Initialise `convertible`.
3. **Methods**:
   - `isConvertible()`: Returns `convertible`.
   - `retractRoof()`: Prints a message.

Code:
```cpp
class Car : public Vehicle {
    bool convertible;

public:
    Car(string _make, string _model, int _year, bool _convertible)
        : Vehicle(_make, _model, _year) {
        convertible = _convertible;
    }

    bool isConvertible() { return convertible; }

    void retractRoof() {
        cout << "Retracting roof" << endl;
    }
};
```

## Step 4: Define the `Motorbike` Class
Derive the `Motorbike` class from `Vehicle` and customise behaviour.
1. **Constructor**:
   - Call the `Vehicle` constructor for initialisation.
2. **Override the `reverse` method**:
   - Print an error message as motorbikes cannot reverse.

Code:
```cpp
class Motorbike : public Vehicle {
public:
    Motorbike(string _make, string _model, int _year)
        : Vehicle(_make, _model, _year) {}

    void reverse(int miles) {
        cout << "Motorbikes cannot reverse" << endl;
    }
};
```

## Step 5: Implement the `main` Function
Test the classes by creating objects and calling their methods.
1. **Create a `Motorbike` object**:
   - Call `reverse()` to display the customised behaviour.
2. **(Optional)** Test commented-out sections to explore other functionality.

Code:
```cpp
int main() {
    Motorbike m("Honda", "CBR", 2015);
    m.reverse(1);
    return 0;
}
```

## Complete Code
Combine all the above steps into a single file:
```cpp
#include <iostream>
using namespace std;

class Vehicle {
protected:
    string make, model;
    int year, mileage;

public:
    Vehicle(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
        mileage = 0;
    }

    void drive(int miles) {
        mileage += miles;
    }

    void reverse(int miles) {
        mileage += miles;
    }

    int getMileage() { return mileage; }
    string getMake() { return make; }
    string getModel() { return model; }
};

class Car : public Vehicle {
    bool convertible;

public:
    Car(string _make, string _model, int _year, bool _convertible)
        : Vehicle(_make, _model, _year) {
        convertible = _convertible;
    }

    bool isConvertible() { return convertible; }

    void retractRoof() {
        cout << "Retracting roof" << endl;
    }
};

class Motorbike : public Vehicle {
public:
    Motorbike(string _make, string _model, int _year)
        : Vehicle(_make, _model, _year) {}

    void reverse(int miles) {
        cout << "Motorbikes cannot reverse" << endl;
    }
};

int main() {
    Motorbike m("Honda", "CBR", 2015);
    m.reverse(1);
    return 0;
}
```

## Explanation
This programme demonstrates:
- **Inheritance**: Shared properties/methods in `Vehicle` are used by derived classes.
- **Polymorphism**: The `Motorbike` class overrides the `reverse` method to change its behaviour.

Feel free to experiment further with this foundation!
```