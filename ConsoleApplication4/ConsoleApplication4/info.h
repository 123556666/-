#pragma once
#include <string>
#include<random>


using namespace std;

random_device rd;
mt19937 gen(rd());
int randomInt(int min, int max) {
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
double randomDouble(double min, double  max) {
	uniform_real_distribution<> dis(min, max);
	return dis(gen);
}

static string UnaryOperations[] = { "sin", "cos", "sqrt", "ln", "exp" };
static string BinaryOperations[] = { "+", "-", "*", "/" };

inline static string GiveRandOper(bool unary) { return unary ? UnaryOperations[rand() % 6] : BinaryOperations[rand() % 4]; }
//a to b ratio
inline static int Ratio(int a, int b) { return rand() % (a + b) < b ? 0 : 1; }

struct Node_Info {
	int ID = 0;
	bool Unary = NULL;
	bool Var = NULL;
	int TypeF = 0;
	int Depth = 0;
	int VarNumber = 0;
	double value = 0;
};
struct Tree_Info {
	int LastDepth = 0;
	int LastNode = 0;
	double IndFitness = 0;
};
struct Forest_Info {
	int Size = 0;
};