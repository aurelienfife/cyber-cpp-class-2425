#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


// Creating the random list, return one vector
// Classic 'return value' mode
vector<int> createRandList(int size)
{
    // Populate with 10 random numbers
    srand(time(NULL));
    // Create the vector and populate it
    vector<int> v;

    for(int i = 0; i < size; i++)
    {
        v.push_back(rand()%101);
    }

    return v;
}

// Same a above, but this time uses 
// Passing by reference
void createRandList(int size, vector<int>& v)
{
    // Populate with 10 random numbers
    srand(time(NULL));
    // Create the vector and populate it
    for(int i = 0; i < size; i++)
    {
        v.push_back(rand()%101);
    }
}



// When passing objects, use of constant references
// is advised
void displayList(const vector<int>& v)
{
    for (int n: v)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main() 
{
    // Vector: an array which can be mutated
    // ie. changed size etc
    vector<int> randomNums;

    // randomNums = createRandList(10);
    createRandList(10, randomNums);

    displayList(randomNums);

    // Vectors: you can add extra values
    randomNums.push_back(56);
    randomNums.push_back(77);

    displayList(randomNums);

    randomNums.pop_back();

    displayList(randomNums);


    return 0;
}