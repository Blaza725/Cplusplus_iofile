#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employees{
    string ID;
    string name;
    float sal;
    float basicsal;
    float allo;
    // float total = sal*basicsal + allo;
}

int main()
{
    Employees e;
    cin.ignore();
    // Input to file
    fstream outfile;
    outfile.open("testio.txt", ios::out);

    getline(cin, e.ID);
    outfile << e.ID << endl;
    getline(cin, e.name);
    outfile << e.name << endl;
    cin >> e.sal;
    outfile << e.sal << endl;
    cin >> e.basicsal;
    outfile << e.basicsal << endl;
    cin >> e.allo;
    outfile << e.allo << endl;
    

}