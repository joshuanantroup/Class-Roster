//
//  student.hpp
//  Class Roster
//
//  Created by Josh Nantroup on 5/7/22.
//
#pragma once
#include <iostream>
#include <iomanip>
#include <array>
#include "degree.h"
using std::string;
using std::cout;

// class for each student
class Student
{
public:
    const static int daysInCourseArraySize = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[daysInCourseArraySize];
    DegreeProgram degreeProgram;
    
public:
    Student(); // empty constructor - sets to default values
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram);
    ~Student(); // destructor
    
    // accessors aka getters
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemailAddress();
    int getage();
    int* getdaysInCourse();
    DegreeProgram getdegreeProgram();
    
    // mutators aka setters
    void setstudentID(string studentID);
    void setfirstName(string firstName);
    void setlastName(string lastName);
    void setemailAddress(string emailAddress);
    void setage(int age);
    void setdaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    static void printHeader(); // displays header for data to follow
    
    void print (); // displays this student's data
};
