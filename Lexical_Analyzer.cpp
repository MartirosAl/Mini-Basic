#pragma once
#include "Lexical_Analyzer.h"


SymbolicToken Lexical_Analyzer::Transliterator(int character)
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

Lexical_Analyzer::Lexical_Analyzer(string name_file)
{
    ifstream in(name_file);
    if (!in)
    {
        cout << "Couldn't open the file " << name_file << endl;
        return;
    }

    SymbolicToken character;
    string word;

    //Tests flags
    bool flag_work_state = false;

    //Initial state
    q = &Lexical_Analyzer::A1;

    while (true)
    {
        character = Transliterator(in.get());


        (this->*q)(character);
        if (q == &Lexical_Analyzer::Error)
            return;
        if (flag_work_state)
            cout << character.value << endl;

        if (q == &Lexical_Analyzer::A3)
        {
            cout << "Goodbye World!" << endl;
            break;
        }
    }

}

//начало строки
void Lexical_Analyzer::A1(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case DIGIT:
      E2a();
      break;
   case SPACE:
      q = A1;
      break;
   case LF:
      q = A1;
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error(ch);
      break;
   }
}

//искать перем., конст., опер., СR, (, ), отнош.
void Lexical_Analyzer::A2(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = A2;
      break;
   case LF:
      q = A1;
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error(ch);
      break;
   }
}

//искать зарезерв. слово, опер., СR, (, ), отнош
void Lexical_Analyzer::A3(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = A3;
      break;
   case LF:
      q = A1;
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error(ch);
      break;
   }
}

//Обнаружить зарезерв.слово
void Lexical_Analyzer::B1(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case LETTER:
      M1();
      break;
   case SPACE:
      q = B1;
      break;
   default:
      Error(ch);
      break;
   }
}

//искать переменную
void Lexical_Analyzer::C1(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case LETTER:
      C2d();
      break;
   case SPACE:
      q = C1;
      break;
   case END_OF_FILE_S:
      q = EXIT3;
      break;
   default:
      Error(ch);
      break;
   }
}

//завершить обработку переменной
void Lexical_Analyzer::C2(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = C2;
      break;
   case LF:
      A1a();
      break;
   case END_OF_FILE_S:
      q = EXIT4;
      break;
   default:
      Error(ch);
      break;
   }
}

//завершить обработку целой части
void Lexical_Analyzer::D1(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = D2;
      break;
   case LF:
      A1b();
      break;
   case END_OF_FILE_S:
      q = EXIT3;
      break;
   default:
      Error(ch);
      break;
   }
}

//завершить обработку дробной части
void Lexical_Analyzer::D2(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = D2;
      break;
   case LF:
      A1c();
      break;
   case END_OF_FILE_S:
      q = EXIT4;
      break;
   default:
      Error(ch);
      break;
   }
}

//после буквы Е
void Lexical_Analyzer::D3(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case DIGIT:
      D5a();
      break;
   case ARITHMETIC_OPERATION_S:
      D4a();
      break;
   case SPACE:
      q = D3;
      break;
   default:
      Error(ch);
      break;
   }
}

//после буквы Е и знака
void Lexical_Analyzer::D4(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case DIGIT:
      D2b();
      break;
   case SPACE:
      q = D4;
      break;
   default:
      Error(ch);
      break;
   }
}

//завершить обработку порядка
void Lexical_Analyzer::D5(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = D5;
      break;
   case LF:
      A1d();
      break;
   case END_OF_FILE_S:
      q = EXIT5;
      break;
   default:
      Error(ch);
      break;
   }
}

//после первой десятичной точки
void Lexical_Analyzer::D6(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case DIGIT:
      D2b();
      break;
   case SPACE:
      q = D6;
      break;
   default:
      Error(ch);
      break;
   }
}

//искать номер строки
void Lexical_Analyzer::E1(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case DIGIT:
      E2b();
      break;
   case SPACE:
      q = E1;
   default:
      Error(ch);
      break;
   }
}

//оставшаяся часть номера строки
void Lexical_Analyzer::E2(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = E2;
      break;
   case LF:
      A1e();
      break;
   default:
      Error(ch);
      break;
   }
}

//искать переменную и =
void Lexical_Analyzer::F1(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case LETTER:
      F2a();
      break;
   case SPACE:
      q = F1;
      break;
   default:
      Error(ch);
      break;
   }
}

//оставшаяся часть переменной
void Lexical_Analyzer::F2(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case DIGIT:
      F3a();
      break;
   case RELATION_S:
      A2o();
      break;
   case SPACE:
      q = F2;
      break;
   default:
      Error(ch);
      break;
   }
}

//искать =
void Lexical_Analyzer::F3(SymbolicToken ch)
{
   switch (ch.token_class)
   {
   case RELATION_S:
      A2o();
      break;
   case SPACE:
      q = F3;
      break;
   default:
      Error(ch);
      break;
   }
}

//найти СR (комментарий)
void Lexical_Analyzer::G1(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = G1;
      break;
   case LF:
      q = A1;
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error(ch);
      break;
   }
}

//завершить обработку отношения
void Lexical_Analyzer::H1(SymbolicToken ch)
{
   switch (ch.token_class)
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
      q = H1;
      break;
   case LF:
      A1a();
      break;
   case END_OF_FILE_S:
      q = EXIT1;
      break;
   default:
      Error(ch);
      break;
   }
}

void Lexical_Analyzer::DA1D()
{
   number_reg = 0;
   //Вычислить константу

}

void Lexical_Analyzer::DA2D()
{
    order_reg = -counter_reg;
    //Вычислить константу
}

void Lexical_Analyzer::DA3D()
{
    if (order_reg == -1)
    {
        order_reg = -order_reg;
    }

    counter_reg -= order_reg;

    //Вычислить константу
}

void Lexical_Analyzer::DA1E()
{
    ....
}

void Lexical_Analyzer::DA1Ecycle()
{
    ....
}

void Lexical_Analyzer::A1a()
{
    Create_Token();
    q = A1;
}

void Lexical_Analyzer::A1b()
{
    DA1D();
    q = A1;
}

void Lexical_Analyzer::A1c()
{
    DA2D();
    q = A1;
}

void Lexical_Analyzer::A1d()
{
    DA3D();
    A1a();
    q = A1;
}

void Lexical_Analyzer::A1e()
{
    DA1E();
    A1a();
    q = A1;
}

void Lexical_Analyzer::A2a()
{
    lex_class_reg = ARITHMETIC_OPERATIONS;
    q = A2;
}

void Lexical_Analyzer::A2b()
{
    Create_Token();
    q = A2;
}

void Lexical_Analyzer::A2c()
{
    DA1D();
    q = A2;
}

void Lexical_Analyzer::A2d()
{
    DA2D();
    A2g();
    q = A2;
}

void Lexical_Analyzer::A2e()
{
    DA3D();
    A2g();
    q = A2;
}

void Lexical_Analyzer::A2f()
{
    DA1E();
    A2g();
    q = A2;
}

void Lexical_Analyzer::A2g()
{
    Create_Token();
    q = A2;
}

void Lexical_Analyzer::A2h()
{
    lex_class_reg = L_BRACKET;
    Create_Token();
    q = A2;
}

void Lexical_Analyzer::A2j()
{
    DA1E();
    q = A2;
}

void Lexical_Analyzer::A2k()
{
    Create_Token();
    q = A2;
}

void Lexical_Analyzer::A2l()
{
    DA1D();
    A2k();
    q = A2;
}

void Lexical_Analyzer::A2m()
{
    DA2D();
    A2k();
    q = A2;
}

void Lexical_Analyzer::A2n()
{
    DA3D();
    A2k();
    q = A2;
}

void Lexical_Analyzer::A2o()
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

void Lexical_Analyzer::A2p()
{
   😢
   q = A2;
}

void Lexical_Analyzer::A2q()
{
   lex_class_reg = END;
   q = A2;
}

void Lexical_Analyzer::A2r()
{
   lex_class_reg = IF;
   q = A2;
}

void Lexical_Analyzer::A2s()
{
   lex_class_reg = RETURN;
   q = A2;
}

void Lexical_Analyzer::A2t()
{
   lex_class_reg = STEP;
   q = A2;
}

void Lexical_Analyzer::A2u()
{
   lex_class_reg = TO;
   q = A2;
}

void Lexical_Analyzer::A3a()
{
   😢
   q = A2;
}

void Lexical_Analyzer::A3b()
{
   lex_class_reg = R_BRACKET;
   q = A3;
}

void Lexical_Analyzer::A3c()
{
   Create_Token();
   q = A3;
}

void Lexical_Analyzer::A3d()
{
   DA1D();
   q = A3;
}

void Lexical_Analyzer::A3e()
{
   DA2D();
   A3c();
   q = A3;
}

void Lexical_Analyzer::A3f()
{
   DA3D();
   A3c();
   q = A3;
}

void Lexical_Analyzer::A3g()
{
   DA1E();
   A3c();
   q = A3;
}

void Lexical_Analyzer::B1a()
{
   😢
   q = B1;
}

void Lexical_Analyzer::B1b()
{
   Create_Token();
   q = B1;
}

void Lexical_Analyzer::B1c()
{
   DA3D();
   q = B1;
}

void Lexical_Analyzer::B1d()
{
   detection_reg++;
   q = B1;
}

void Lexical_Analyzer::B1e()
{
   DA1E();
   B1b();
   q = B1;
}

void Lexical_Analyzer::C1a()
{
   lex_class_reg = NEXT;
   q = C1;
}

void Lexical_Analyzer::C2a()
{
   lex_class_reg = OPERAND;
   q = C2;
}

void Lexical_Analyzer::C2b()
{
   Create_Token();
   q = C2;
}

void Lexical_Analyzer::C2d()
{
   😢
   q = C2;
}

void Lexical_Analyzer::D1a()
{
   lex_class_reg = OPERAND;
   😢
   q = D1;
}

void Lexical_Analyzer::D1b()
{
   number_reg *= 10;
   😢
   q = D1;
}

void Lexical_Analyzer::D1c()
{
   Create_Token();
   q = D1;
}

void Lexical_Analyzer::D2a()
{
   counter_reg = 1;
   number_reg *= 10;
   😢
   q = D2;
}

void Lexical_Analyzer::D2b()
{
}

void Lexical_Analyzer::D2c()
{
}

void Lexical_Analyzer::D3a()
{
}

void Lexical_Analyzer::D4a()
{
}

void Lexical_Analyzer::D5a()
{
}

void Lexical_Analyzer::D5b()
{
}

void Lexical_Analyzer::D5c()
{
}

void Lexical_Analyzer::D6a()
{
}

void Lexical_Analyzer::E1a()
{
}

void Lexical_Analyzer::E1b()
{
}

void Lexical_Analyzer::E2a()
{
}

void Lexical_Analyzer::E2b()
{
}

void Lexical_Analyzer::E2c()
{
}

void Lexical_Analyzer::F1a()
{
}

void Lexical_Analyzer::F1b()
{
}

void Lexical_Analyzer::F2a()
{
}

void Lexical_Analyzer::F3a()
{
}

void Lexical_Analyzer::G1a()
{
}

void Lexical_Analyzer::H1a()
{
}

void Lexical_Analyzer::H1b()
{
}

void Lexical_Analyzer::H1c()
{
}

void Lexical_Analyzer::H1d()
{
}

void Lexical_Analyzer::H1e()
{
}

void Lexical_Analyzer::H1f()
{
}

void Lexical_Analyzer::M1()
{
}

void Lexical_Analyzer::M2()
{
}

void Lexical_Analyzer::M3()
{
}

void Lexical_Analyzer::Exit1()
{
}

void Lexical_Analyzer::Exit2()
{
}

void Lexical_Analyzer::Exit3()
{
}

void Lexical_Analyzer::Exit4()
{
}

void Lexical_Analyzer::Exit5()
{
}

void Lexical_Analyzer::Exit6()
{
}

void Lexical_Analyzer::Error(SymbolicToken ch)
{
   ;
}





