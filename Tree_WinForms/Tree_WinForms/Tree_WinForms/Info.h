#pragma once

#include <string>
#include <vector>


namespace Info_nspace {
	using namespace std;

	namespace {
		string UnaryOperations[] = { "sin", "cos", "sqr", "sqrt", "ln", "exp" };
		string BinaryOperations[] = { "+", "-", "*", "/" };
		string GiveRandOper(bool unary) { return unary ? UnaryOperations[rand() % 6] : BinaryOperations[rand() % 4]; }
		int Ratio(int a, int b) { return rand() % (a + b) < b ? 0 : 1; } /*a to b ratio*/
	}

	struct N_Info {
		int ID = NULL;
		bool Unary = false;
		bool Operator = false;
		string RandInfo = "";
	};
	struct T_Info {
		int Depth = NULL;
		int LastNode = NULL;
		double Fitness = NULL;
	};
	struct F_Info {
		int Size = NULL;
	};
}