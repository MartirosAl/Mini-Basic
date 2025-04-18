﻿#pragma once
#include "MINI_BASIC.h"


SymbolicToken MINI_BASIC::Transliterator(int character)
{
    SymbolicToken result;
    result.value = 0;
    if (character >= 'A' && character <= 'Z')
    {
        result.token_class = SymbolicTokenType::LETTER;
        result.value = (int)character;
    }
    else if (character >= '0' && character <= '9')
    {
        result.token_class = SymbolicTokenType::DIGIT;
        result.value = (int)character;
    }
    else if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^')
    {
        result.token_class = SymbolicTokenType::ARITHMETIC_OPERATION_S;
        result.value = (int)character;
    }
    else if (character == '<' || character == '>' || character == '=')
    {
        result.token_class = SymbolicTokenType::RELATION_S;
        result.value = (int)character;
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
    character = Transliterator(stream.get());

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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
      character = Transliterator(stream.get());
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
   number_reg = 0;
   //Вычислить константу

}

void MINI_BASIC::DA2D()
{
    order_reg = -counter_reg;
    //Вычислить константу
}

void MINI_BASIC::DA3D()
{
    if (order_reg == -1)
    {
        order_reg = -order_reg;
    }

    counter_reg -= order_reg;

    //Вычислить константу
    Внедрить Hash таблицу
}

void MINI_BASIC::DA1E()
{
   Внедрить Hash таблицу
}

void MINI_BASIC::DA1Ecycle()
{
    ....
}

void MINI_BASIC::A1a()
{
    Create_Token();
    q = A1;
}

void MINI_BASIC::A1b()
{
    DA1D();
    q = A1;
}

void MINI_BASIC::A1c()
{
    DA2D();
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
    q = A2;
}

void MINI_BASIC::A2b()
{
    Create_Token();
    q = A2;
}

void MINI_BASIC::A2c()
{
    DA1D();
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
    q = A2;
}

void MINI_BASIC::A2h()
{
    lex_class_reg = L_BRACKET;
    Create_Token();
    q = A2;
}

void MINI_BASIC::A2j()
{
    DA1E();
    q = A2;
}

void MINI_BASIC::A2k()
{
    Create_Token();
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
   if (char_value_reg == 1)
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
   char_value_reg 
   q = A2;
}

void MINI_BASIC::A2q()
{
   lex_class_reg = END;
   q = A2;
}

void MINI_BASIC::A2r()
{
   lex_class_reg = IF;
   q = A2;
}

void MINI_BASIC::A2s()
{
   lex_class_reg = RETURN;
   q = A2;
}

void MINI_BASIC::A2t()
{
   lex_class_reg = STEP;
   q = A2;
}

void MINI_BASIC::A2u()
{
   lex_class_reg = TO;
   q = A2;
}

void MINI_BASIC::A3a()
{
   😢
   q = A2;
}

void MINI_BASIC::A3b()
{
   lex_class_reg = R_BRACKET;
   q = A3;
}

void MINI_BASIC::A3c()
{
   Create_Token();
   q = A3;
}

void MINI_BASIC::A3d()
{
   DA1D();
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
   😢
   q = B1;
}

void MINI_BASIC::B1b()
{
   Create_Token();
   q = B1;
}

void MINI_BASIC::B1c()
{
   DA3D();
   q = B1;
}

void MINI_BASIC::B1d()
{
   detection_reg++;
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
   q = C1;
}

void MINI_BASIC::C2a()
{
   lex_class_reg = OPERAND;
   q = C2;
}

void MINI_BASIC::C2b()
{
   Create_Token();
   q = C2;
}

void MINI_BASIC::C2d()
{
   😢
   q = C2;
}

void MINI_BASIC::D1a()
{
   lex_class_reg = OPERAND;
   😢
   q = D1;
}

void MINI_BASIC::D1b()
{
   number_reg *= 10;
   😢
   q = D1;
}

void MINI_BASIC::D1c()
{
   Create_Token();
   q = D1;
}

void MINI_BASIC::D2a()
{
   counter_reg = 1;
   number_reg *= 10;
   😢
   q = D2;
}

//🔥🔥🔥🔥🔥🔥🧯
void MINI_BASIC::D2b()
{
   counter_reg = 1;
   😢
   q = D2;
}

void MINI_BASIC::D2c()
{
   counter_reg = 0;
   q = D2;
}

void MINI_BASIC::D3a()
{
   counter_reg = 0;
   q = D3;
}

void MINI_BASIC::D4a()
{
   😢
   q = D4;
}

void MINI_BASIC::D5a()
{
   char_value_reg = +1;
   q = D5;
}

void MINI_BASIC::D5b()
{
   😢
   q = D5;
}

void MINI_BASIC::D5c()
{
   order_reg *= 10;
   😢
   q = D5;
}

void MINI_BASIC::D6a()
{
   Create_Token();
   q = D6;
}

void MINI_BASIC::E1a()
{

}

void MINI_BASIC::E1b()
{
}

void MINI_BASIC::E2a()
{
   lex_class_reg = LABLE;
   number_string_reg = character.value - '0';
   q = E2;
}

void MINI_BASIC::E2b()
{
}

void MINI_BASIC::E2c()
{
   number_string_reg *= 10;
   number_string_reg += character.value - '0';
   character = Transliterator(stream.get());
}

void MINI_BASIC::F1a()
{
}

void MINI_BASIC::F1b()
{
}

void MINI_BASIC::F2a()
{
}

void MINI_BASIC::F3a()
{
}

void MINI_BASIC::G1a()
{
}

void MINI_BASIC::H1a()
{
}

void MINI_BASIC::H1b()
{
}

void MINI_BASIC::H1c()
{
}

void MINI_BASIC::H1d()
{
}

void MINI_BASIC::H1e()
{
}

void MINI_BASIC::H1f()
{
}

void MINI_BASIC::M1()
{
   for (int i = 0; i < table_first_vector.size(); i++)
      if (table_first_vector[i][0] == character.value)
      {
         character = Transliterator(stream.get());
         while (true)
         {
            if (character.)
         }
      }
   Error_Handler();
}

void MINI_BASIC::M2()
{
}

void MINI_BASIC::M3()
{
}

void MINI_BASIC::EXIT1()
{
}

void MINI_BASIC::EXIT2()
{
}

void MINI_BASIC::EXIT3()
{
}

void MINI_BASIC::EXIT4()
{
}

void MINI_BASIC::EXIT5()
{
}

void MINI_BASIC::EXIT6()
{
}

void MINI_BASIC::Error()
{
   ;
}





