# Step-by-Step Tutorial to Create the Random Number List Programme in C++

This tutorial explains how to create a C++ programme that generates and manipulates a list of random numbers using vectors.

## Step 1: Include Required Libraries
Include the necessary libraries for input-output operations, vector handling, and random number generation:
```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
```

## Step 2: Create a Function to Generate Random Numbers (Return by Value)
1. **Define the function `createRandList(int size)`**:
   - Takes an integer `size` as the number of random numbers to generate.
   - Uses `srand()` to seed the random number generator.
   - Generates random numbers between 0 and 100 using `rand() % 101` and adds them to a vector.
   - Returns the vector.

Code:
```cpp
vector<int> createRandList(int size) {
    srand(time(NULL));
    vector<int> v;

    for (int i = 0; i < size; i++) {
        v.push_back(rand() % 101);
    }

    return v;
}
```

## Step 3: Create a Function to Generate Random Numbers (Pass by Reference)
1. **Define the function `createRandList(int size, vector<int>& v)`**:
   - Similar to the previous function but uses pass-by-reference.
   - Directly modifies the vector passed as an argument instead of returning a new one.

Code:
```cpp
void createRandList(int size, vector<int>& v) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        v.push_back(rand() % 101);
    }
}
```

## Step 4: Display the Vector (Constant Reference)
1. **Define the function `displayList(const vector<int>& v)`**:
   - Loops through the vector and prints its elements separated by spaces.
   - Uses a `const` reference to ensure the vector is not modified.

Code:
```cpp
void displayList(const vector<int>& v) {
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
}
```

## Step 5: Implement the `main` Function
1. **Create a vector to hold random numbers**:
   - Initialise an empty vector.
2. **Generate random numbers**:
   - Use the pass-by-reference version of `createRandList`.
3. **Display the vector**:
   - Call `displayList` to print the numbers.
4. **Modify the vector**:
   - Add two numbers using `push_back`.
   - Remove the last number using `pop_back`.
   - Display the updated vector after each operation.

Code:
```cpp
int main() {
    vector<int> randomNums;

    createRandList(10, randomNums);

    displayList(randomNums);

    randomNums.push_back(56);
    randomNums.push_back(77);

    displayList(randomNums);

    randomNums.pop_back();

    displayList(randomNums);

    return 0;
}
```

## Complete Code
Combine all the above steps into a single programme:
```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> createRandList(int size) {
    srand(time(NULL));
    vector<int> v;

    for (int i = 0; i < size; i++) {
        v.push_back(rand() % 101);
    }

    return v;
}

void createRandList(int size, vector<int>& v) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        v.push_back(rand() % 101);
    }
}

void displayList(const vector<int>& v) {
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    vector<int> randomNums;

    createRandList(10, randomNums);

    displayList(randomNums);

    randomNums.push_back(56);
    randomNums.push_back(77);

    displayList(randomNums);

    randomNums.pop_back();

    displayList(randomNums);

    return 0;
}
```

## Explanation
This programme demonstrates:
- **Vectors**: A dynamic array that can grow and shrink in size.
- **Pass-by-reference**: Efficiently modifying a vector without copying it.
- **Random number generation**: Using `rand()` and `srand()` for randomisation.

Experiment with the vector size or additional operations (e.g., sorting) to expand this programme!