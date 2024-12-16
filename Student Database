#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class definition
class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;

public:
    // Default constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        studentClass = "None";
        division = 'X';
        dateOfBirth = "01/01/2000";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "Unknown";
        drivingLicenseNumber = "Unknown";
    }

    // Parameterized constructor
    Student(string n, int r, string cls, char div, string dob, string bg, string addr, string phone, string dl) {
        name = n;
        rollNumber = r;
        studentClass = cls;
        division = div;
        dateOfBirth = dob;
        bloodGroup = bg;
        contactAddress = addr;
        telephoneNumber = phone;
        drivingLicenseNumber = dl;
    }
    ~Student(){}

    // Function to display student details
    void displayDetails() {
        cout << "\nStudent Details:\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License Number: " << drivingLicenseNumber << endl;
    }

    // Function to input student details
    void inputDetails() {
        cout << "\nEnter Student Details:\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Roll Number: ";
        cin >> rollNumber;
       // cin.ignore(); // Clear the newline character from the input buffer
        cout << "Class: ";
        getline(cin, studentClass);
        cout << "Division: ";
        cin >> division;
       // cin.ignore();
        cout << "Date of Birth (DD/MM/YYYY): ";
        getline(cin, dateOfBirth);
        cout << "Blood Group: ";
        getline(cin, bloodGroup);
        cout << "Contact Address: ";
        getline(cin, contactAddress);
        cout << "Telephone Number: ";
        getline(cin, telephoneNumber);
        cout << "Driving License Number: ";
        getline(cin, drivingLicenseNumber);
    }
};

int main() {

    Student s1;
    s1.inputDetails();
    s1.displayDetails();
    return 0;
}
