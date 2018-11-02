#pragma once
#include "pch.h"
#include "Forest.h"
#include <time.h>
#include <fstream>

using namespace std;

int main() {
	srand((unsigned int)time(NULL));


	ifstream fin("1x.txt");
	ifstream fin1("1y.txt");
	int varnum = 1, n = 100;
	vector< vector<double> > x(n, vector<double>(varnum));
	vector<double> y(n);
	cout << "x" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < varnum; j++) {
			fin >> x[i][j];
			cout << x[i][j] << "\t";
		}cout << endl;
	}
	cout << "y" << endl;
	for (int i = 0; i < n; i++) {
		fin1 >> y[i];
		cout << y[i] << endl;
	}

	double MutationProbability = 0.5;
	int Depth = 4;
	int NumberOfIndivids = 10;
	int NumberOfGenerations = 10;
	double min = -10.;
	double max = 10.;
	vector<int>Nm;



	Forest ParentPopulation(NumberOfIndivids, Depth, varnum, min, max), DescendentPopulation;
	ParentPopulation.ForestFitness(n, x, y);
	//ParentPopulation.Print();
	//ParentPopulation.optimize_coefs(n, x, y);
	for (int i = 0; i < NumberOfGenerations; i++) {
		Nm = ParentPopulation.Selection_Tournament(2);
		DescendentPopulation = ParentPopulation.StandartCrossover(5, Nm);
		DescendentPopulation.TreeMutation(MutationProbability, varnum, min, max);
		DescendentPopulation.ForestFitness(n, x, y);
		DescendentPopulation.Print();
		//DescendentPopulation.optimize_coefs(n, x, y);
		if (ParentPopulation.BestIndivid.GetIndFitness() > DescendentPopulation.BestIndivid.GetIndFitness())
			DescendentPopulation.BestIndivid = ParentPopulation.BestIndivid;
		ParentPopulation = DescendentPopulation;
		cout << "fitness = " << ParentPopulation.BestIndivid.GetIndFitness() /*<< "       " << ParentPopulation.BestIndivid.GetMistake()*/ << "             " << i << endl;
		DescendentPopulation.Print();
	}
	DescendentPopulation.Print();
	fout << endl;
	DescendentPopulation.BestIndivid.Print();
	fout.close();
	//system("pause");
	return 0;


}