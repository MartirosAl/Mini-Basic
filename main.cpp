
#include "MINI_BASIC.h"
using namespace std;
int main()
{ 
   MINI_BASIC A("Test1.txt");
   A.Print_table_tokens();
   A.Print_table_operands();
   A.Print_table_labels();
   return 0;
}