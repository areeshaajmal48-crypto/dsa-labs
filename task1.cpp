#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("StudentInfo.csv");

    if (!outFile)
    {
        cout << "Unable to create file." << endl;
        return 1;
    }

    outFile << "RegistrationNumber,FirstName,LastName,Program,CGPA,ContactNumber\n";

    int totalStudents;
    cout << "How many students do you want to enter? ";
    cin >> totalStudents;

    for (int i = 1; i <= totalStudents; i++)
    {
        string registrationNumber;
        string firstName;
        string lastName;
        string program;
        string contactNumber;
        double cgpa;

        cout << "\nStudent " << i << endl;

        cout << "Registration Number: ";
        cin >> registrationNumber;

        cout << "First Name: ";
        cin >> firstName;

        cout << "Last Name: ";
        cin >> lastName;

        cout << "Program: ";
        cin >> program;

        cout << "CGPA: ";
        cin >> cgpa;

        cout << "Contact Number: ";
        cin >> contactNumber;

        outFile << registrationNumber << ","
            << firstName << ","
            << lastName << ","
            << program << ","
            << cgpa << ","
            << contactNumber << "\n";
    }

    outFile.close();

    cout << "\nStudent data saved successfully." << endl;

    return 0;
}