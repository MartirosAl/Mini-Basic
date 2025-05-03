#pragma once
#include "MINI_BASIC.h"


SymbolicToken MINI_BASIC::Transliterator(int character)
{
    SymbolicToken result;
    result.value = 0;
    if (character >= 'A' && character <= 'Z')
    {
        result.token_class = SymbolicTokenType::LETTER;
        result.value = character - 'A' + 1;
    }
    else if (character >= '0' && character <= '9')
    {
        result.token_class = SymbolicTokenType::DIGIT;
        result.value = character - '0' + 1;
    }
    else if (character == '+')
    {
        result.token_class = SymbolicTokenType::ARITHMETIC_OPERATION_S;
        result.value = 1;
    }    
    else if (character == '-')
    {
        result.token_class = SymbolicTokenType::ARITHMETIC_OPERATION_S;
        result.value = 2;
    }    
    else if (character == '*')
    {
        result.token_class = SymbolicTokenType::ARITHMETIC_OPERATION_S;
        result.value = 3;
    }    
    else if (character == '/')
    {
        result.token_class = SymbolicTokenType::ARITHMETIC_OPERATION_S;
        result.value = 4;
    }    
    else if (character == '^')
    {
        result.token_class = SymbolicTokenType::ARITHMETIC_OPERATION_S;
        result.value = 5;
    }
    else if (character == '=')
    {
        result.token_class = SymbolicTokenType::RELATION_S;
        result.value = 1;
    }
    else if (character == '<')
    {
       result.token_class = SymbolicTokenType::RELATION_S;
       result.value = 2;
    }
    else if (character == '>')
    {
       result.token_class = SymbolicTokenType::RELATION_S;
       result.value = 3;
    }
    else if (character == '(')
    {
        result.token_class = SymbolicTokenType::O_BRACE_S;
        result.value = (int)character;
    }
    else if (character == ')')
    {
        result.token_class = SymbolicTokenType::C_BRACE_S;
        result.value = (int)character;
    }
    else if (character == '.')
    {
       result.token_class = SymbolicTokenType::DOT;
       result.value = (int)character;
    }
    else if (character == ' ' || character == '\t')
    {
        result.token_class = SymbolicTokenType::SPACE;
        result.value = (int)character;
    }
    else if (character == '\n')
    {
        result.token_class = SymbolicTokenType::LF;
        result.value = (int)character;
    }
    else if (character == EOF)
    {
        result.token_class = SymbolicTokenType::END_OF_FILE_S;
        result.value = (int)character;
    }
    else
    {
        result.token_class = SymbolicTokenType::ERROR_S;
        result.value = (int)character;
    }
    return result;
}

void MINI_BASIC::next()
{
   char temp;
   stream.get(temp);
   character = Transliterator(temp);
}

MINI_BASIC::MINI_BASIC(string name_file)
{

    stream.open(name_file);
    if (!stream)
    {
        cout << "Couldn't open the file " << name_file << endl;
        return;
    }

    //Tests flags
    bool flag_work_state = false;

    //Initial state
    q = &MINI_BASIC::A1;
    next();

    //Initial table operands
    for (int i = 1; i <= 286; i++)
       table_operands[i] = 0;

    func prev_func = q;

    while (true)
    {
        (this->*q)();
        if (q == &MINI_BASIC::Error)
            return;
        if (flag_work_state)
            cout << character.value << endl;

        if (q == &MINI_BASIC::A3)
        {
            cout << "Goodbye World!" << endl;
            break;
        }

        //if (prev_func != q)
        //{
        //   next();
        //   prev_func = q;
        //}
    }

}

//начало строки
void MINI_BASIC::A1()
{
   switch (character.token_class)
   {
   case DIGIT:
      E2a();
      break;
   case SPACE:
      next();
      q = A1;
      break;
   case LF:
      q = A1;
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error();
      break;
   }
}

//искать перем., конст., опер., СR, (, ), отнош.
void MINI_BASIC::A2()
{
   switch (character.token_class)
   {
   case LETTER:
      C2a();
      break;
   case DIGIT:
      D1a();
      break;
   case ARITHMETIC_OPERATION_S:
      A2a();
      break;
   case RELATION_S:
      H1a();
      break;
   case O_BRACE_S:
      A2h();
      break;
   case C_BRACE_S:
      A3b();
      break;
   case DOT:
      q = D6;
      break;
   case SPACE:
      next();
      q = A2;
      break;
   case LF:
      q = A1;
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error();
      break;
   }
}

//искать зарезерв. слово, опер., СR, (, ), отнош
void MINI_BASIC::A3()
{
   switch (character.token_class)
   {
   case LETTER:
      B1a();
      break;
   case DIGIT:
      D1a();
      break;
   case ARITHMETIC_OPERATION_S:
      A2a();
      break;
   case RELATION_S:
      H1a();
      break;
   case O_BRACE_S:
      A2h();
      break;
   case C_BRACE_S:
      A3b();
      break;
   case DOT:
      q = D6;
      break;
   case SPACE:
      next();
      q = A3;
      break;
   case LF:
      q = A1;
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error();
      break;
   }
}

//Обнаружить зарезерв.слово
void MINI_BASIC::B1()
{
   switch (character.token_class)
   {
   case LETTER:
      M1();
      break;
   case SPACE:
      next();
      q = B1;
      break;
   default:
      Error();
      break;
   }
}

//искать переменную
void MINI_BASIC::C1()
{
   switch (character.token_class)
   {
   case LETTER:
      C2d();
      break;
   case SPACE:
      next();
      q = C1;
      break;
   case END_OF_FILE_S:
      q = EXIT3;
      break;
   default:
      Error();
      break;
   }
}

//завершить обработку переменной
void MINI_BASIC::C2()
{
   switch (character.token_class)
   {
   case LETTER:
      B1b();
      break;
   case DIGIT:
      A3a();
      break;
   case ARITHMETIC_OPERATION_S:
      A2g();
      break;
   case RELATION_S:
      H1b();
      break;
   case O_BRACE_S:
      A2k();
      break;
   case C_BRACE_S:
      A3c();
      break;
   case SPACE:
      next();
      q = C2;
      break;
   case LF:
      A1a();
      break;
   case END_OF_FILE_S:
      q = EXIT4;
      break;
   default:
      Error();
      break;
   }
}

//завершить обработку целой части
void MINI_BASIC::D1()
{
   switch (character.token_class)
   {
   case LETTER:
      M2();
      break;
   case DIGIT:
      D1b();
      break;
   case ARITHMETIC_OPERATION_S:
      A2c();
      break;
   case RELATION_S:
      H1c();
      break;
   case O_BRACE_S:
      A2l();
      break;
   case C_BRACE_S:
      A3d();
      break;
   case DOT:
      D2c();
      break;
   case SPACE:
      next();
      q = D2;
      break;
   case LF:
      A1b();
      break;
   case END_OF_FILE_S:
      q = EXIT3;
      break;
   default:
      Error();
      break;
   }
}

//завершить обработку дробной части
void MINI_BASIC::D2()
{
   switch (character.token_class)
   {
   case LETTER:
      M3();
      break;
   case DIGIT:
      D2a();
      break;
   case ARITHMETIC_OPERATION_S:
      A2d();
      break;
   case RELATION_S:
      H1d();
      break;
   case O_BRACE_S:
      A2m();
      break;
   case C_BRACE_S:
      A3e();
      break;
   case SPACE:
      next();
      q = D2;
      break;
   case LF:
      A1c();
      break;
   case END_OF_FILE_S:
      q = EXIT4;
      break;
   default:
      Error();
      break;
   }
}

//после буквы Е
void MINI_BASIC::D3()
{
   switch (character.token_class)
   {
   case DIGIT:
      D5a();
      break;
   case ARITHMETIC_OPERATION_S:
      D4a();
      break;
   case SPACE:
      next();
      q = D3;
      break;
   default:
      Error();
      break;
   }
}

//после буквы Е и знака
void MINI_BASIC::D4()
{
   switch (character.token_class)
   {
   case DIGIT:
      D2b();
      break;
   case SPACE:
      next();
      q = D4;
      break;
   default:
      Error();
      break;
   }
}

//завершить обработку порядка
void MINI_BASIC::D5()
{
   switch (character.token_class)
   {
   case LETTER:
      B1c();
      break;
   case DIGIT:
      D5c();
      break;
   case ARITHMETIC_OPERATION_S:
      A2e();
      break;
   case RELATION_S:
      H1c();
      break;
   case O_BRACE_S:
      A2n();
      break;
   case C_BRACE_S:
      A3f();
      break;
   case SPACE:
      next();
      q = D5;
      break;
   case LF:
      A1d();
      break;
   case END_OF_FILE_S:
      q = EXIT5;
      break;
   default:
      Error();
      break;
   }
}

//после первой десятичной точки
void MINI_BASIC::D6()
{
   switch (character.token_class)
   {
   case DIGIT:
      D2b();
      break;
   case SPACE:
      lex_class_reg = OPERAND;
      next();
      q = D6;
      break;
   default:
      Error();
      break;
   }
}

//искать номер строки
void MINI_BASIC::E1()
{
   switch (character.token_class)
   {
   case DIGIT:
      E2b();
      break;
   case SPACE:
      next();
      q = E1;
   default:
      Error();
      break;
   }
}

//оставшаяся часть номера строки
void MINI_BASIC::E2()
{
   switch (character.token_class)
   {
   case LETTER:
      B1e();
      break;
   case DIGIT:
      E2c();
      break;
   case ARITHMETIC_OPERATION_S:
      A2f();
      break;
   case RELATION_S:
      H1f();
      break;
   case O_BRACE_S:
      A2j();
      break;
   case C_BRACE_S:
      A3g();
      break;
   case SPACE:
      next();
      q = E2;
      break;
   case LF:
      A1e();
      break;
   default:
      Error();
      break;
   }
}

//искать переменную и =
void MINI_BASIC::F1()
{
   switch (character.token_class)
   {
   case LETTER:
      F2a();
      break;
   case SPACE:
      next();
      q = F1;
      break;
   default:
      Error();
      break;
   }
}

//оставшаяся часть переменной
void MINI_BASIC::F2()
{
   switch (character.token_class)
   {
   case DIGIT:
      F3a();
      break;
   case RELATION_S:
      A2o();
      break;
   case SPACE:
      next();
      q = F2;
      break;
   default:
      Error();
      break;
   }
}

//искать =
void MINI_BASIC::F3()
{
   switch (character.token_class)
   {
   case RELATION_S:
      A2o();
      break;
   case SPACE:
      next();
      q = F3;
      break;
   default:
      Error();
      break;
   }
}

//найти СR (комментарий)
void MINI_BASIC::G1()
{
   switch (character.token_class)
   {
   case LETTER:
      q = G1;
      break;
   case DIGIT:
      q = G1;
      break;
   case ARITHMETIC_OPERATION_S:
      q = G1;
      break;
   case RELATION_S:
      q = G1;
      break;
   case O_BRACE_S:
      q = G1;
      break;
   case C_BRACE_S:
      q = G1;
      break;
   case DOT:
      q = G1;
      break;
   case SPACE:
      next();
      q = G1;
      break;
   case LF:
      q = A1;
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error();
      break;
   }
}

//завершить обработку отношения
void MINI_BASIC::H1()
{
   switch (character.token_class)
   {
   case LETTER:
      C2b();
      break;
   case DIGIT:
      D1c();
      break;
   case ARITHMETIC_OPERATION_S:
      A2g();
      break;
   case RELATION_S:
      A2p();
      break;
   case O_BRACE_S:
      A2k();
      break;
   case C_BRACE_S:
      A3c();
      break;
   case DOT:
      D6a();
      break;
   case SPACE:
      next();
      q = H1;
      break;
   case LF:
      A1a();
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error();
      break;
   }
}

void MINI_BASIC::DA1D()
{
   order_reg = 0;

   table_operands[ptr_to_free] = number_reg;
   ptr_to_free++;
   
}

void MINI_BASIC::DA2D()
{

    string temp;
    if (to_string(number_reg).length() - counter_reg <= 0)
    {
       temp = "0.";

       for (int i = 0; i < abs((int)to_string(number_reg).length() - counter_reg) - 1; i++)
          temp += '0';
       table_operands[ptr_to_free] = stold(temp + to_string(number_reg));

    }
    else
    {
       temp = to_string(number_reg);
       reverse(temp.begin(), temp.end());


       number_reg /= pow(10, (to_string(number_reg).length() - counter_reg));

       temp.resize(counter_reg);
       reverse(temp.begin(), temp.end());

       table_operands[ptr_to_free] = stold(to_string(number_reg) + '.' + temp);
    }
    ptr_to_free++;

}

void MINI_BASIC::DA3D()
{
    if (order_reg == -1)
    {
        order_reg = -order_reg;
    }

    counter_reg -= order_reg;
    string temp = '\0';
    if (counter_reg > 0)
    {
       DA2D();
    }
    else
    {

       for (int i = 0; i < abs(counter_reg); i++)
          temp += '0';
       table_operands[ptr_to_free] = stold(to_string(number_reg) + temp);
       ptr_to_free++;
    }

}

void MINI_BASIC::DA1E()
{
   index_cur_number = table_number_string.insert(number_string_reg);
}


void MINI_BASIC::A1a()
{
    Create_Token();
    next();
    q = A1;
}

void MINI_BASIC::A1b()
{
    DA1D();
    A1a();
    q = A1;
}

void MINI_BASIC::A1c()
{
    DA2D();
    A1a();
    q = A1;
}

void MINI_BASIC::A1d()
{
    DA3D();
    A1a();
    q = A1;
}

void MINI_BASIC::A1e()
{
    DA1E();
    A1a();
    q = A1;
}

void MINI_BASIC::A2a()
{
    lex_class_reg = ARITHMETIC_OPERATIONS;
    A2b();
    q = A2;
}

void MINI_BASIC::A2b()
{
    Create_Token();
    next();
    q = A2;
}

void MINI_BASIC::A2c()
{
    DA1D();
    A2g();
    q = A2;
}

void MINI_BASIC::A2d()
{
    DA2D();
    A2g();
    q = A2;
}

void MINI_BASIC::A2e()
{
    DA3D();
    A2g();
    q = A2;
}

void MINI_BASIC::A2f()
{
    DA1E();
    A2g();
    q = A2;
}

void MINI_BASIC::A2g()
{
    Create_Token();
    A2a();
    q = A2;
}

void MINI_BASIC::A2h()
{
    lex_class_reg = L_BRACKET;
    Create_Token();
    next();
    q = A2;
}

void MINI_BASIC::A2j()
{
    DA1E();
    A2k();
    q = A2;
}

void MINI_BASIC::A2k()
{
    Create_Token();
    A2h();
    q = A2;
}

void MINI_BASIC::A2l()
{
    DA1D();
    A2k();
    q = A2;
}

void MINI_BASIC::A2m()
{
    DA2D();
    A2k();
    q = A2;
}

void MINI_BASIC::A2n()
{
    DA3D();
    A2k();
    q = A2;
}

void MINI_BASIC::A2o()
{
   if (char_class_value_reg == 1)
      A2b();
   else
   {
      Error_Handler();
      return;
   }
   q = A2;
}

void MINI_BASIC::A2p()
{
   switch (relation_value_reg)
   {
   case 1:
      Error_Handler();
   case 2:
      if (character.value == 1/* = */)
         relation_value_reg = 4;
      else if (character.value == 3/* > */)
         relation_value_reg = 6;
      else
         Error_Handler();
   case 3:
      if (character.value == 1/* = */)
         relation_value_reg = 5;
      else
         Error_Handler();
   }
   A2b();
   q = A2;
}

void MINI_BASIC::A2q()
{
   lex_class_reg = END;
   A2b();
   q = A2;
}

void MINI_BASIC::A2r()
{
   lex_class_reg = IF;
   A2b();
   q = A2;
}

void MINI_BASIC::A2s()
{
   lex_class_reg = RETURN;
   A2b();
   q = A2;
}

void MINI_BASIC::A2t()
{
   lex_class_reg = STEP;
   A2b();
   q = A2;
}

void MINI_BASIC::A2u()
{
   lex_class_reg = TO;
   A2b();
   q = A2;
}

void MINI_BASIC::A3a()
{
   //имя переменой
   index_reg += (character.value + 1) * 26;
   Create_Token();
   next();
   q = A2;
}

void MINI_BASIC::A3b()
{
   lex_class_reg = R_BRACKET;
   Create_Token();
   next();
   q = A3;
}

void MINI_BASIC::A3c()
{
   Create_Token();
   A3b();
   q = A3;
}

void MINI_BASIC::A3d()
{
   DA1D();
   A3c();
   q = A3;
}

void MINI_BASIC::A3e()
{
   DA2D();
   A3c();
   q = A3;
}

void MINI_BASIC::A3f()
{
   DA3D();
   A3c();
   q = A3;
}

void MINI_BASIC::A3g()
{
   DA1E();
   A3c();
   q = A3;
}

void MINI_BASIC::B1a()
{
   detection_reg = table_first_vector[character.value];
   next();
   q = B1;
}

void MINI_BASIC::B1b()
{
   Create_Token();
   B1a();
   q = B1;
}

void MINI_BASIC::B1c()
{
   DA3D();
   B1b();
   q = B1;
}

void MINI_BASIC::B1d()
{
   detection_reg++;
   next();
   q = B1;
}

void MINI_BASIC::B1e()
{
   DA1E();
   B1b();
   q = B1;
}

void MINI_BASIC::C1a()
{
   lex_class_reg = NEXT;
   next();
   q = C1;
}

void MINI_BASIC::C2a()
{
   lex_class_reg = OPERAND;
   C2d();
   q = C2;
}

void MINI_BASIC::C2b()
{
   Create_Token();
   C2a();
   q = C2;
}

void MINI_BASIC::C2d()
{
   index_reg = character.value;
   next();
   q = C2;
}

void MINI_BASIC::D1a()
{
   lex_class_reg = OPERAND;
   number_reg = character.value;
   next();
   q = D1;
}

void MINI_BASIC::D1b()
{
   number_reg *= 10;
   number_reg += character.value;
   next();
   q = D1;
}

void MINI_BASIC::D1c()
{
   Create_Token();
   D1a();
   q = D1;
}

void MINI_BASIC::D2a()
{
   counter_reg += 1;
   number_reg *= 10;
   number_reg += character.value;
   next();
   q = D2;
}

//🔥🔥🔥🔥🔥🔥🧯
void MINI_BASIC::D2b()
{
   counter_reg = 1;
   number_reg = character.value;
   next();
   q = D2;
}

void MINI_BASIC::D2c()
{
   counter_reg = 0;
   next();
   q = D2;
}

void MINI_BASIC::D3a()
{
   counter_reg = 0;
   next();
   q = D3;
}

void MINI_BASIC::D4a()
{
   if (character.value == 1)
      order_sign_reg = 1;
   else if (character.value == 2)
      order_sign_reg = -1;
   else
      Error_Handler();
   next();
   q = D4;
}

void MINI_BASIC::D5a()
{
   char_class_value_reg = +1;
   D5b();
   q = D5;
}

void MINI_BASIC::D5b()
{
   order_reg = character.value;
   next();
   q = D5;
}

void MINI_BASIC::D5c()
{
   order_reg *= 10;
   order_reg = character.value;
   next();
   q = D5;
}

void MINI_BASIC::D6a()
{
   Create_Token();
   lex_class_reg = OPERAND;
   next();
   q = D6;
}

void MINI_BASIC::E1a()
{
   lex_class_reg = GOTO;
   next();
   q = E1;
}

void MINI_BASIC::E1b()
{
   lex_class_reg = GOSUB;
   next();
   q = E1;
}

void MINI_BASIC::E2a()
{
   lex_class_reg = LABLE;
   E2b();
   q = E2;
}

void MINI_BASIC::E2b()
{
   number_string_reg = character.value;
   next();
   q = E2;
}

void MINI_BASIC::E2c()
{
   number_string_reg *= 10;
   number_string_reg += character.value;
   next();
   q = E2;
}

void MINI_BASIC::F1a()
{
   lex_class_reg = FOR;
   next();
   q = F1;
}

void MINI_BASIC::F1b()
{
   lex_class_reg = TO;
   next();
   q = F1;
}

void MINI_BASIC::F2a()
{
   index_reg = character.value;
   next();
   q = F2;
}

void MINI_BASIC::F3a()
{
   index_reg = (character.value + 1) * 26;
   next();
   q = F3;
}

void MINI_BASIC::G1a()
{
   lex_class_reg = COMMENT;
   Create_Token();
   next();
   q = G1;
}

void MINI_BASIC::H1a()
{
   relation_value_reg = character.value;
   lex_class_reg = RELATIONSHIP_OPERATIONS;
   next();
   q = H1;
}

void MINI_BASIC::H1b()
{
   Create_Token();
   H1a();
   q = H1;
}

void MINI_BASIC::H1c()
{
   DA1D();
   H1b();
   q = H1;
}

void MINI_BASIC::H1d()
{
   DA2D();
   H1b();
   q = H1;
}

void MINI_BASIC::H1e()
{
   DA3D();
   H1b();
   q = H1;
}

void MINI_BASIC::H1f()
{
   DA1E();
   H1b();
   q = H1;
}

void MINI_BASIC::M1()
{
   if (detection_reg == 0)
   {
      if (table_first_vector[character.value] != 0)
         detection_reg = table_first_vector[character.value];
      else
         Error_Handler();
   }

   next();
   if (character.value == table_detection[detection_reg].letter)
   {
      (this->*(table_detection[detection_reg].f))();
      detection_reg++;
   }
   else if (table_detection[detection_reg].alt != -1)
   {
      detection_reg = table_detection[detection_reg].alt - 1;
   }
   else    
      Error_Handler();
}

void MINI_BASIC::M2()
{
   if (character.value != 5)
   {
      DA1D();
      B1b();
   }
   else
      D3a();
}

void MINI_BASIC::M3()
{
   if (character.value != 5)
   {
      DA2D();
      B1b();
   }
   else
      q = D3;
}

void MINI_BASIC::EXIT1()
{
   lex_class_reg = END;
   Create_Token();
}

void MINI_BASIC::EXIT2()
{
   Create_Token();
   EXIT1();
}

void MINI_BASIC::EXIT3()
{
   DA1D();
   EXIT2();
}

void MINI_BASIC::EXIT4()
{
   DA2D();
   EXIT2();
}

void MINI_BASIC::EXIT5()
{
   DA3D();
   EXIT2();
}

void MINI_BASIC::EXIT6()
{
   DA1E();
   EXIT2();
}

void MINI_BASIC::Create_Token()
{
   Token T;
   T.type = lex_class_reg;
   counter_tokens++;

   switch (lex_class_reg)
   {
   case LABLE:
      T.value = table_number_string.insert_index(number_string_reg, counter_tokens);
      break;

   case OPERAND:
      T.value = ptr_to_free - 1;
      break;

   case GOTO:
   case GOSUB:
      T.value = table_number_string.find(number_string_reg);
      break;

   case LET:
   case FOR:
   case NEXT:
      T.value = ptr_to_free;
      break;

   case ARITHMETIC_OPERATIONS:
   case RELATIONSHIP_OPERATIONS:
   case L_BRACKET:
   case R_BRACKET:
   case IF:
   case RETURN:
   case END:
   case TO:
   case STEP:
   case REM:
   case ERROR:
   case END_OF_FILE:
   case COMMENT:
      T.value = character.value;
      break;
   }

   table_tokens.push_back(T);
}

void MINI_BASIC::Error_Handler()
{
   cout << "JOPA" << endl;
   q = Error;
}

void MINI_BASIC::Error()
{
   ;
}




