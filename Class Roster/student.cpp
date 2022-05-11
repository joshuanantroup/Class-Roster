//
//  student.cpp
//  Class Roster
//
//  Created by Josh Nantroup on 5/7/22.
//

#include "student.hpp"
#include "degree.h"
using std::string;
using std::cout;


Student::Student() // parameterless constructor
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse[0] = 0;
    this->daysInCourse[1] = 0;
    this->daysInCourse[2] = 0;
    this->degreeProgram = DegreeProgram::NONE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram) // complete constructor
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
    this->degreeProgram = degreeProgram;
}

// destructor
Student::~Student(){};

// accessors aka getters
string Student::getstudentID() { return this->studentID; }
string Student::getfirstName() { return this->firstName; }
string Student::getlastName() { return this->lastName; }
string Student::getemailAddress() { return this->emailAddress; }
int Student::getage() { return this->age; }
int* Student::getdaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getdegreeProgram() { return this->degreeProgram; }

//mutators aka setters
void Student::setstudentID(string studentID) { this->studentID = studentID; }
void Student::setfirstName(string firstName) { this->firstName = firstName; }
void Student::setlastName(string lastName) { this->lastName = lastName; }
void Student::setemailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setage(int age) { this->age = age; }
void Student::setdaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
    //for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
       Student::daysInCourse[0] = daysInCourse1;
       Student::daysInCourse[1] = daysInCourse2;
       Student::daysInCourse[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// used to print the header
void Student::printHeader()
{
    //cout << "ID | First | Last    | Email Address | Age | Days | Degree\n";
    cout  << left
            << setw(5) << "ID:|"
            << setw(15) << "First Name: |"
            << setw(15) << "Last Name:   |"
            << setw(30) << "Email Address:           |"
            << setw(10) << "Age:   |"
            << setw(20) << "Days In Course:      |"
            << setw(10) << "Degree Program:"
            << endl;
     
}

void Student::print()
{
    cout  << left
            << setw(5) << this->getstudentID()
            << setw(15) << this->getfirstName()
            << setw(15) << this->getlastName()
            << setw(30) << this->getemailAddress()
            << setw(10) << this->getage()
            << this->getdaysInCourse()[0] << ","
            << this->getdaysInCourse()[1] << ","
            << this->getdaysInCourse()[2] << '\t'
            << right << setw(20) << degreeProgramStr[degreeProgram]
            << endl;
   
}
