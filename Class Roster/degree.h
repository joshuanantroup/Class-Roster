//
//  degree.h
//  Class Roster
//
//  Created by Josh Nantroup on 5/7/22.
//
#pragma once
#include <iostream>
#include <string>
using namespace std;

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE, NONE };

// array creates a string translation for each degree program enum

static const string degreeProgramStr[] = { "SECURITY", "NETWORK", "SOFTWARE", "NONE" };
