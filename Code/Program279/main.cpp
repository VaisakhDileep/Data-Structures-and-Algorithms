/*
Created by  : Vaisakh Dileep
Date        : 28, June, 2021
Description : This program creates a weighed directed graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<iostream>

#include<vector>

using namespace std;

struct Weighed_Directed_Graph // Using adjacency matrix.
{
    vector<vector<int>*> *A; // dynamically created 2-D array.
};

struct Weighed_Edge
{
    int vertex_1;

    int vertex_2;

    int weight;
};

int main()
{
    Weighed_Directed_Graph wd_graph {new vector<vector<int>*> {new vector<int> {0, INT_MAX, 4}, new vector<int> {1, 0, INT_MAX}, new vector<int> {1, 2, 0}, new vector<int> {7, 5, INT_MAX}, new vector<int> {8, 3, 2}}};

    return 0;
}