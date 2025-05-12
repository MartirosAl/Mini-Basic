#include "MB Sintax analyzer.h"

MINI_BASIC_Syntax_analyzer::MINI_BASIC_Syntax_analyzer()
{
   Create_Big_Table();
}

void MINI_BASIC_Syntax_analyzer::Create_Big_Table()
{
   //<Программа>
   Control_Table[0][0]   = MINI_BASIC_Syntax_analyzer::Process1;
   Control_Table[0][1]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][2]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][3]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][4]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][5]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][6]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][7]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][8]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][9]   = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][10]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][11]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][12]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][13]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][14]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][15]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][16]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][17]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][18]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][19]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][20]  = MINI_BASIC_Syntax_analyzer::A;
   Control_Table[0][21]  = MINI_BASIC_Syntax_analyzer::C;
   Control_Table[0][22]  = MINI_BASIC_Syntax_analyzer::T1;

   //<Тело программы>
   Control_Table[1][0]  = MINI_BASIC_Syntax_analyzer::Process3;
   Control_Table[1][1]  = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][2]  = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][3]  = MINI_BASIC_Syntax_analyzer::Process2;
   Control_Table[1][4]  = MINI_BASIC_Syntax_analyzer::Process4;
   Control_Table[1][5]  = MINI_BASIC_Syntax_analyzer::Process9;
   Control_Table[1][6]  = MINI_BASIC_Syntax_analyzer::Process5;
   Control_Table[1][7]  = MINI_BASIC_Syntax_analyzer::Process7;
   Control_Table[1][8]  = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][9]  = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][10] = MINI_BASIC_Syntax_analyzer::Process6;
   Control_Table[1][11] = MINI_BASIC_Syntax_analyzer::Process8;
   Control_Table[1][12] = MINI_BASIC_Syntax_analyzer::Process2;
   Control_Table[1][13] = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][14] = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][15] = MINI_BASIC_Syntax_analyzer::Process12;
   Control_Table[1][16] = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][17] = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][18] = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][19] = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][20] = MINI_BASIC_Syntax_analyzer::B;
   Control_Table[1][21] = MINI_BASIC_Syntax_analyzer::C;
   Control_Table[1][22] = MINI_BASIC_Syntax_analyzer::T2;

   //<Шаг>
   Control_Table[2][0]  = MINI_BASIC_Syntax_analyzer::Process11;
   Control_Table[2][1]  = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][2]  = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][3]  = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][4]  = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][5]  = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][6]  = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][7]  = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][8]  = MINI_BASIC_Syntax_analyzer::G2;
   Control_Table[2][9]  = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][10] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][11] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][12] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][13] = MINI_BASIC_Syntax_analyzer::Process10;
   Control_Table[2][14] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][15] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][16] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][17] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][18] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][19] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][20] = MINI_BASIC_Syntax_analyzer::G1;
   Control_Table[2][21] = MINI_BASIC_Syntax_analyzer::C;
   Control_Table[2][22] = MINI_BASIC_Syntax_analyzer::T2;

   //<Другие строки>
   Control_Table[3][0] = MINI_BASIC_Syntax_analyzer::Process13;
   Control_Table[3][1] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][2] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][3] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][4] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][5] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][6] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][7] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][8] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][9] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][10] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][11] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][12] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][13] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][14] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][15] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][16] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][17] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][18] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][19] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][20] = MINI_BASIC_Syntax_analyzer::D;
   Control_Table[3][21] = MINI_BASIC_Syntax_analyzer::C;
   Control_Table[3][22] = MINI_BASIC_Syntax_analyzer::T2;

   //<Выражение>
   Control_Table[3][0]  = MINI_BASIC_Syntax_analyzer::K2;
   Control_Table[3][1]  = MINI_BASIC_Syntax_analyzer::Process14;
   Control_Table[3][2]  = MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[3][3]  = MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[3][4]  = MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[3][5]  = MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[3][6]  = MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[3][7]  = MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[3][8]  = MINI_BASIC_Syntax_analyzer::Process14;
   Control_Table[3][9]  = MINI_BASIC_Syntax_analyzer::K3;
   Control_Table[3][10] = MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[3][11] = MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[3][12] = MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[3][13] = MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[3][14] = MINI_BASIC_Syntax_analyzer::K1;
   Control_Table[3][15] = MINI_BASIC_Syntax_analyzer::K4;
   Control_Table[3][16] = MINI_BASIC_Syntax_analyzer::Process15;
   Control_Table[3][17] = MINI_BASIC_Syntax_analyzer::Process16;
   Control_Table[3][18] = MINI_BASIC_Syntax_analyzer::K5;
   Control_Table[3][19] = MINI_BASIC_Syntax_analyzer::K5;
   Control_Table[3][20] = MINI_BASIC_Syntax_analyzer::K5;
   Control_Table[3][21] = MINI_BASIC_Syntax_analyzer::C;
   Control_Table[3][22] = MINI_BASIC_Syntax_analyzer::T2;
}
