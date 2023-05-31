#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char data[100];
    
    // Open file in write mode
    ofstream outfile;
    outfile.open("test_i_o.txt");

    cout << "Writing to the file" << endl;
    cout << "Enter the name: ";
    cin.getline(data, 100);

    // Write inputted data into the file
    outfile << data << endl;

    cout << "Enter the age: ";
    cin >> data;
    cin.ignore();

    //Again write inputted data into the file
    outfile << data << endl;

    //Close the opened file
    outfile.close();

    // Open a file in read mode
    ifstream infile;
    infile.open("test_i_o.txt");

    cout << "Reading from the file"  << endl;
    infile >> data;
    
    // Write the data at the screen
    cout << data << endl;

    // Again read the data from the file and display it
    infile >> data;
    cout << data << endl;

    // Close the opened file
    infile.close();


    return 0;


}