/*
Created by  : Vaisakh Dileep
Date		: 6, June, 2021
Description : This program creates a binary tree.
*/

#include<iostream>

#include<climits>

using namespace std;

struct Binary_Tree
{
	int *A;

	int size;
};

int main()
{
	Binary_Tree T {new int[7] {1, 2, 3, INT_MIN, INT_MIN, 4, INT_MIN}, 7};

	return 0;
}