#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("StudentInfo.csv");

    if (!file)
    {
        cout << "File not found." << endl;
        return 1;
    }

    string regNo, firstName, lastName, program, contact;
    double cgpa;
    char comma;

    getline(file, regNo);

    cout << "Students with CGPA 3.5 or above:\n" << endl;

    while (file >> regNo >> comma
        >> firstName >> comma
        >> lastName >> comma
        >> program >> comma
        >> cgpa >> comma
        >> contact)
    {
        if (cgpa >= 3.5)
        {
            cout << firstName << " " << lastName << endl;
        }
    }

    file.close();

    return 0;
}