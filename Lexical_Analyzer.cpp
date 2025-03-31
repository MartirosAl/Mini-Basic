#pragma once
#include "Lexical_Analyzer.h"

//Начало строки
void Lexical_Analyzer::A1(SymbolicToken ch)
{
    switch (ch.token_class)
    {
    case DIGIT:
        E2a();
        break;
    case SPACE:
        q = A1;
        break;
    case LF:
        q = A1;
        break;
    case END_OF_FILE_S:
        q = EXIT1;
        break;
    default:
        break;
    }
}

void Lexical_Analyzer::A2(SymbolicToken ch)
{
    switch (ch.token_class)
    {
    case LETTER:
        C2a();
        break;
    case DIGIT:
        D1a();
        break;
    case ARITHMETIC_OPERATION_S:
        A2a();
        break;
    case RELATION_S:
        H1a();
        break;
    case O_BRACE_S:
        A2h();
        break;
    case C_BRACE_S:
        A3b();
        break;
    case DOT:
        q = D6;
        break;
    case SPACE:
        break;
    case LF:
        break;
    case END_OF_FILE_S:
        break;
    default:
        break;
    }
}

void Lexical_Analyzer::A3(SymbolicToken ch)
{
    switch (ch.token_class)
    {
    case LETTER:
        break;
    case DIGIT:
        break;
    case ARITHMETIC_OPERATION_S:
        break;
    case RELATION_S:
        break;
    case O_BRACE_S:
        break;
    case C_BRACE_S:
        break;
    case DOT:
        break;
    case SPACE:
        break;
    case LF:
        break;
    case END_OF_FILE_S:
        break;
    default:
        break;
    }
}

void Lexical_Analyzer::B1(SymbolicToken ch)
{
    switch (ch.token_class)
    {
    case LETTER:
        break;
    case DIGIT:
        break;
    case ARITHMETIC_OPERATION_S:
        break;
    case RELATION_S:
        break;
    case O_BRACE_S:
        break;
    case C_BRACE_S:
        break;
    case DOT:
        break;
    case SPACE:
        break;
    case LF:
        break;
    case END_OF_FILE_S:
        break;
    default:
        break;
    }
}

void Lexical_Analyzer::C1(SymbolicToken ch)
{
    switch (ch.token_class)
    {
    case LETTER:
        break;
    case DIGIT:
        break;
    case ARITHMETIC_OPERATION_S:
        break;
    case RELATION_S:
        break;
    case O_BRACE_S:
        break;
    case C_BRACE_S:
        break;
    case DOT:
        break;
    case SPACE:
        break;
    case LF:
        break;
    case END_OF_FILE_S:
        break;
    default:
        break;
    }
}

void Lexical_Analyzer::C2(SymbolicToken ch)
{
    switch (ch.token_class)
    {
    case LETTER:
        break;
    case DIGIT:
        break;
    case ARITHMETIC_OPERATION_S:
        break;
    case RELATION_S:
        break;
    case O_BRACE_S:
        break;
    case C_BRACE_S:
        break;
    case DOT:
        break;
    case SPACE:
        break;
    case LF:
        break;
    case END_OF_FILE_S:
        break;
    default:
        break;
    }
}

void Lexical_Analyzer::D1(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::D2(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::D3(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::D4(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::D5(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::D6(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::E1(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::E2(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::F1(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::F2(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::F3(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::G1(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::H1(SymbolicToken ch)
{
   ;
}

void Lexical_Analyzer::Error(SymbolicToken ch)
{
   ;
}


SymbolicToken Lexical_Analyzer::Transliterator(int character)
{
   SymbolicToken result;
   result.value = 0;
   if (character >= 'A' && character <= 'Z')
   {
      result.token_class = SymbolicTokenType::LETTER;
      result.value = (int)character;
   }
   else if (character >= '0' && character <= '9')
   {
      result.token_class = SymbolicTokenType::DIGIT;
      result.value = (int)character;
   }
   else if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^')
   {
      result.token_class = SymbolicTokenType::ARITHMETIC_OPERATION_S;
      result.value = (int)character;
   }
   else if (character == '<' || character == '>' || character == '=')
   {
      result.token_class = SymbolicTokenType::RELATION_S;
      result.value = (int)character;
   }
   else if (character == '(')
   {
      result.token_class = SymbolicTokenType::O_BRACE_S;
      result.value = (int)character;
   }
   else if (character == ')')
   {
      result.token_class = SymbolicTokenType::C_BRACE_S;
      result.value = (int)character;
   }
   else if (character == ' ' || character == '\t')
   {
      result.token_class = SymbolicTokenType::SPACE;
      result.value = (int)character;
   }
   else if (character == '\n')
   {
      result.token_class = SymbolicTokenType::LF;
      result.value = (int)character;
   }
   else if (character == EOF)
   {
      result.token_class = SymbolicTokenType::END_OF_FILE_S;
      result.value = (int)character;
   }
   else
   {
      result.token_class = SymbolicTokenType::ERROR_S;
      result.value = (int)character;
   }
   return result;
}

Lexical_Analyzer::Lexical_Analyzer(string name_file)
{
   ifstream in(name_file);
   if (!in)
   {
      cout << "Couldn't open the file " << name_file << endl;
      return; 
   }

   SymbolicToken character;
   string word;

   //Tests flags
   bool flag_work_state = false;

   //Initial state
   q = &Lexical_Analyzer::A1;

   while(true)
   {
      character = Transliterator(in.get());
      

      (this->*q)(character);
      if (q == &Lexical_Analyzer::Error)
         return;
      if (flag_work_state)
         cout << character.value << endl;

      if (q == &Lexical_Analyzer::A3)
      {
         cout << "Goodbye World!" << endl;
         break;
      }
   }

`}
