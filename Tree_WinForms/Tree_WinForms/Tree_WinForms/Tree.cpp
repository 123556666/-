#include "Tree.h"

namespace Tree_nspace {
#pragma region Ctor/Dtor
	Tree::Tree() :
		Root(nullptr) {}
	Tree::Tree(const Tree &t) :
		info(t.info),
		Root(copy_unique(t.Root)) {}
	Tree::Tree(Tree &&t) :
		info(t.info),
		Root(move(t.Root)) {
		t.info = T_Info();
	}
	Tree::Tree(int depth, double min, int range) {
		SetDepth(depth);
		if (GetDepth() < 1) Root.reset(new Node(0, 0, Ratio(1, 1), min, range));
		else Root.reset(new Node(GetDepth() - 1, Ratio(9, 1), Ratio(1, 9), min, range));
		SetLastNode(Root->SetID(0) - 1);
	}
	Tree::Tree(Node_ptr root) {
		if (root) { Root = move(root); SetLastNode(Root->SetID(0)); }
		SetDepth(10);
	}
#pragma endregion
#pragma region Set/Get
	void Tree::SetNode(int target, Node_ptr node) { 
		if (target) Root->SetNode(target, move(node)); 
		else Root = move(node); 
	}
#pragma endregion
#pragma region Methods
	string Tree::Print() { if (Root) return Root->Print(); else return ""; }
	void Tree::Fitness(int n, vector<double> arr_x, vector<double> arr_y) {
		double mistake = 0;
			
		if (Root) for (int i = 0; i < n; i++) mistake += pow((arr_y[i] - GetY(arr_x[i])), 2);

		SetFitness(1. / (1 + mistake));
	}
#pragma endregion
#pragma region Copy
	void Tree::Swap(Tree &t) { 
		swap(info, t.info); 
		Root.swap(t.Root); 
	}
	Tree& Tree::operator=(const Tree &t) { 
		if (this != &t) Tree(t).Swap(*this); 
		return *this; 
	}
	Tree& Tree::operator=(Tree &&t) {
		Swap(t); 
		return *this; 
	}
#pragma endregion
}