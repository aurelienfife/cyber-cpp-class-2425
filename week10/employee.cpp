#include <iostream>

using namespace std;

class Employee {
    int baseSalary, overtimeRate, overtimeHours;

public:
    // Constructor
    Employee(int salary, int rate, int hours) {
        baseSalary = salary;
        overtimeRate = rate;
        overtimeHours = hours;
    }

    int getWage()  {
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