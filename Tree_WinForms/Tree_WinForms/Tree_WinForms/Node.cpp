#include "Node.h"

namespace Node_nspace {
#pragma region Ctor/Dtor
	Node::Node() :
		l(nullptr), 
		r(nullptr) {}
	Node::Node(const Node & t) :
		info(t.info),
		l(copy_unique(t.l)),
		r(copy_unique(t.r)) {}
	Node::Node(Node &&t) :
		info(t.info),
		l(move(t.l)),
		r(move(t.r)) {
		t.info = N_Info();
	}
	Node::Node(int d, bool o, bool u, double min, int range) {
		SetType(o, u);

		if (GetOperator()) {
			if (d < 1) { o = 0; u = Ratio(1, 1); }
			else { o = Ratio(9, 1); u = Ratio(1, 9); }

			SetRandInfo(GiveRandOper(GetUnary()));
			l.reset(new Node(d - 1, o, u, min, range));
			if (!GetUnary()) r.reset(new Node(d - 1, o, u, min, range));
		}
		else {
			u = Ratio(1, 1);
			if (GetUnary()) SetRandInfo(RANGE_RAND(min, range));
			else SetRandInfo("x");
		}
	}
#pragma endregion
#pragma region Set/Get
	int	Node::SetID(int id) {
		info.ID = id;
		return l ? (r ? r->SetID(l->SetID(id + 1)) : l->SetID(id + 1)) : id + 1;
	}

	Node_ptr Node::SetNode(int target, Node_ptr node) {
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
	Node_ptr Node::GetNode(int target) {
		Node_ptr temp = nullptr;
		if (l)
			if (l->GetID() == target) return copy_unique(l);
			else {
				temp = l->GetNode(target);
				if (temp) return temp;
				else
					if (r)
						if (r->GetID() == target) return copy_unique(r);
						else return r->GetNode(target);
					else return temp;
			}
		else return nullptr;
	}
#pragma endregion
#pragma region Methods
	string Node::Print() {
		if (l)
			if (r) return " (" + l->Print() + GetRandInfo() + r->Print() + ") ";
			else return GetRandInfo() + " (" + l->Print() + ") ";
		else return GetRandInfo();
	}
	double Node::Evaluate(double x) {
		if (l) {
			double value_l = l->Evaluate(x);
			if (r) {
				double value_r = r->Evaluate(x);
				if (value_r) {
					if (GetRandInfo() == "+") return value_l + value_r;
					else 
						if (GetRandInfo() == "-") return value_l - value_r;
						else 
							if (GetRandInfo() == "*") return value_l * value_r;
							else 
								if (GetRandInfo() == "/") return value_l / value_r;
								else return 0;
				}
				else {
					if (GetRandInfo() == "*") return 0;
					else return value_l;
				}
			}
			else {
				//"sin", "cos", "sqr", "sqrt", "ln", "exp"
				if (GetRandInfo() == "sin") return sin(value_l);
				else 
					if (GetRandInfo() == "cos") return cos(value_l);
					else return 0;
			}
		}
		else {
			if(GetUnary()) return stod(GetRandInfo());
			else return x;
		}
	}
#pragma endregion
#pragma region Copy
	void Node::Swap(Node &t) {
		swap(info, t.info);
		l.swap(t.l);
		r.swap(t.r);
	}
	Node& Node::operator=(const Node &t) {
		if (this != &t) Node(t).Swap(*this);
		return *this;
	}
	Node& Node::operator=(Node &&t) {
		Swap(t);
		return *this;
	}
#pragma endregion
}