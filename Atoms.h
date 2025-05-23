#pragma once
#include <vector>
#include <string>
using namespace std;

enum AtomType
{
   start_A = -1, END_A, NUMBER_LINE_A, ASSIGNMENT_A, TRANSITION_A, STORAGE_TRANSITION_A, RETURN_TRANSITION_A, CONDITIONAL_TRANSITION_A, STORAGE_A, LABLE_A, CHECK, INCREASE_A, ADDITION_A, SUBSTRACTION_A, MULTIPLICATION_A, DIVISION_A, POWER_A, PLUS_A, MINUS_A
};

const vector<string> AtomTypeString
{
    "END", "NUMBER_LINE", "ASSIGNMENT", "TRANSITION", "STORAGE_TRANSITION", "RETURN_TRANSITION", "CONDITIONAL_TRANSITION", "STORAGE", "LABLE", "CHECK", "INCREASE", "ADDITION", "SUBSTRACTION", "MULTIPLICATION", "DIVISION", "POWER", "PLUS", "MINUS"
};

struct Atom
{
   AtomType type = start_A;
   int attribute1 = 0;
   int attribute2 = 0;
   int attribute3 = 0;
   int attribute4 = 0;
};