//
//  roster.hpp
//  Class Roster
//
//  Created by Josh Nantroup on 5/7/22.
//

#pragma once
#include "student.hpp"
#include <string>
#include <iostream>
using std::cout;

class Roster {
    
public:
    int lastIndex = -1;
    
    const static int numStudents = 5;
    
    Student* classRosterArray[numStudents];
    
    void parse (string row);
    void add (string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    
    void printAll();
    void printAverageDays(string studentID);/*average number of days for students to complete courses*/
    void printInvalidEmails();/*emails must have an "@", a "." and no " "*/
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void removeStudentByID (string studentID);
    Student* getStudentAt(int index);

    //The destructor
    ~Roster();
};
