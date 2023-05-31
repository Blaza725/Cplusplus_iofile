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
};

void writeEmployeesToFile(const string& filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "Cannot open file " << filename << " for writing\n";
        return;
    }

    // Employee employees[10] = {
    //     {1, "Nguyen Van A", 2.3, 5000000, 1000000},
    //     {2, "Tran Van B", 2.5, 6000000, 1200000},
    //     {3, "Le Thi C", 2.7, 7000000, 1400000},
    //     {4, "Pham Van D", 2.9, 8000000, 1600000},
    //     {5, "Hoang Thi E", 3.1, 9000000, 1800000},
    //     {6, "Nguyen Van F", 3.3, 10000000, 2000000},
    //     {7, "Tran Thi G", 3.5, 11000000, 2200000},
    //     {8, "Le Van H", 3.7, 12000000, 2400000},
    //     {9, "Pham Thi I", 3.9, 13000000, 2600000},
    //     {10, "Hoang Van K", 4.1, 14000000, 2800000}
    // };

    fout.write((char*)employees, sizeof(employees));
   fout.close();
}

void readEmployeesFromFile(const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "Cannot open file " << filename << " for reading\n";
        return;
    }

    Employee employees[10];
    fin.read((char*)employees, sizeof(employees));
    fin.close();

    cout << "Employee Information:\n";
    for (int i = 0; i < 10; i++) {
        int total_salary = employees[i].basic_salary * employees[i].salary_coefficient + employees[i].allowance;
        cout << "Employee " << employees[i].id << " - " << employees[i].name << ": " << total_salary << " VND\n";
    }
}

int main() {
    string filename = "employees.dat";
    writeEmployeesToFile(filename);
    readEmployeesFromFile(filename);

    return 0;
}
