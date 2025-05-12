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

   void Create_Big_Table();

   MINI_BASIC_Syntax_analyzer();
   
   void Rule1();
   void Rule2();
   void Rule3();
   void Rule4();
   void Rule5();
   void Rule6();
   void Rule7();
   void Rule8();
   void Rule9();
   void Rule10();
   void Rule11();
   void Rule12();
   void Rule13();
   void Rule14();
   void Rule15();
   void Rule16();
   void Rule17();
   void Rule18();
   void Rule19();
   void Rule20();
   void Rule21();
   void Rule22();
   void Rule23();
   void Rule24();
   void Rule25();
   void Rule26();
   void Rule27();

   void Process1();
   void Process2();
   void Process3();
   void Process4();
   void Process5();
   void Process6();
   void Process7();
   void Process8();
   void Process9();
   void Process10();
   void Process11();
   void Process12();
   void Process13();
   void Process14();
   void Process15();
   void Process16();
   void Process17();
   void Process18();
   void Process19();
   void Process20();
   void Process21();
   void Process22();
   void Process23();
   void Process24();
   void Process25();
   void Process26();
   void Process27();
   void Process28();

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

