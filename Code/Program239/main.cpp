/*
Created by  : Vaisakh Dileep
Date        : 17, June, 2021
Description : This program deletes an undirected graph.
*/

#include<iostream>

#include<vector>

using namespace std;

struct Undirected_Graph
{
    vector<vector<int>*> *A;
};

struct Edge
{
    int vertex_1;

    int vertex_2;
};

void delete_undirected_graph(Undirected_Graph *u_graph)
{
    if(u_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((u_graph->A == nullptr) or (u_graph->A->size() == 0))
    {
        return ;
    }

    for(int i {0}; i < u_graph->A->size(); i++)
    {
        delete u_graph->A->at(i);
    }

    delete u_graph->A;
}

void handle_delete_undirected_graph(Undirected_Graph *u_graph)
{
    try
    {
        delete_undirected_graph(u_graph);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Undirected_Graph u_graph {new vector<vector<int>*> {new vector<int> {0, 1, 1, 1, 0}, new vector<int> {1, 0, 1, 0, 0}, new vector<int> {1, 1, 0, 1, 1}, new vector<int> {1, 0, 1, 0, 1}, new vector<int> {0, 0, 1, 1, 0}}};

    handle_delete_undirected_graph(&u_graph);

    return 0;
}