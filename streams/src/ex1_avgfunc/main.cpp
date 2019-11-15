/*******************************************************************************
 *
 *  Workshop 6 example 1
 *
 * 1) Create a function called printDblArray() that prints a given array of doubles
 * as a row of elements. Use comma (,) as a delimiter. Enclose the output seq in
 * curly brackets.
 *
 * 2) Create a function called calcAvg() that obtains on its input a c-style
 * array of double, calculates an average of array elements and returns it.
 * Put the function definition before main().
 *
 ******************************************************************************/

#include <iostream>
#include <string>
//#include <cassert>              // for assert macro

using std::cout;
using std::cin;

void printDblArray(double arr[], size_t arrSize)
{
    cout << '{';
    bool firstEl = true;

    for(size_t i = 0; i < arrSize; ++i)
    {
        if(!firstEl)
            cout << ", ";
        else
            firstEl = false;

        cout << arr[i];
    }

    cout << '}';
}

double calcAvg(double arr[], size_t arrSize)
{
    double avg = 0;
    for(size_t i = 0; i < arrSize; ++i)
        avg += arr[i];

//    avg /= arrSize;
//    return avg;
    return avg / arrSize;       // return an expression
}




int main()
{
    cout << "Workshop 6 Example 1\n\n";

    double e1[5] = {1, 2, 3, 4, 5.1};
    size_t e1Sz = sizeof(e1) / sizeof(e1[0]);
    //printDblArray(e1, e1Sz);
    double e1Avg = calcAvg(e1, e1Sz);

    // prints it
    cout << "Arr1: ";
    printDblArray(e1, e1Sz);
    cout << "; its avg = " << e1Avg;
    cout << "\n";

    double e2[5] = {10.1, 2.1e2, 3.3e-1, 40.4}; // different forms of float consts
    size_t e2Sz = sizeof(e2) / sizeof(e2[0]);
    double e2Avg = calcAvg(e2, e2Sz);

    // prints it
    cout << "Arr2: ";
    printDblArray(e2, e2Sz);
    cout << "; its avg = " << e2Avg;

    // TODO: HW: here we have the same pattern for both arrays.
    // Refactor the program (create a function if needed) to generalize cases.


    cout << "\n\n";

    return 0;
}
