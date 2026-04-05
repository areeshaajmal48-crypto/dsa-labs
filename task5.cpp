#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("employee.csv");

    if (!file)
    {
        cout << "File not found." << endl;
        return 1;
    }

    string line;
    getline(file, line);

    string empId, empName, joiningDate, deptId, contact, maritalStatus;
    double salary;
    char comma;

    string highestName, lowestName;
    double highestSalary = 0;
    double lowestSalary = 1000000000;

    int marriedCount = 0;
    double totalSalary = 0;
    int totalEmployees = 0;

    double imranSalary = 0;
    double azizSalary = 0;

    while (file >> empId >> comma
        >> empName >> comma
        >> joiningDate >> comma
        >> deptId >> comma
        >> contact >> comma
        >> salary >> comma
        >> maritalStatus)
    {
        totalEmployees++;
        totalSalary += salary;

        if (salary > highestSalary)
        {
            highestSalary = salary;
            highestName = empName;
        }

        if (salary < lowestSalary)
        {
            lowestSalary = salary;
            lowestName = empName;
        }

        if (maritalStatus == "Married")
        {
            marriedCount++;
        }

        if (empName == "Imran")
            imranSalary = salary;

        if (empName == "Aziz")
            azizSalary = salary;
    }

    file.close();

    cout << "1. Highest Salary: " << highestName << endl;
    cout << "2. Lowest Salary: " << lowestName << endl;
    cout << "3. Total Married Employees: " << marriedCount << endl;

    cout << "4. Employees who are Single:\n";

    ifstream file2("employee.csv");
    getline(file2, line);

    while (file2 >> empId >> comma
        >> empName >> comma
        >> joiningDate >> comma
        >> deptId >> comma
        >> contact >> comma
        >> salary >> comma
        >> maritalStatus)
    {
        if (maritalStatus == "Single")
            cout << empName << endl;
    }

    cout << "5. Average Salary: " << totalSalary / totalEmployees << endl;

    cout << "6. Employees earning more than Imran:\n";

    file2.clear();
    file2.seekg(0);
    getline(file2, line);

    while (file2 >> empId >> comma
        >> empName >> comma
        >> joiningDate >> comma
        >> deptId >> comma
        >> contact >> comma
        >> salary >> comma
        >> maritalStatus)
    {
        if (salary > imranSalary)
            cout << empName << endl;
    }

    cout << "7. Employees earning less than Aziz:\n";

    file2.clear();
    file2.seekg(0);
    getline(file2, line);

    while (file2 >> empId >> comma
        >> empName >> comma
        >> joiningDate >> comma
        >> deptId >> comma
        >> contact >> comma
        >> salary >> comma
        >> maritalStatus)
    {
        if (salary < azizSalary)
            cout << empName << endl;
    }

    cout << "8. Search Omer:\n";

    file2.clear();
    file2.seekg(0);
    getline(file2, line);

    while (file2 >> empId >> comma
        >> empName >> comma
        >> joiningDate >> comma
        >> deptId >> comma
        >> contact >> comma
        >> salary >> comma
        >> maritalStatus)
    {
        if (empName == "Omer")
        {
            cout << empId << " "
                << empName << " "
                << joiningDate << " "
                << deptId << " "
                << contact << " "
                << salary << " "
                << maritalStatus << endl;
        }
    }

    file2.close();

    return 0;
}