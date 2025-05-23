
#include "MB Lexical analyzer.h"
#include "MB Lexical analyzer.h"
using namespace std;
int main()
{ 
   MINI_BASIC_Lexical_analyzer A;
   A.start_LA("Test1.txt");
   A.Print_table_tokens();
   A.Print_table_operands();
   A.Print_table_labels();
   return 0;
}