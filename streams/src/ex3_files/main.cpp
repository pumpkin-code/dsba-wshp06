/*******************************************************************************
 *
 *  Workshop 6 example 3
 *
 * 1) Create a function called sumLines() that obtains an input stream
 * object (given by reference) istream&, reads float numbers from it line by line
 * and sums up numbers from each line. The result is output to a given
 * output stream (given by reference) ostream&.
 *
 * Reuse function calcSumFromStream() developed in ex. to deal with individual lines!
 *
 * In the main program provide two different file stream (both text files) to
 * read from and output to data, correspondingly.
 * http://www.cplusplus.com/doc/tutorial/files/
 *
 ******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>      // for files

using std::cout;
using std::string;
using std::stringstream;

// prototype
double calcSumFromStream(std::istream& istr);


void sumLines(std::istream& istr, std::ostream& ostr)
{
    // read line by line
    while(istr.good() && !istr.eof())
    {
        string s;
        std::getline(istr, s);
        if(s.empty())
            return;                 // empty string breaks the execution

        // otherwise its not empty
        stringstream ss(s);
        double sum = calcSumFromStream(ss);
        ostr << sum << std::endl;
    }
}


int main()
{
    using std::cout;
    using std::cin;

    cout << "Workshop 6 Example 3\n\n";


    const char INP_FILE_NAME[] = "f:\\HSE\\training\\DSBA\\2019-20\\programming\\workhops\\06\\code\\streams\\src\\ex3_files\\inp.txt";
    std::ifstream inpFile;
    inpFile.open (INP_FILE_NAME);           // open the file

    sumLines(inpFile, cout);                // outputs result to screen

    inpFile.clear();                        // clear flags
    inpFile.seekg(0);                       // read pos — to the beginning

    // for output file
    const char OUTP_FILE_NAME[] = "f:\\HSE\\training\\DSBA\\2019-20\\programming\\workhops\\06\\code\\streams\\src\\ex3_files\\outp.txt";
    std::ofstream outpFile(OUTP_FILE_NAME); // init right here
    // onpFile.open(INP_FILE_NAME);         // do not need to, cause already open
    sumLines(inpFile, outpFile);            // outputs result to a file

    outpFile.close();
    inpFile.close();


    cout << "\n\n";

    return 0;
}

// implementation
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
