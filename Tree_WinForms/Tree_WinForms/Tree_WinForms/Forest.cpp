#include "Forest.h"

namespace Forest_nspace {
#pragma region Ctor/Dtor
	Forest::Forest() : 
		Population(0), 
		best(0) {}
	Forest::Forest(int size, int depth, double min, int range) {
		info.Size = size;
		Population.resize(info.Size);
		for (int i = 0; i < info.Size; i++) Population[i] = Tree(depth, min, range);
	}
#pragma endregion
#pragma region Methods
	void Forest::CrossOver(vector<int> order) { /*Standart*/
		vector<Tree> temp(0);

		for (int i = 0; i < GetSize(); i++) {
			int &first = order[i * 2];
			int &second = order[i * 2 + 1];
			int first_node = rand() % (Population[first].GetLastNode() + 1);
			int second_node = rand() % (Population[second].GetLastNode() + 1);

			Tree Oak = Population[first];
			Tree Pine = Population[second];

			Node_ptr tmp1 = move(Oak.GetNode(first_node));
			Node_ptr tmp2 = move(Pine.GetNode(second_node));

			Oak.SetNode(first_node, move(tmp2));
			Pine.SetNode(second_node, move(tmp1));

			if (rand() % 2 == 0) temp.push_back(Oak);
			else temp.push_back(Pine);
		}

		Population = temp;
	}
	void Forest::TreeMutation(double probability, double min, double max) {
		int randomNode = 0, SubTreeDepth = 0;
		for (int i = 0; i < GetSize(); i++) {
			double p = RANGE_RAND(0, 1);
			if (p < probability) {
				randomNode = rand() % (Population[i].GetLastNode() + 1);;//рандом узла			
				Node_ptr tmp1 = move(Population[i].GetNode(randomNode));//выдераем поддерево
				SubTreeDepth = tmp1->SetID(0);//считаем его длину
				Node_ptr SubTree;
				SubTree.reset(new Node(0, 0, Ratio(1, 1), min, max));//новое поддерево такой же глубины
				Population[i].SetNode(randomNode, move(SubTree));//вставляем новое поддерево
			}
		}
	}
	void Forest::Print(int n, vector<double> arr_x, vector<double> arr_y) {
		for (int i = 0; i < info.Size; i++) { 
			//Population[i].Print(); 
			Population[i].Fitness(100, arr_x, arr_y);
		}
	}
#pragma endregion
}