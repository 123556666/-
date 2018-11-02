#pragma once

#include "Info.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdlib.h>

#define Node_ptr unique_ptr<Node>

ofstream fout("1234.txt");

using namespace std;

class Node {
public:
	Node_Info info;
	Node_ptr l = nullptr;
	Node_ptr r = nullptr;
	Node() {}
	//Copy
	Node(const Node & t) : info(t.info), l(copy_unique(t.l)), r(copy_unique(t.r)) {}
	//Move
	Node(Node &&t) noexcept : info(t.info), l(move(t.l)), r(move(t.r)) { t.info = Node_Info(); }
	//Param
	Node(int d,int varnum,double min ,double max) {
		SetUnary();
		if (d != 0) {
			if (GetUnary()) {
				SetTypeF(randomInt(0, 4));
				l.reset(new Node(d - 1, varnum, min, max));
			}
			else {
				SetTypeF(randomInt(0, 3));
				l.reset(new Node(d - 1, varnum, min, max));
				r.reset(new Node(d - 1, varnum, min, max));
			}
		}else 
			if (GetVar()) 
				SetVAarNumber(randomInt(0, varnum - 1));
			else  
				SetValue(randomDouble(min, max));
	}
	~Node() {}
	void		SetVAarNumber(int i) { info.VarNumber = i; }
	void		SetInfo(Node_Info i) { info = i; }
	int	SetID(int id) {
		info.ID = id;
		if (l)
			if (r) return r->SetID(l->SetID(id + 1));
			else return l->SetID(id + 1);
		else return id + 1;
	}
	void		SetUnary() {  info.Unary = Ratio(10, 90); info.Var = Ratio(50, 50);}
	void		SetValue(double i) { info.value = i; }
	void		SetTypeF(int i) { info.TypeF = i; }
	
	Node_ptr	SetNode(int target, Node_ptr node) {
		if (l)
			if (l->GetID() == target) { l = move(node); return nullptr; }
			else {
				node = move(l->SetNode(target, move(node)));
				if (node && r)
					if (r->GetID() == target) { r = move(node); return nullptr; }
					else return move(r->SetNode(target, move(node)));
				else return nullptr;
			}
		else return move(node);
	}
	double evaluate(vector<vector<double>>x, int i) {
		if (l) {
			if (GetUnary()) {
				if (GetTypeF() == 0)
					return cos(l->evaluate(x, i));
				if (GetTypeF() == 1)
					return sin(l->evaluate(x, i));
				if (GetTypeF() == 2)
					return sqrt(abs(l->evaluate(x, i)));
				if (GetTypeF() == 3)
					return log(l->evaluate(x, i));
				if (GetTypeF() == 4)
					return exp(l->evaluate(x, i));
			}
			else {
				if (GetTypeF() == 0)
					return l->evaluate(x, i) + r->evaluate(x, i);
				if (GetTypeF() == 1)
					return l->evaluate(x, i) - r->evaluate(x, i);
				if (GetTypeF() == 2)
					return l->evaluate(x, i) * r->evaluate(x, i);
				if (GetTypeF() == 3)
					return l->evaluate(x, i) / (r->evaluate(x, i) + 0.00000001);
			}
		}
		else {
			if (GetVar())
				return x[i][GetVarNumber()];
			else
				return GetValue();
		}
	}
			
		
	int SetDepth(int d) {
		int a = 0, b = 0;
		info.Depth = d;
		if (l) a = l->SetDepth(d + 1);
		if (r) b = r->SetDepth(d + 1);
		if (a > d && a > b) return a;
		if (b > d) return b;
		return d;
	}
	Node_Info	GetInfo() { return info; }
	int			GetVarNumber() { return info.VarNumber; }
	int			GetID() { return info.ID; }
	bool		GetUnary() { return info.Unary; }
	bool		GetVar() { return info.Var; }
	int			GetTypeF() { return info.TypeF; }
	double		GetValue() { return info.value; }
	Node_ptr	GetNode(int target) {
		Node_ptr temp = nullptr;
		if (l) {
			if (l->GetID() == target) return copy_unique(l);
			else {
				temp = l->GetNode(target);
				if (temp) return temp;
				else
					if (r) {
						if (r->GetID() == target) return copy_unique(r);
						else return r->GetNode(target);
					}
					else return temp;
			}
		}
		else return nullptr;
	}



	//Node must exist!
	void Print() {
		if(l){
			if (GetUnary()) {
				if (GetTypeF() == 0) {
					fout << "cos("; l->Print(); fout << ")";
				}
				if (GetTypeF() == 1) {
					fout << "sin("; l->Print(); fout << ")";
				}
				if (GetTypeF() == 2){ 
					fout << "sqrt("; l->Print(); fout << ")"; 
				}
				if (GetTypeF() == 3){ 
					fout << "log("; l->Print(); fout << ")"; 
				}
				if (GetTypeF() == 4){
					fout << "cos("; l->Print(); fout << ")"; 
				}
			}
			else {
				if (GetTypeF() == 0) {
					fout << "("; l->Print(); fout << "+"; r->Print(); fout << ")";
				}
				if (GetTypeF() == 1) {
					fout << "("; l->Print(); fout << "-"; r->Print(); fout << ")";
				}					
				if (GetTypeF() == 2) {
					fout << "("; l->Print(); fout << "*"; r->Print(); fout << ")";
				}
				if (GetTypeF() == 3) {
					fout << "("; l->Print(); fout << "/"; r->Print(); fout << ")";
				}				
			}
		}
		else{
			if (GetVar())
				fout << "x[" << GetVarNumber() << "]";
			else {
				if (GetValue() > 0)
					fout << GetValue();
				else
					fout << "(" << GetValue() << ")";
			}
		}	
	}
	
	void Swap(Node &t) noexcept { swap(info, t.info); l.swap(t.l); r.swap(t.r); }
	//Copy-assignment
	Node &operator=(const Node &t) { if (this != &t) Node(t).Swap(*this); return *this; }
	//Move-assignment
	Node &operator=(Node &&t) { Swap(t); return *this; }
	//Deep-copy helper
	static Node_ptr copy_unique(const Node_ptr& t) { return t ? make_unique<Node>(*t) : nullptr; }
};