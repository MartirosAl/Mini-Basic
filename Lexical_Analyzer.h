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
   void A1(SymbolicToken ch);
   void A2(SymbolicToken ch);
   void A3(SymbolicToken ch);

   void B1(SymbolicToken ch);

   void C1(SymbolicToken ch);
   void C2(SymbolicToken ch);

   void D1(SymbolicToken ch);
   void D2(SymbolicToken ch);
   void D3(SymbolicToken ch);
   void D4(SymbolicToken ch);
   void D5(SymbolicToken ch);
   void D6(SymbolicToken ch);

   void E1(SymbolicToken ch);
   void E2(SymbolicToken ch);

   void F1(SymbolicToken ch);
   void F2(SymbolicToken ch);
   void F3(SymbolicToken ch);

   void G1(SymbolicToken ch);

   void H1(SymbolicToken ch);

   void Error(SymbolicToken ch);



public:

   Lexical_Analyzer(string name_file);

};

