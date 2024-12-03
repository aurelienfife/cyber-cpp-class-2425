#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // When you need random numbers, you need to 'seed'
    // The generator with some data.
    srand(time(NULL));

    // Create an array of 10 integers.
    int randomNums[10]; 

    for(int i=0; i<10; i++)
    {
        randomNums[i] = rand()%101;
    }

    // Display the whole array
    for(int n: randomNums)
    {
        cout << n << " ";
    }
    cout << endl;



    return 0;
}

