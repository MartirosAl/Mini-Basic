#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Tokens.h"



using namespace std; 
class MINI_BASIC
{
   //���� � ��������
   std::fstream error_list;   
   //RSTR
   int number_string_reg;
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
   //RSOS
   int state_reg = 0;
   //ROB
   int detection_reg = 0;
   //RK
   int char_class_value_reg = 0;

   typedef void(MINI_BASIC::*func) ();
   func q;

   //RZN ������� ������ 
   SymbolicToken character;
   //������� �����
   string word;

   //�����
   ifstream& stream;

   //TL
   vector<Token> table_tokens;

   SymbolicToken Transliterator(int character);




   //states

   //������ ������
   void A1();
   //������ �����., �����., ����., �R, (, ), �����.
   void A2();
   //������ ��������. �����, ����., �R, (, ), �����
   void A3();
   //���������� ��������.�����
   void B1();
   //������ ����������
   void C1();
   //��������� ��������� ����������
   void C2();
   //��������� ��������� ����� �����
   void D1();
   //��������� ��������� ������� �����
   void D2();
   //����� ����� �
   void D3();
   //����� ����� � � �����
   void D4();
   //��������� ��������� �������
   void D5();
   //����� ������ ���������� �����
   void D6();
   //������ ����� ������
   void E1();
   //���������� ����� ������ ������
   void E2();
   //������ ���������� � =
   void F1();
   //���������� ����� ����������
   void F2();
   //������ =
   void F3();
   //����� �R (�����������)
   void G1();
   //��������� ��������� ���������
   void H1();

   void Error();

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

   void EXIT1();
   void EXIT2();
   void EXIT3();
   void EXIT4();
   void EXIT5();
   void EXIT6();

   void Create_Token();

   void Error_Handler();


   struct Keyword{
      char letter;
      func f;
      int alt;
   };

   vector<vector<int>> table_first_vector
   {
      {'E', 1 },
      {'F', 3 },
      {'G', 5 },
      {'I', 11},
      {'L', 12},
      {'N', 14},
      {'R', 17},
      {'S', 23},
      {'T', 26}
   };

   vector<Keyword> table_detection
   {
      /**1*/{'N', B1d, -1},//END
      /**2*/{'D', A2q, -1},//END
      /**3*/{'O', B1d, -1},//FOR
      /**4*/{'R', F1b, -1},//FOR
      /**5*/{'O', B1d, -1},//GOTO, GOSUB
      /**6*/{'T', B1d,  8},//GOTO 
      /**7*/{'O', E1a, -1},//GOSUB
      /**8*/{'S', B1d, -1},//GOSUB
      /**9*/{'U', B1d, -1},//GOSUB
      /*10*/{'B', E1b, -1},//GOSUB
      /*11*/{'F', A2r, -1},//IF
      /*12*/{'E', B1d, -1},//LET
      /*13*/{'T', F1a, -1},//LET
      /*14*/{'E', B1d, -1},//NEXT
      /*15*/{'X', B1d, -1},//NEXT
      /*16*/{'T', C1a, -1},//NEXT
      /*17*/{'E', B1d, -1},//RETURN, REM
      /*18*/{'T', B1d, 22},//RETURN
      /*19*/{'U', B1d, -1},//RETURN
      /*20*/{'R', B1d, -1},//RETURN
      /*21*/{'N', A2s, -1},//RETURN
      /*22*/{'M', G1a, -1},//REM
      /*23*/{'T', B1d, -1},//STEP
      /*24*/{'E', B1d, -1},//STEP
      /*25*/{'P', A2t, -1},//STEP
      /*26*/{'O', A2u, -1},//TO
   };

  


public:

   MINI_BASIC(string name_file);

};

