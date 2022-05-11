//
//  roster.cpp
//  Class Roster
//
//  Created by Josh Nantroup on 5/7/22.
//

#include "roster.hpp"
#include <iostream>
#include <string>



void Roster::parse(string studentdata)
{
    int rhs = studentdata.find(",");
    string studentID = studentdata.substr(0, rhs);
    int lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string firstName = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string lastName = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string emailAddress = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int age = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse1 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse2 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse3 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    
    DegreeProgram deg = SECURITY;
    
    if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') deg = SECURITY;
        else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') deg = SOFTWARE;
        else if (studentdata.at(lhs) == 'N') deg = NETWORK;
    
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, deg);
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int daysInCourse[3] =
    {
        daysInCourse1, daysInCourse2, daysInCourse3
    };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}
    

void Roster::printAverageDays(string studentID){
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            if (classRosterArray[i]->getstudentID()==studentID)
            {
        
                cout << studentID << ": ";
                cout << (classRosterArray[i]->getdaysInCourse()[0] + classRosterArray[i]->getdaysInCourse()[1] + classRosterArray[i]->getdaysInCourse()[2]) / 3 << std::endl;
            }
        }
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string emailAddress = (classRosterArray[i]->getemailAddress());
        if (emailAddress.find('@') == string::npos ||
            emailAddress.find('.') == string::npos ||
            emailAddress.find(' ') != string::npos)
        {
            any = true;
            cout << classRosterArray[i]->getstudentID() << ": " << classRosterArray[i]->getemailAddress() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++){
        if (Roster::classRosterArray[i]->getdegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << std::endl;
}


void Roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++){
        if (classRosterArray[i]->getstudentID() == studentID){
            success = true;
            if (i < numStudents - 1){
                Student* temp = classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << "Student " << studentID << " removed from table." << std::endl << std::endl;
        this->printAll();
    }
    else cout << "Student " << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster() //Destructor
{
    cout << "Destructor called!" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl << std::endl;
        classRosterArray[i] = nullptr;
        //delete classRosterArray
        
        
    }
}
