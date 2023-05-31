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

void WriteInfoToFile(const string& filename, int n)
{
    fstream outfile(filename, ios::out | ios::binary);
    if(!outfile)
    {
        cout << "Khong the mo file " << filename << " de ghi du lieu\n";
        return;
    }

    Employees e[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i+1 << ":\n";
        cin.ignore();       
        cout << "ID: ";
        getline(cin, e[i].ID);
        cout << "H? và tên: ";
        getline(cin, e[i].name);
        cout << "H? s? luong: ";
        cin >> e[i].sal;
        cout << "Luong co b?n: ";
        cin >> e[i].basicsal;
        cout << "Ph? c?p: ";
        cin >> e[i].allo;
    }
    outfile.write((char*)e, sizeof(e));
    outfile.close();
}

void ReadInfoOfFile(const string& filename, int n)
{
    fstream infile(filename, ios::in | ios::binary);
    if(!infile)
    {
        cout << "Khong the mo file " << filename << " de doc du lieu\n";
        return;
    }

    Employees e[n];
    infile.read((char*)e, sizeof(e));
    infile.close();

    cout << "Thong tin nhan vien:\n";
    for (int i = 0; i < n; i++) 
    {
        int total_salary = e[i].sal * e[i].basicsal + e[i].allo;
        cout << "Nhan vien " << e[i].ID << " - " << e[i].name << ": " << total_salary << " (Trieu dong)\n";
    }

}


int main()
{
    string filename = "testemployees_01.txt";
    cout << "Nhap so luong nhan vien: ";
    int n;
    cin >> n;
    WriteInfoToFile(filename, n);
    ReadInfoOfFile(filename, n);

    return 0;
}
