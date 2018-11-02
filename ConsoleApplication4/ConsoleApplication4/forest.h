#pragma once

#include "Info.h"
#include "Tree.h"
#include <iostream>
#include <vector>


class Forest {
public:
	Forest_Info info;
	vector<Tree> Population;
	Tree BestIndivid;
	int best = 0;
	Forest() {}
	Forest(int size, int depth, int varnum, double min, double max) {
		info.Size = size;
		Population.resize(info.Size);
		for (int i = 0; i < info.Size; i++) Population[i] = Tree(depth, varnum, min, max);
	}
	void SetSize(int i) { info.Size = i; }
	int GetSize() { return info.Size; }

	void ForestFitness(int n, vector<vector<double>>x, vector<double> y) {
		for (int i = 0; i < info.Size; i++)
			Population[i].fitness_individ(n,x,y);
		BestIndividCalc();
	}
	void BestIndividCalc() {
		double best_fit = 0;
		int best_num = 0;
		for (int j = 0; j < GetSize(); j++)
			if (Population[j].GetIndFitness() > best_fit) {
				best_fit = Population[j].GetIndFitness();
				best_num = j;
			}
		BestIndivid = Population[best_num];
	}
	vector<int> Selection_Tournament(int turs) {
		vector<int>m;
		vector<int> numbers;
		numbers.resize(GetSize()*2);
		int   k, best_individ = 0;
		bool a;
		double best_f;
		for (int i = 0; i < turs; i++) m.push_back(turs);
		for (int o = 0; o < GetSize() * 2; o++) {
			for (int i = 0; i < turs; i++) {
				do {
					a = 0;
					k = rand() % (info.Size);
					m[i] = k;
					for (int j = 0; j != i; j++)
						if (m[i] == m[j])
							a = 1;
				} while (a == 1);
			}
			best_f = 0;
			for (int i = 0; i < turs; i++) {
				if (Population[m[i]].GetIndFitness() > best_f) {
					best_f = Population[m[i]].GetIndFitness();
					best_individ = m[i];
				}
			}
			numbers[o] = best_individ;
		}return numbers;
	}
	Forest StandartCrossover(int target, vector<int>Numbers) {
		Forest temp;
		temp.SetSize(GetSize());
		temp.Population.resize(temp.GetSize());
		int randomTree1, randomTree2, randomNode1, randomNode2;
		for (int i = 0; i < GetSize(); i++) {
			do
			{
				randomTree1 = Numbers[i * 2]; //рандом деревьев
				randomTree2 = Numbers[i * 2 + 1];
				randomNode1 = randomInt(0, Population[randomTree1].GetLastNode());//рандом узлов
				randomNode2 = randomInt(0, Population[randomTree2].GetLastNode());

				Tree CopTreeRand1 = Population[randomTree1];
				Tree CopTreeRand2 = Population[randomTree2];
				if (randomNode1 || randomNode2 == 0)
					int p = 1;
				Node_ptr tmp1 = move(CopTreeRand1.GetNode(randomNode1));//обмен поддеревьев
				Node_ptr tmp2 = move(CopTreeRand2.GetNode(randomNode2));


				CopTreeRand1.SetNode(randomNode1, move(tmp2));
				CopTreeRand2.SetNode(randomNode2, move(tmp1));
				if (rand() % 2 == 0)
					temp.Population[i] = CopTreeRand1;
				else temp.Population[i] = CopTreeRand2;
				if (temp.Population[i].Root == NULL)
					int o = 0;
				temp.Population[i].SetLastNode(temp.Population[i].Root->SetID(0) - 1); //нумерация ID нового дерева 
				temp.Population[i].SetDepth(temp.Population[i].Root->SetDepth(0));;//нумерация глубины нового дерева 
				//temp.Population[i].Root->setСoefficientNumber(0);
				//temp.Population[i].SetСoefficients();
				//temp.Population[i].SetNumberOfСoef();
			} while (temp.Population[i].GetDepth() > target);
		}return temp;
	}
	void TreeMutation(double probability, int varnum, double min, double max) {
		int randomNode = 0, SubTreeDepth = 0;
		for (int i = 0; i < GetSize(); i++) {
			double p = randomDouble(0., 1.);
			if (p < probability) {
				randomNode = randomInt(0, Population[i].GetLastNode());//рандом узла			
				Node_ptr tmp1 = move(Population[i].GetNode(randomNode));//выдераем поддерево
				SubTreeDepth = tmp1->SetDepth(0);//считаем его длину
				Node_ptr SubTree;
				SubTree.reset(new Node(0, varnum, min, max));//новое поддерево такой же глубины
				Population[i].SetNode(randomNode, move(SubTree));//вставляем новое поддерево
			}
		}
	}

	void Print() {
		cout << "\n=================\n";
 		for (int i = 0; i < info.Size; i++) 
			Population[i].Print();
		cout << "\n=================\n";
	}
};