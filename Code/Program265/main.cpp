/*
Created by  : Vaisakh Dileep
Date        : 26, June, 2021
Description : This program creates a directed graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<iostream>

#include<vector>

using namespace std;

struct Directed_Graph // Using adjacency matrix.
{
    vector<vector<int>*> *A; // dynamically created 2-D array.
};

struct Edge
{
    int vertex_1;

    int vertex_2;
};

int main()
{
    Directed_Graph d_graph {new vector<vector<int>*> {new vector<int> {0, 1, 0, 0, 1}, new vector<int> {0, 0, 1, 0, 0}, new vector<int> {1, 1, 0, 0, 0}, new vector<int> {1, 1, 0, 0, 0}, new vector<int> {1, 0, 0, 0, 0}}};

    return 0;
}