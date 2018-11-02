#pragma once

#include "Info.h"
#include "Node.h"
#include <iostream>
#include <memory>

#define Node_ptr unique_ptr<Node>

using namespace std;

class Tree {


public:
	Tree_Info info;
	Node_ptr Root = nullptr;
	Tree() {}
	//Copy
	Tree(const Tree &t) : info(t.info), Root(Node::copy_unique(t.Root)) {}
	//Move
	Tree(Tree &&t) noexcept : info(t.info), Root(move(t.Root)) { t.info = Tree_Info(); }
	//Param
	Tree(int depth, int varnum, double min, double max) {
		SetDepth(depth);
		if (GetDepth() < 1) Root.reset(new Node(0, varnum, min, max));
		else Root.reset(new Node(GetDepth() - 1, varnum, min, max));
		SetLastNode(Root->SetID(0) - 1);
	}
	Tree(Node_ptr root) {
		if (root) { Root = move(root); SetLastNode(Root->SetID(0)); }
		SetDepth(0);
	}
	~Tree() {}

	void SetDepth(int d) { info.LastDepth = d; }
	void SetLastNode(int ln) { info.LastNode = ln; }
	void SetNode(int target, Node_ptr node) { if (target) Root->SetNode(target, move(node)); else Root = move(node); }
	void SetIndFitness(double i) { info.IndFitness = i; }

	double GetIndFitness() { return info.IndFitness; }
	int			GetDepth() { return info.LastDepth; }
	int			GetLastNode() { return info.LastNode; }
	Node_ptr	GetNode(int target) { return target ? Root->GetNode(target) : Node::copy_unique(Root); }

	void fitness_individ(int n, vector<vector<double>>x , vector<double> y) {
		double mist = 0;
		int j = 0;
		for (int i = 0; i < n; i++) 
			mist += pow((y[i] - Root->evaluate(x, i)), 2);
		SetIndFitness(1. / (1 + mist));
	}
	void Print() {
		fout <<  "y = ";
		if (Root) Root->Print(); fout << "        ";// << //GetIndFitness();
		fout << endl;
	}
	void Swap(Tree &t) noexcept { swap(info, t.info); Root.swap(t.Root); }
	//Copy-assignment
	Tree &operator=(const Tree &t) { if (this != &t) Tree(t).Swap(*this); return *this; }
	//Move-assignment
	Tree &operator=(Tree &&t) { Swap(t); return *this; }
};