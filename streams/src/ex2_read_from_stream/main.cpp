/*******************************************************************************
 *
 *  Workshop 6 example 2
 *
 * 1) Create a function called calcSumFromStream() that obtains an input stream
 * object (given by reference) istream&, reads float numbers from it until the end
 * of line, sums them and returns the result by value.
 * Put the definition of the method below main(), use a prototype for declaring it.
 *
 ******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;


double calcSumFromStream(std::istream& istr);

int main()
{
    cout << "Workshop 6 Example 2\n\n";

    // input data from std::cin and output result to std::cout
    cout << "Input numbers to calculate sum: ";
    cout << "Sum is: " << calcSumFromStream(cin);

    cout << "\n\n";

    return 0;
}

double calcSumFromStream(std::istream& istr)
{
    // we have to use stringstream to read a whole line
    std::string s;
    std::getline(istr, s);
    std::stringstream ss(s);

    double sum = 0;

    while(ss.good() && !ss.eof())
    {
        double  cur;
        ss >> cur;
        sum += cur;
    }

    return sum;
}

