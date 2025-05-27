#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Lexical_Grammar_Analyzer
{
public:
	Lexical_Grammar_Analyzer(string filename);

private:

	vector<string> terminals;
	vector<string> nonterminals;

	

};

