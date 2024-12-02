# Step-by-Step Tutorial to Create the Car Programme in C++

This tutorial explains how to create a simple C++ programme that models a `Car` class with properties and methods to track its mileage.

## Step 1: Include the Necessary Libraries
Begin by including the header file for input-output operations and declare the `std` namespace for easier syntax:
```cpp
#include <iostream>
using namespace std;
```

## Step 2: Define the `Car` Class
Create a `Car` class to represent a car object.
1. **Add private properties**:
   - `make`, `model` (string): To store the car's brand and model.
   - `year` (int): The manufacturing year.
   - `mileage` (int): Tracks the total distance travelled.
2. **Create a constructor**:
   - Accept `make`, `model`, and `year` as parameters.
   - Initialise `mileage` to `0`.
3. **Define public methods**:
   - `drive(int miles)`: Increases `mileage` by the given miles.
   - `getMileage()`: Returns the current mileage.

Code:
```cpp
class Car {
    string make, model;
    int year, mileage;

public:
    Car(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
        mileage = 0;
    }

    void drive(int miles) {
        mileage += miles; 
    }

    int getMileage() { return mileage; }
};
```

## Step 3: Implement the `main` Function
Write the main function to test the `Car` class.
1. **Create a `Car` object**:
   - Initialise with specific values for `make`, `model`, and `year`.
2. **Create an array of drive distances**:
   - Use an array to represent the different distances the car has been driven.
3. **Iterate through the array**:
   - For each distance, call the `drive` method.
   - Print the updated mileage after each drive.

Code:
```cpp
int main() {
    Car tankar("Fiat", "500", 2016);

    int drives[5] = {32, 60, 200, 30, 59};

    for (int miles : drives) {
        tankar.drive(miles);
        cout << "The new mileage is: " << tankar.getMileage() << endl;
    }

    return 0;
}
```

## Complete Code
Combine all the above steps into a single file:
```cpp
#include <iostream>
using namespace std;

class Car {
    string make, model;
    int year, mileage;

public:
    Car(string _make, string _model, int _year) {
        make = _make;
        model = _model;
        year = _year;
        mileage = 0;
    }

    void drive(int miles) {
        mileage += miles; 
    }

    int getMileage() { return mileage; }
};

int main() {
    Car tankar("Fiat", "500", 2016);

    int drives[5] = {32, 60, 200, 30, 59};

    for (int miles : drives) {
        tankar.drive(miles);
        cout << "The new mileage is: " << tankar.getMileage() << endl;
    }

    return 0;
}
```

## Explanation
This programme demonstrates:
- **Encapsulation**: Properties like `make`, `model`, and `mileage` are private, ensuring they are modified only through class methods.
- **Iteration**: A `for` loop is used to simulate multiple drives.

Feel free to extend the programme by adding more properties (e.g., fuel efficiency) or methods (e.g., refuel)!