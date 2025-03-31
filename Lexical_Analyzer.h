#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Tokens.h"



using namespace std; 
class Lexical_Analyzer
{
   std::fstream error_list;
   std::string string_reg;
   double number_reg = 0;
   int order_sign_reg = 0;
   int order_reg = 0;
   int counter_reg = 0;
   int lex_class_reg = 0;
   int relation_value_reg = 0;
   int char_value_reg = 0;
   int state_reg = 0;
   int detection_reg = 0;
   int char_class_value_reg = 0;

   void(Lexical_Analyzer::*q) (SymbolicToken ch);

   vector<Token> table_tokens;

   SymbolicToken Transliterator(int character);




   //states

   //начало строки
   void A1(SymbolicToken ch);
   //искать перем., конст., опер., —R, (, ), отнош.
   void A2(SymbolicToken ch);
   //искать зарезерв. слово, опер., —R, (, ), отнош
   void A3(SymbolicToken ch);
   //ќбнаружить зарезерв.слово
   void B1(SymbolicToken ch);
   //искать переменную
   void C1(SymbolicToken ch);
   //завершить обработку переменной
   void C2(SymbolicToken ch);
   //завершить обработку целой части
   void D1(SymbolicToken ch);
   //завершить обработку дробной части
   void D2(SymbolicToken ch);
   //после буквы ≈
   void D3(SymbolicToken ch);
   //после буквы ≈ и знака
   void D4(SymbolicToken ch);
   //завершить обработку пор€дка
   void D5(SymbolicToken ch);
   //после первой дес€тичной точки
   void D6(SymbolicToken ch);
   //искать номер строки
   void E1(SymbolicToken ch);
   //оставша€с€ часть номера строки
   void E2(SymbolicToken ch);
   //искать переменную и =
   void F1(SymbolicToken ch);
   //оставша€с€ часть переменной
   void F2(SymbolicToken ch);
   //искать =
   void F3(SymbolicToken ch);
   //найти —R (комментарий)
   void G1(SymbolicToken ch);
   //завершить обработку отношени€
   void H1(SymbolicToken ch);

   void Error(SymbolicToken ch);

   //ѕроцедуры

   void DA1D();
   void DA2D();
   void DA3D();
   void DA1E();
   void DA1Ecycle();


public:

   Lexical_Analyzer(string name_file);

};

