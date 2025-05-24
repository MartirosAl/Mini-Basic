
#include "MB Sintax analyzer.h"
using namespace std;
int main()
{ 
   MINI_BASIC_Lexical_analyzer A;
   A.start_LA("Test1.txt");
   A.Print_table_tokens();
   A.Print_table_operands();
   A.Print_table_labels();
   
   MINI_BASIC_Syntax_analyzer B;
   B.start_SA("Test1.txt");
   cout << "TA" << endl;
   B.PrintTA();
   cout << "Stk" << endl;
   B.PrintStk();
   return 0;
}
