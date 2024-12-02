# Step-by-Step Tutorial to Create the Employee Wage Programme in C++

This tutorial explains how to create a C++ programme that calculates employee wages, including overtime, using a simple `Employee` class.

## Step 1: Include Necessary Libraries
Begin by including the header file for input-output operations and declare the `std` namespace for convenience:
```cpp
#include <iostream>
using namespace std;
```

## Step 2: Define the `Employee` Class
Create the `Employee` class to represent an employee with a base salary and overtime details.
1. **Add private properties**:
   - `baseSalary` (int): The base salary of the employee.
   - `overtimeRate` (int): The hourly rate for overtime.
   - `overtimeHours` (int): The number of overtime hours worked.
2. **Create a constructor**:
   - Initialise the three properties using the parameters passed to it.
3. **Define public methods**:
   - `getWage()`: Calculates and returns the total wage, including overtime.
   - `setSalary(int newSalary)`: Updates the base salary.

Code:
```cpp
class Employee {
    int baseSalary, overtimeRate, overtimeHours;

public:
    Employee(int salary, int rate, int hours) {
        baseSalary = salary;
        overtimeRate = rate;
        overtimeHours = hours;
    }

    int getWage() {
        return baseSalary + (overtimeRate * overtimeHours);
    }

    void setSalary(int newSalary) {
        baseSalary = newSalary;
    }
};
```

## Step 3: Implement the `main` Function
Write the main function to test the `Employee` class.
1. **Create `Employee` objects**:
   - Initialise multiple employees with different base salaries but the same overtime rate and hours.
2. **Calculate and display wages**:
   - Use `getWage()` to compute and print each employee's total wage.
3. **Modify a salary**:
   - Call `setSalary()` to update one employee's base salary and recalculate their wage.

Code:
```cpp
int main() {
    Employee stewart(30000, 20, 10);
    Employee mitch(32000, 20, 10);
    Employee curtis(28000, 20, 10);

    cout << stewart.getWage() << endl;
    cout << mitch.getWage() << endl;
    cout << curtis.getWage() << endl;

    curtis.setSalary(30000);

    cout << curtis.getWage() << endl;

    return 0;
}
```

## Complete Code
Combine all the above steps into a single file:
```cpp
#include <iostream>
using namespace std;

class Employee {
    int baseSalary, overtimeRate, overtimeHours;

public:
    Employee(int salary, int rate, int hours) {
        baseSalary = salary;
        overtimeRate = rate;
        overtimeHours = hours;
    }

    int getWage() {
        return baseSalary + (overtimeRate * overtimeHours);
    }

    void setSalary(int newSalary) {
        baseSalary = newSalary;
    }
};

int main() {
    Employee stewart(30000, 20, 10);
    Employee mitch(32000, 20, 10);
    Employee curtis(28000, 20, 10);

    cout << stewart.getWage() << endl;
    cout << mitch.getWage() << endl;
    cout << curtis.getWage() << endl;

    curtis.setSalary(30000);

    cout << curtis.getWage() << endl;

    return 0;
}
```

## Explanation
This programme demonstrates:
- **Encapsulation**: Employee details are private and accessed or modified only through class methods.
- **Calculation**: The `getWage()` method calculates the total wage, factoring in overtime pay.
- **Reusability**: Multiple employee objects are created and managed efficiently.

Experiment by adjusting overtime hours, rates, or base salaries to explore different scenarios!