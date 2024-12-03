#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    int lotteryDraw[6] = {5, 41, 23, 36, 17, 8};
    // This will not print and array, but an address.
    cout << lotteryDraw << endl;
    // This should show the first element of the array
    cout << *lotteryDraw << endl;

    for(int index =0; index < 6; index++)
    {
        // 'Classic' way to roll through an array
        // cout << lotteryDraw[index] << endl;

        // Pointer way to roll through the array
        cout << "Address: " <<  lotteryDraw+index << endl;
        cout << "Value: " << *(lotteryDraw+index) << endl;
    }

    // Forcing the interpretation of a type into another
    char *p = (char *)lotteryDraw; // Type casting

    for(int index=0; index < 24; index++)
    {
        cout << "Address" << p+index << endl;
        cout << "Value" << *(p+index) << endl;
    }

    int *lotteryDraw2;
    // Allocate 6 integers dynamically;
    lotteryDraw2 = (int *)malloc(6*sizeof(int));

    for(int index=0; index< 6; index++)
    {
        lotteryDraw2[index] = index;
    }

    





    return 0;
}