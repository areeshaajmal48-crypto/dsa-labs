#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void showResearchEmployees()
{
    ifstream deptFile("department.csv");
    ifstream empFile("employee.csv");

    if (!deptFile || !empFile)
    {
        cout << "Error opening files." << endl;
        return;
    }

    string deptId, deptName;
    char comma;
    string line;
    string researchDeptId;

    getline(deptFile, line);

    while (deptFile >> deptId >> comma >> deptName)
    {
        if (deptName == "Research")
        {
            researchDeptId = deptId;
            break;
        }
    }

    getline(empFile, line);

    string empId, empName, joiningDate, empDeptId, contact, salary, maritalStatus;

    cout << "Employees working in Research Department:\n" << endl;

    while (empFile >> empId >> comma
        >> empName >> comma
        >> joiningDate >> comma
        >> empDeptId >> comma
        >> contact >> comma
        >> salary >> comma
        >> maritalStatus)
    {
        if (empDeptId == researchDeptId)
        {
            cout << empName << endl;
        }
    }

    deptFile.close();
    empFile.close();
}

int main()
{
    showResearchEmployees();
    return 0;
}