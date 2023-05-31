#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // 1. Create file stream object, open
    fstream infile;
    infile.open("test_i_o.txt", ios::in);

    fstream outfile;
    outfile.open("", ios::out);

    // 2. Read all data from file 
    int test;
    while(infile > test)
    {
        outfile << test << endl;
    }

    // 3. Closed file
    
}