/*  Bank account class
    Create a class simulating a bank account
    It hold the following data:
    - Account holder name
    - Bank balance (float)

    You define the name and a starting balance when
    creating the object

    You can only interact in the following way:
    - Make deposits
    - Make withdrawals
    - Get the balance
    - Get the account holder name

    Think about:
    - internal variables needed
    - what the constructor needs
    - public functions (methods) needed
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Bank account
class BankAccount {
    // Private member variables
    string name;
    double balance;

public:
    // If no starting balance is defined, set it to zero.
    BankAccount(const string& _name, double startingBalance = 0.0) {
        name = _name;
        balance = startingBalance;
    }

    // Public methods
    void deposit(double d) { balance += d; }
    void withdraw(double w) { balance -= w; }
    double getBalance() { return balance; }
    string getName() { return name; }
};

int main()
{
    string name, input;
    double n;

    cout << "Enter the holder's name" << endl;
    getline(cin, name);

    cout << "Enter the starting balance" << endl;
    getline(cin, input);
    n = atof(input.c_str());

    BankAccount a(name, n);
    a.deposit(1000);
    a.withdraw(500);
    a.deposit(600);

    cout << a.getName() << " has £" << a.getBalance() << endl;

    return 0;
}