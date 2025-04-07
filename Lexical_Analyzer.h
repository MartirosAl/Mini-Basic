#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Tokens.h"



using namespace std; 
class Lexical_Analyzer
{
   //���� � ��������
   std::fstream error_list;   
   //RSTR
   int string_reg;
   //RCH
   double number_reg = 0; 
   //RZ
   int order_sign_reg = 0;       
   //RP
   int order_reg = 0;        
   //RS
   int counter_reg = 0;
   //RKL
   TokenType lex_class_reg = start;
   //ROT
   int relation_value_reg = 0;
   //RZN
   int char_value_reg = 0;
   //RSOS
   int state_reg = 0;
   //ROB
   int detection_reg = 0;
   //RK
   int char_class_value_reg = 0;

   void(Lexical_Analyzer::*q) (SymbolicToken ch);

   //TL
   vector<Token> table_tokens;

   SymbolicToken Transliterator(int character);




   //states

   //������ ������
   void A1(SymbolicToken ch);
   //������ �����., �����., ����., �R, (, ), �����.
   void A2(SymbolicToken ch);
   //������ ��������. �����, ����., �R, (, ), �����
   void A3(SymbolicToken ch);
   //���������� ��������.�����
   void B1(SymbolicToken ch);
   //������ ����������
   void C1(SymbolicToken ch);
   //��������� ��������� ����������
   void C2(SymbolicToken ch);
   //��������� ��������� ����� �����
   void D1(SymbolicToken ch);
   //��������� ��������� ������� �����
   void D2(SymbolicToken ch);
   //����� ����� �
   void D3(SymbolicToken ch);
   //����� ����� � � �����
   void D4(SymbolicToken ch);
   //��������� ��������� �������
   void D5(SymbolicToken ch);
   //����� ������ ���������� �����
   void D6(SymbolicToken ch);
   //������ ����� ������
   void E1(SymbolicToken ch);
   //���������� ����� ������ ������
   void E2(SymbolicToken ch);
   //������ ���������� � =
   void F1(SymbolicToken ch);
   //���������� ����� ����������
   void F2(SymbolicToken ch);
   //������ =
   void F3(SymbolicToken ch);
   //����� �R (�����������)
   void G1(SymbolicToken ch);
   //��������� ��������� ���������
   void H1(SymbolicToken ch);

   void Error(SymbolicToken ch);

   //���������

   void DA1D();
   void DA2D();
   void DA3D();
   void DA1E();
   void DA1Ecycle();

   void A1a();
   void A1b();
   void A1c();
   void A1d();
   void A1e();

   void A2a(); 
   void A2b(); 
   void A2c(); 
   void A2d(); 
   void A2e(); 
   void A2f(); 
   void A2g(); 
   void A2h(); 
   void A2j(); 
   void A2k(); 
   void A2l(); 
   void A2m(); 
   void A2n(); 
   void A2o(); 
   void A2p(); 
   void A2q(); 
   void A2r(); 
   void A2s(); 
   void A2t(); 
   void A2u(); 
   
   void A3a();
   void A3b();
   void A3c();
   void A3d();
   void A3e();
   void A3f();
   void A3g();

   void B1a();
   void B1b();
   void B1c();
   void B1d();
   void B1e();

   void C1a();

   void C2a();
   void C2b();
   void C2d();

   void D1a();
   void D1b();
   void D1c();
   
   void D2a();
   void D2b();
   void D2c();

   void D3a();

   void D4a();
   
   void D5a();
   void D5b();
   void D5c();

   void D6a();

   void E1a();
   void E1b();

   void E2a();
   void E2b();
   void E2c();

   void F1a();
   void F1b();

   void F2a();

   void F3a();

   void G1a();

   void H1a();
   void H1b();
   void H1c();
   void H1d();
   void H1e();
   void H1f();

   void M1();
   void M2();
   void M3();

   void Exit1();
   void Exit2();
   void Exit3();
   void Exit4();
   void Exit5();
   void Exit6();




public:

   Lexical_Analyzer(string name_file);

};

