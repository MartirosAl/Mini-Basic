
#include "MB Sintax analyzer.h"
using namespace std;
int main()
{ 
   string name_file = "Test4.txt";
   MINI_BASIC_Lexical_analyzer A;
   //A.start_LA(name_file);
   //A.Print_table_tokens();
   //A.Print_table_operands();
   //A.Print_table_labels();
   //
   MINI_BASIC_Syntax_analyzer B;
   B.start_SA(name_file);
   B.PrintTA();
   B.PrintStk();
   return 0;
}
