#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void showHighSalaryEmployees()
{
    ifstream file("employee.csv");

    if (!file)
    {
        cout << "File not found." << endl;
        return;
    }

    string line;
    getline(file, line);

    string empId, empName, joiningDate, deptId, contact, maritalStatus;
    double salary;
    char comma;

    cout << "Employees earning 1500000 or more per year:\n" << endl;

    while (file >> empId >> comma
        >> empName >> comma
        >> joiningDate >> comma
        >> deptId >> comma
        >> contact >> comma
        >> salary >> comma
        >> maritalStatus)
    {
        double yearlySalary = salary * 12;

        if (yearlySalary >= 1500000)
        {
            cout << empName << " - " << yearlySalary << endl;
        }
    }

    file.close();
}

int main()
{
    showHighSalaryEmployees();
    return 0;
}