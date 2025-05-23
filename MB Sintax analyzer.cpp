#include "MB Sintax analyzer.h"
#include <stack>

MINI_BASIC_Syntax_analyzer::MINI_BASIC_Syntax_analyzer()
{
   Create_Big_Table();

   stk.push(18);
   stk.push(1);
   NTA = 0;
   in = NTX = NTM = 1;
   num_str = 0;
   flagErr = false;

}

void MINI_BASIC_Syntax_analyzer::Create_Atom(int index, int a, int b, int c, int d)
{

}

void MINI_BASIC_Syntax_analyzer::a()
{
   stk.pop();
   in++;
}
void MINI_BASIC_Syntax_analyzer::b()
{
   stk.pop();
   int i = stk.top() - 1;
   stk.pop();
   stack<int> tmp;
   while (i != 0)
   {
      tmp.push(stk.top());
      stk.pop();
      i--;
   }
   stk.pop();
   stk.push(table_tokens[in].value);
   while (!tmp.empty())
   {
      stk.push(tmp.top());
      tmp.pop();
   }
   in++;
}
void MINI_BASIC_Syntax_analyzer::c()
{
   Create_Atom(1);
   in++;
}
void MINI_BASIC_Syntax_analyzer::d()
{
   int k1, k2;
   stk.pop();
   k1 = stk.top();
   stk.pop();
   k2 = stk.top();
   stk.pop();
   Create_Atom(3, k1, k2);
}
void MINI_BASIC_Syntax_analyzer::e()
{
   int p, q, r, s;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   r = stk.top();
   stk.pop();
   s = stk.top();
   stk.pop();
   Create_Atom(7, p, q, r, s);

}
void MINI_BASIC_Syntax_analyzer::f()
{
   int p, q;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   Create_Atom(8, p, q);
}
void MINI_BASIC_Syntax_analyzer::g()
{
   int p;
   stk.pop();
   p = stk.top();
   stk.pop();
   Create_Atom(9, p);
}
void MINI_BASIC_Syntax_analyzer::h()
{
   int p, q, r, s;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   r = stk.top();
   stk.pop();
   s = stk.top();
   stk.pop();
   Create_Atom(10, p, q, r, s);
}
void MINI_BASIC_Syntax_analyzer::i()
{
   int k1, k2;
   stk.pop();
   k1 = stk.top();
   stk.pop();
   k2 = stk.top();
   stk.pop();
   if (k1 != k2)
   {
      Error("Переменная в next операторе отлична от переменной for оператора");
   }
   stk.pop();
}
void MINI_BASIC_Syntax_analyzer::l()
{
   int p, q, r;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   r = stk.top();
   stk.pop();
   Create_Atom(12, p, q, r);
}
void MINI_BASIC_Syntax_analyzer::j()
{
   int p, q;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   Create_Atom(11, p, q);
}
void MINI_BASIC_Syntax_analyzer::k()
{
   int p;
   stk.pop();
   p = stk.top();
   stk.pop();
   Create_Atom(4, p);
}
void MINI_BASIC_Syntax_analyzer::n()
{
   int p, q, r;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   r = stk.top();
   stk.pop();
   Create_Atom(14, p, q, r);
}
void MINI_BASIC_Syntax_analyzer::m()
{
   int p, q, r;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   r = stk.top();
   stk.pop();
   Create_Atom(13, p, q, r);
}
void MINI_BASIC_Syntax_analyzer::o()
{
   int p, q, r;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   r = stk.top();
   stk.pop();
   Create_Atom(15, p, q, r);
}
void MINI_BASIC_Syntax_analyzer::p()
{
   int p, q, r;
   stk.pop();
   p = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   q = stk.top();
   stk.pop();
   r = stk.top();
   stk.pop();
   Create_Atom(16, p, q, r);
}
void MINI_BASIC_Syntax_analyzer::q()
{
   int k1, k2;
   stk.pop();
   k1 = stk.top();
   stk.pop();
   k2 = stk.top();
   stk.pop();
   Create_Atom(17, k1, k2);
}
void MINI_BASIC_Syntax_analyzer::r()
{
   int k1, k2;
   stk.pop();
   k1 = stk.top();
   stk.pop();
   k2 = stk.top();
   stk.pop();
   Create_Atom(18, k1, k2);
}

void MINI_BASIC_Syntax_analyzer::F1()
{
   stk.pop();
   stk.push(16);
   stk.push(2);
   Create_Atom(2, table_tokens[in].value);
   in = table_number_string.Get_NTS(table_tokens[in].value);
   in++;

}
void MINI_BASIC_Syntax_analyzer::F2()
{
   stk.pop();
   int k = stk.top();
}
void MINI_BASIC_Syntax_analyzer::F3()
{
   Create_Atom(2, table_tokens[in].value);
   in = table_number_string[table_tokens[in].value];
   in++;
}
void MINI_BASIC_Syntax_analyzer::F4()
{
   stk.pop();
   stk.push(4);
   stk.push(0);
   stk.push(table_tokens[in].value);
   stk.push(19);
   stk.push(3);
   stk.push(5);
   in++;
}
void MINI_BASIC_Syntax_analyzer::F5()
{
   stk.pop();
   stk.push(4);
   Create_Atom(4, table_tokens[in].value);
   in++;
}
void MINI_BASIC_Syntax_analyzer::F6()
{
   stk.pop();
   stk.push(4);
   stk.push(0);
   stk.push(0);
   stk.push(0);
   stk.push(0);
   stk.push(20);
   stk.push(5);
   stk.push(14);
   stk.push(5);
   stk.push(5);
   stk.push(8);
   stk.push(12);
   stk.push(8);
   stk.push(5);
   in++;
}
void MINI_BASIC_Syntax_analyzer::F7()
{
   stk.pop();
   stk.push(4);
   Create_Atom(5, table_tokens[in].value);
   in++;
}
void MINI_BASIC_Syntax_analyzer::F8()
{
   stk.pop();
   stk.push(4);
   Create_Atom(6);
   in++;
}
void MINI_BASIC_Syntax_analyzer::F9()
{
   int p, s, t, u, v, y;
   p = table_tokens[in].value;// Значение входа
   s = NTX;// Значение поставляемому вызовом процедуры НОВТX
   NTX++;
   t = NTX;// Значение поставляемому другим вызовом процедуры НОВТХ
   NTX++;
   u = NTM;// значение поставляемому вызовом процедуры НОВТАМ
   NTM++;
   v = NTM;//значение поставляемому другим вызовом процедуры НОВТАМ
   NTM++;
   y = in;
   stk.pop();
   stk.push(4);
   stk.push(v);
   stk.push(22);
   stk.push(u);
   stk.push(26);
   stk.push(t);
   stk.push(p);
   stk.push(25);
   stk.push(y);
   stk.push(0);
   stk.push(p);
   stk.push(24);
   stk.push(3);
   stk.push(13);
   stk.push(4);
   stk.push(v);
   stk.push(t);
   stk.push(s);
   stk.push(p);
   stk.push(23);
   stk.push(u);
   stk.push(22);
   stk.push(t);
   stk.push(0);
   stk.push(21);
   stk.push(2);
   stk.push(3);
   stk.push(s);
   stk.push(0);
   stk.push(21);
   stk.push(2);
   stk.push(5);
   stk.push(17);
   stk.push(0);
   stk.push(p);
   stk.push(19);
   stk.push(3);
   stk.push(5);
   in++;
}
void MINI_BASIC_Syntax_analyzer::F10()
{
   stk.pop();
   stk.push(5);
   in++;
}


void MINI_BASIC_Syntax_analyzer::printTA()
{

}

void MINI_BASIC_Syntax_analyzer::showStk()
{
}

void MINI_BASIC_Syntax_analyzer::Create_Big_Table()
{
   //<Программа>
   Control_Table[0][0] = &MINI_BASIC_Syntax_analyzer::F1;
   Control_Table[0][1] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][2] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][3] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][4] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][5] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][6] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][7] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][8] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][9] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][10] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][11] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][12] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][13] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][14] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][15] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][16] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][17] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][18] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][19] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][20] = &MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[0][22] = &MINI_BASIC_Syntax_analyzer::T1;

   //<Тело программы>
   Control_Table[1][0] = &MINI_BASIC_Syntax_analyzer::F3;
   Control_Table[1][1] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][2] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][3] = &MINI_BASIC_Syntax_analyzer::F2;
   Control_Table[1][4] = &MINI_BASIC_Syntax_analyzer::F4;
   Control_Table[1][5] = &MINI_BASIC_Syntax_analyzer::F9;
   Control_Table[1][6] = &MINI_BASIC_Syntax_analyzer::F5;
   Control_Table[1][7] = &MINI_BASIC_Syntax_analyzer::F7;
   Control_Table[1][8] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][9] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][10] = &MINI_BASIC_Syntax_analyzer::F6;
   Control_Table[1][11] = &MINI_BASIC_Syntax_analyzer::F8;
   Control_Table[1][12] = &MINI_BASIC_Syntax_analyzer::F2;
   Control_Table[1][13] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][14] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][15] = &MINI_BASIC_Syntax_analyzer::F12;
   Control_Table[1][16] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][17] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][18] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][19] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][20] = &MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[1][22] = &MINI_BASIC_Syntax_analyzer::T2;

   //<Шаг>
   Control_Table[2][0] = &MINI_BASIC_Syntax_analyzer::F11;
   Control_Table[2][1] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][2] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][3] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][4] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][5] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][6] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][7] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][8] = &MINI_BASIC_Syntax_analyzer::G2;
   Control_Table[2][9] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][10] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][11] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][12] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][13] = &MINI_BASIC_Syntax_analyzer::F10;
   Control_Table[2][14] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][15] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][16] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][17] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][18] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][19] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][20] = &MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[2][22] = &MINI_BASIC_Syntax_analyzer::T2;

   //<Другие строки>
   Control_Table[3][0] = &MINI_BASIC_Syntax_analyzer::F13;
   Control_Table[3][1] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][2] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][3] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][4] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][5] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][6] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][7] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][8] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][9] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][10] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][11] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][12] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][13] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][14] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][15] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][16] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][17] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][18] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][19] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][20] = &MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[3][22] = &MINI_BASIC_Syntax_analyzer::T2;

   //<Выражение>
   Control_Table[4][0] = &MINI_BASIC_Syntax_analyzer::K2;
   Control_Table[4][1] = &MINI_BASIC_Syntax_analyzer::F14;
   Control_Table[4][2] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[4][3] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[4][4] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[4][5] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[4][6] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[4][7] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[4][8] = &MINI_BASIC_Syntax_analyzer::F14;
   Control_Table[4][9] = &MINI_BASIC_Syntax_analyzer::K3;
   Control_Table[4][10] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[4][11] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[4][12] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[4][13] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[4][14] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[4][15] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[4][16] = &MINI_BASIC_Syntax_analyzer::F15;
   Control_Table[4][17] = &MINI_BASIC_Syntax_analyzer::F16;
   Control_Table[4][18] = &MINI_BASIC_Syntax_analyzer::K5;
   Control_Table[4][19] = &MINI_BASIC_Syntax_analyzer::K5;
   Control_Table[4][20] = &MINI_BASIC_Syntax_analyzer::K5;
   Control_Table[4][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[4][22] = &MINI_BASIC_Syntax_analyzer::T3;

   //<Терм>
   Control_Table[5][0] = &MINI_BASIC_Syntax_analyzer::K2;
   Control_Table[5][1] = &MINI_BASIC_Syntax_analyzer::F20;
   Control_Table[5][2] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[5][3] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[5][4] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[5][5] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[5][6] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[5][7] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[5][8] = &MINI_BASIC_Syntax_analyzer::F20;
   Control_Table[5][9] = &MINI_BASIC_Syntax_analyzer::K3;
   Control_Table[5][10] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[5][11] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[5][12] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[5][13] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[5][14] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[5][15] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[5][16] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[5][17] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[5][18] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[5][19] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[5][20] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[5][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[5][22] = &MINI_BASIC_Syntax_analyzer::T3;

   //<Множитель>
   Control_Table[6][0] = &MINI_BASIC_Syntax_analyzer::K2;
   Control_Table[6][1] = &MINI_BASIC_Syntax_analyzer::F24;
   Control_Table[6][2] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[6][3] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[6][4] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[6][5] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[6][6] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[6][7] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[6][8] = &MINI_BASIC_Syntax_analyzer::F24;
   Control_Table[6][9] = &MINI_BASIC_Syntax_analyzer::K3;
   Control_Table[6][10] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[6][11] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[6][12] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[6][13] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[6][14] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[6][15] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[6][16] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[6][17] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[6][18] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[6][19] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[6][20] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[6][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[6][22] = &MINI_BASIC_Syntax_analyzer::T3;

   //<первичное>
   Control_Table[7][0] = &MINI_BASIC_Syntax_analyzer::K2;
   Control_Table[7][1] = &MINI_BASIC_Syntax_analyzer::F28;
   Control_Table[7][2] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[7][3] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[7][4] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[7][5] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[7][6] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[7][7] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[7][8] = &MINI_BASIC_Syntax_analyzer::F27;
   Control_Table[7][9] = &MINI_BASIC_Syntax_analyzer::K3;
   Control_Table[7][10] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[7][11] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[7][12] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[7][13] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[7][14] = &MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[7][15] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[7][16] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[7][17] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[7][18] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[7][19] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[7][20] = &MINI_BASIC_Syntax_analyzer::K6;
   Control_Table[7][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[7][22] = &MINI_BASIC_Syntax_analyzer::T3;

   //<E-список>
   Control_Table[8][0] = &MINI_BASIC_Syntax_analyzer::F19;
   Control_Table[8][1] = &MINI_BASIC_Syntax_analyzer::K7;
   Control_Table[8][2] = &MINI_BASIC_Syntax_analyzer::F19;
   Control_Table[8][3] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][4] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][5] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][6] = &MINI_BASIC_Syntax_analyzer::F19;
   Control_Table[8][7] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][8] = &MINI_BASIC_Syntax_analyzer::K7;
   Control_Table[8][9] = &MINI_BASIC_Syntax_analyzer::F19;
   Control_Table[8][10] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][11] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][12] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][13] = &MINI_BASIC_Syntax_analyzer::F19;
   Control_Table[8][14] = &MINI_BASIC_Syntax_analyzer::F19;
   Control_Table[8][15] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][16] = &MINI_BASIC_Syntax_analyzer::F17;
   Control_Table[8][17] = &MINI_BASIC_Syntax_analyzer::F18;
   Control_Table[8][18] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][19] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][20] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][21] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[8][22] = &MINI_BASIC_Syntax_analyzer::O;

   //<T-список>
   Control_Table[9][0] = &MINI_BASIC_Syntax_analyzer::F23;
   Control_Table[9][1] = &MINI_BASIC_Syntax_analyzer::K7;
   Control_Table[9][2] = &MINI_BASIC_Syntax_analyzer::F23;
   Control_Table[9][3] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][4] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][5] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][6] = &MINI_BASIC_Syntax_analyzer::F23;
   Control_Table[9][7] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][8] = &MINI_BASIC_Syntax_analyzer::K7;
   Control_Table[9][9] = &MINI_BASIC_Syntax_analyzer::F23;
   Control_Table[9][10] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][11] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][12] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][13] = &MINI_BASIC_Syntax_analyzer::F23;
   Control_Table[9][14] = &MINI_BASIC_Syntax_analyzer::F23;
   Control_Table[9][15] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][16] = &MINI_BASIC_Syntax_analyzer::F23;
   Control_Table[9][17] = &MINI_BASIC_Syntax_analyzer::F23;
   Control_Table[9][18] = &MINI_BASIC_Syntax_analyzer::F21;
   Control_Table[9][19] = &MINI_BASIC_Syntax_analyzer::F22;
   Control_Table[9][20] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][21] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[9][22] = &MINI_BASIC_Syntax_analyzer::O;

   //<F-список>
   Control_Table[10][0] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][1] = &MINI_BASIC_Syntax_analyzer::K7;
   Control_Table[10][2] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][3] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[10][4] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[10][5] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[10][6] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][7] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[10][8] = &MINI_BASIC_Syntax_analyzer::K7;
   Control_Table[10][9] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][10] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[10][11] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[10][12] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[10][13] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][14] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][15] = &MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[10][16] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][17] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][18] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][19] = &MINI_BASIC_Syntax_analyzer::F26;
   Control_Table[10][20] = &MINI_BASIC_Syntax_analyzer::F25;
   Control_Table[10][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[10][22] = &MINI_BASIC_Syntax_analyzer::T2;

   //<Отношение>
   Control_Table[11][0] = &MINI_BASIC_Syntax_analyzer::E2;
   Control_Table[11][1] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][2] = &MINI_BASIC_Syntax_analyzer::b;
   Control_Table[11][3] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][4] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][5] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][6] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][7] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][8] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][9] = &MINI_BASIC_Syntax_analyzer::E3;
   Control_Table[11][10] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][11] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][12] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][13] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][14] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][15] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][16] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][17] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][18] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][19] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][20] = &MINI_BASIC_Syntax_analyzer::E1;
   Control_Table[11][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[11][22] = &MINI_BASIC_Syntax_analyzer::T3;

   //<Конец цикла>
   Control_Table[12][0] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][1] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][2] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][3] = &MINI_BASIC_Syntax_analyzer::d;
   Control_Table[12][4] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][5] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][6] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][7] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][8] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][9] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][10] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][11] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][12] = &MINI_BASIC_Syntax_analyzer::L;
   Control_Table[12][13] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][14] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][15] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][16] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][17] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][18] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][19] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][20] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][21] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[12][22] = &MINI_BASIC_Syntax_analyzer::O;

   //<Переход>
   Control_Table[13][0] = &MINI_BASIC_Syntax_analyzer::M2;
   Control_Table[13][1] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][2] = &MINI_BASIC_Syntax_analyzer::M3;
   Control_Table[13][3] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][4] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][5] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][6] = &MINI_BASIC_Syntax_analyzer::b;
   Control_Table[13][7] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][8] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][9] = &MINI_BASIC_Syntax_analyzer::M4;
   Control_Table[13][10] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][11] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][12] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][13] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][14] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][15] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][16] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][17] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][18] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][19] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][20] = &MINI_BASIC_Syntax_analyzer::M1;
   Control_Table[13][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[13][22] = &MINI_BASIC_Syntax_analyzer::T3;

   //<Правая скобка>
   Control_Table[14][0] = &MINI_BASIC_Syntax_analyzer::N2;
   Control_Table[14][1] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][2] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][3] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][4] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][5] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][6] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][7] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][8] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][9] = &MINI_BASIC_Syntax_analyzer::a;
   Control_Table[14][10] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][11] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][12] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][13] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][14] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][15] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][16] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][17] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][18] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][19] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][20] = &MINI_BASIC_Syntax_analyzer::N1;
   Control_Table[14][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[14][22] = &MINI_BASIC_Syntax_analyzer::T3;

   //<Конец>
   Control_Table[15][0] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][1] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][2] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][3] = &MINI_BASIC_Syntax_analyzer::K;
   Control_Table[15][4] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][5] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][6] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][7] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][8] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][9] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][10] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][11] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][12] = &MINI_BASIC_Syntax_analyzer::a;
   Control_Table[15][13] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][14] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][15] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][16] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][17] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][18] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][19] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][20] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][21] = &MINI_BASIC_Syntax_analyzer::O;
   Control_Table[15][22] = &MINI_BASIC_Syntax_analyzer::O;

   //<До>
   Control_Table[16][0] = &MINI_BASIC_Syntax_analyzer::P2;
   Control_Table[16][1] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][2] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][3] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][4] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][5] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][6] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][7] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][8] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][9] = &MINI_BASIC_Syntax_analyzer::P3;
   Control_Table[16][10] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][11] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][12] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][13] = &MINI_BASIC_Syntax_analyzer::a;
   Control_Table[16][14] = &MINI_BASIC_Syntax_analyzer::P4;
   Control_Table[16][15] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][16] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][17] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][18] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][19] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][20] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[16][22] = &MINI_BASIC_Syntax_analyzer::T3;

   //<До>
   Control_Table[17][0] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][1] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][2] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][3] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][4] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][5] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][6] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][7] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][8] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][9] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][10] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][11] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][12] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][13] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][14] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][15] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][16] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][17] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][18] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][19] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][20] = &MINI_BASIC_Syntax_analyzer::P;
   Control_Table[17][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[17][22] = &MINI_BASIC_Syntax_analyzer::c;

   //{Присвоить}
   Control_Table[16][0] = &MINI_BASIC_Syntax_analyzer::P2;
   Control_Table[16][1] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][2] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][3] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][4] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][5] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][6] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][7] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][8] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][9] = &MINI_BASIC_Syntax_analyzer::P3;
   Control_Table[16][10] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][11] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][12] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][13] = &MINI_BASIC_Syntax_analyzer::a;
   Control_Table[16][14] = &MINI_BASIC_Syntax_analyzer::P4;
   Control_Table[16][15] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][16] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][17] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][18] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][19] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][20] = &MINI_BASIC_Syntax_analyzer::P1;
   Control_Table[16][21] = &MINI_BASIC_Syntax_analyzer::C;
   Control_Table[16][22] = &MINI_BASIC_Syntax_analyzer::T3;

   for (int i = 0; i < 23; i++)
      Control_Table[17][i] = &MINI_BASIC_Syntax_analyzer::d;

   for (int i = 0; i < 23; i++)
      Control_Table[18][i] = &MINI_BASIC_Syntax_analyzer::e;

   for (int i = 0; i < 23; i++)
      Control_Table[19][i] = &MINI_BASIC_Syntax_analyzer::f;

   for (int i = 0; i < 23; i++)
      Control_Table[20][i] = &MINI_BASIC_Syntax_analyzer::g;

   for (int i = 0; i < 23; i++)
      Control_Table[21][i] = &MINI_BASIC_Syntax_analyzer::h;

   for (int i = 0; i < 23; i++)
      Control_Table[22][i] = &MINI_BASIC_Syntax_analyzer::i;

   for (int i = 0; i < 23; i++)
      Control_Table[23][i] = &MINI_BASIC_Syntax_analyzer::j;

   for (int i = 0; i < 23; i++)
      Control_Table[24][i] = &MINI_BASIC_Syntax_analyzer::k;

   for (int i = 0; i < 23; i++)
      Control_Table[25][i] = &MINI_BASIC_Syntax_analyzer::l;

   for (int i = 0; i < 23; i++)
      Control_Table[26][i] = &MINI_BASIC_Syntax_analyzer::m;

   for (int i = 0; i < 23; i++)
      Control_Table[27][i] = &MINI_BASIC_Syntax_analyzer::n;

   for (int i = 0; i < 23; i++)
      Control_Table[28][i] = &MINI_BASIC_Syntax_analyzer::o;

   for (int i = 0; i < 23; i++)
      Control_Table[29][i] = &MINI_BASIC_Syntax_analyzer::p;

   for (int i = 0; i < 23; i++)
      Control_Table[30][i] = &MINI_BASIC_Syntax_analyzer::q;

   for (int i = 0; i < 23; i++)
      Control_Table[31][i] = &MINI_BASIC_Syntax_analyzer::r;
};
