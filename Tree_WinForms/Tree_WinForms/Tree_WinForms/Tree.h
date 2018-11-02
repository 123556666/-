#pragma once

#include "Info.h"
#include "Node.h"
#include <iostream>
#include <memory>

namespace Tree_nspace {
	using namespace Node_nspace;

	class Tree {
	private:
		T_Info info;
		Node_ptr Root;
	public:
#pragma region Ctor / Dtor
		Tree();
		Tree(const Tree &t);						/*Copy*/
		Tree(Tree &&t);								/*Move*/
		Tree(int depth, double min, int range);	/*Param*/
		Tree(Node_ptr root);
		~Tree() {}
#pragma endregion
#pragma region Set/Get
		inline	void		SetDepth(int d)						{ info.Depth = d; }
		inline	int			GetDepth() const					{ return info.Depth; }
		
		inline	void		SetLastNode(int ln)					{ info.LastNode = ln; }
		inline	int			GetLastNode() const					{ return info.LastNode; }

		inline	double		GetY(double x)						{ return Root->Evaluate(x); }

		inline	void		SetFitness(double f)				{ info.Fitness = f; }
		inline	double		GetFitness() const					{ return info.Fitness; }

				void		SetNode(int target, Node_ptr node);
		inline	Node_ptr	GetNode(int target)					{ return target ? Root->GetNode(target) : copy_unique(Root); }
#pragma endregion
#pragma region Methods
		string Print();
		void Fitness(int n, vector<double> arr_x, vector<double> arr_y);
#pragma endregion
#pragma region Copy
		void Swap(Tree &t);
		Tree &operator=(const Tree &t);	/*Copy-assignment*/
		Tree &operator=(Tree &&t);		/*Move-assignment*/
#pragma endregion
	};
}