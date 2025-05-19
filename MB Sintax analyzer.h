#pragma once
#include "MB Lexical analyzer.h"
#include "Atoms.h"
class MINI_BASIC_Syntax_analyzer :
    protected MINI_BASIC_Lexical_analyzer
{
protected:

   vector<Atom> table_atoms;

   typedef void(MINI_BASIC_Syntax_analyzer::* func) ();
   func Control_Table[33][23];

   stack<int> stk;

   int in;

   void Create_Big_Table();

   MINI_BASIC_Syntax_analyzer();

   void Create_Atom();
   
   void F1();
   void F2();
   void F3();
   void F4();
   void F5();
   void F6();
   void F7();
   void F8();
   void F9();
   void F10();
   void F11();
   void F12();
   void F13();
   void F14();
   void F15();
   void F16();
   void F17();
   void F18();
   void F19();
   void F20();
   void F21();
   void F22();
   void F23();
   void F24();
   void F25();
   void F26();
   void F27();
   void F28();

   void a();
   void b();
   void c();
   void d();
   void e();
   void f();
   void g();
   void h();
   void i();
   void j();
   void k();
   void l();
   void m();
   void n();
   void o();
   void p();
   void q();
   void r();

   void A();

   void B();

   void G1();
   void G2();

   void D();

   void K1();
   void K2();
   void K3();
   void K4();
   void K5();
   void K6();
   void K7();

   void E1();
   void E2();
   void E3();

   void L();

   void M1();
   void M2();
   void M3();
   void M4();

   void N1();
   void N2();
   void N3();

   void K();

   void P1();
   void P2();
   void P3();
   void P4();

   void P();

   void C();

   void T1();
   void T2();
   void T3();

   void O();



};

