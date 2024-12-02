/*  Loops - fixed and conditional 
    Fixed -> for loop / foreach loop
    Conditional -> while / do...while */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    
    /* Conditional loops
    They break off on a condition
    Use them when you are uncertain how many iterations happen
    e.g. checking a password, waiting for an interrupt etc etc
     */

    // while loops - check the condition beforehand; 
    // Loops may be skipped altogether
    string password = "password123";
    string userPass;
    
    // Read password from user
    cout << "Please enter your password: ";
    getline(cin, userPass);

    while(userPass != password) 
    {
        cout << "Wrong password try again: ";
        getline(cin, userPass);
    }

    // do... while - checks condition after loop
    // You need to run the content of the loop at least once
    string input;
    do
    {
        cout << "You are now forced to see this until you type 'yes': ";
        getline(cin, input);
    }
    while(input!="yes");


    // For loops (fixed)
    // In python you used 'for i in range(10):'
    // Using a counter -> 
    // for (variable_init; end_condition; increment)

    for(int i = 0; i < 20; i++) // ++ -> add 1 to var
    {
        cout << i << " ";
    }
    cout << endl;

    // Create an array of students - ARRAY SIZE IS FIXED 
    string students[5] = { "Mitch", "Aurelien", "Yaseen", "Curtis", "Tanya" };
    // 'For each' -> if don't need a counter
    // You can set a variable going through an entire loop

    for(string currentStudent: students)
    {
        cout << currentStudent << endl;
    }
    
    // You can also access traditionally using index

    for(int index = 0; index < 5; index++)
    {
        cout << students[index] << endl;
    }

    // If you need an array that resizes dynamically
    // Use vector

    vector<int> lotteryNums;
    for(int counter=0; counter<6; counter++)
    {
        cout << "Enter a number :";
        getline(cin, input);
        int num = stoi(input);

        lotteryNums.push_back(num);
    } 
    
    return 0;
}
