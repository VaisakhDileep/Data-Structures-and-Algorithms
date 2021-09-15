/*
Created by  : Vaisakh Dileep
Date		: 15, September, 2021
Description : This program demonstrates the union-find algorithm.
*/

#include<iostream>

#include<vector>

using namespace std;

vector<int>* create_disjoint_sets(int size)
{
	return new vector<int>(size, -1);
}

int Find(vector<int>* disjoint_sets, int target) // Finds the root of the disjoint set.
{
	if(disjoint_sets->at(target) == -1)
	{
		return target;
	}

	return Find(disjoint_sets, disjoint_sets->at(target));
}

void Union(vector<int>* disjoint_sets, int target_1, int target_2) // Preforms Union operator on the two subsets.
{
	int target_1_root {Find(disjoint_sets, target_1)};

	int target_2_root {Find(disjoint_sets, target_2)};

	if(target_1_root == target_2_root) // Both the elements are already in the same set.
	{
		return ;
	}

	disjoint_sets->at(target_1_root) = target_2_root;
}

int main()
{
	vector<int>* disjoint_sets {create_disjoint_sets(10)};

	Union(disjoint_sets, 6, 4);
	Union(disjoint_sets, 6, 8);
	Union(disjoint_sets, 6, 8);

	cout<<"Find(disjoint_sets, 6): "<<Find(disjoint_sets, 6)<<"\n";
	cout<<"Find(disjoint_sets, 8): "<<Find(disjoint_sets, 8)<<"\n";
	cout<<"Find(disjoint_sets, 4): "<<Find(disjoint_sets, 4)<<"\n";

	return 0;
}