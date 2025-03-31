#pragma once
#include <map>
#include <string>

using namespace std;

enum TokenType
{
   start = -1, LABLE, OPERAND, ARITHMETIC_OPERATIONS, RELATIONSHIP_OPERATIONS, 
   NEXT, LET, FOR, GOTO, GOSUB, L_BRACKET, R_BRACKET, IF, RETURN, END, TO, STEP, REM, ERROR, END_OF_FILE
};

enum Arithmetic_Operations
{
   PLUS, MINUS, MULT, DIV, XOR
};

enum Relationship_operations
{
   EQUAL, NOT, LESS_THEN, MORE_THEN, NOT_EQUAL, LESS_OR_EQUAL_THEN, MORE_OR_EQUAL_THEN
};

const map<string, TokenType> table_detection
{
   {"NEXT", NEXT}, {"LET", LET}, {"FOR", FOR}, {"GOTO", GOTO}, {"GOSUB", GOSUB}, 
   {"IF", IF}, {"RETURN", RETURN}, {"END", END}, {"TO", TO}, {"STEP", STEP}, {"REM", REM}
};

struct Token
{
   TokenType type = start;
   string value;
};

enum SymbolicTokenType
{
   start_S = -1,
   LETTER,
   DIGIT,
   ARITHMETIC_OPERATION_S,
   RELATION_S,
   SPACE,
   LF,
   ERROR_S,
   O_BRACE_S,
   C_BRACE_S,
   DOT,
   END_OF_FILE_S
};

struct SymbolicToken
{
   SymbolicTokenType token_class = start_S;
   int value = 0;
};




