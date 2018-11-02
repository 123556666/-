#pragma once

#include "Info.h"
#include "Tree.h"
#include <iostream>

namespace Forest_nspace {
	using namespace Tree_nspace;

	class Forest {
	private:
		F_Info info;
	public:
		vector<Tree> Population;
		int best;
#pragma region Ctor/Dtor
		Forest();
		Forest(int size, int depth, double min, int range);
#pragma endregion
#pragma region Set/Get
		inline void SetSize(int s)	{ info.Size = s; }
		inline int	GetSize() const	{ return info.Size; }
#pragma endregion
#pragma region Methods
		void CrossOver(vector<int> order);
		void TreeMutation(double probability, double min, double max);
		//void SP_Crossover();
		void Print(int n, vector<double> arr_x, vector<double> arr_y);
#pragma endregion
	};
}