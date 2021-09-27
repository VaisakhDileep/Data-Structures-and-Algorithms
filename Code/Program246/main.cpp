/*
Created by  : Vaisakh Dileep
Date        : 19, June, 2021
Description : This program deletes a weighed undirected graph.
*/

#include<iostream>

#include<vector>

using namespace std;

struct Weighed_Undirected_Graph
{
    vector<vector<int>*> *A;
};

struct Weighed_Edge
{
    int vertex_1;

    int vertex_2;

    int weight;
};

void delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
    {
        return ;
    }

    for(int i {0}; i < wu_graph->A->size(); i++)
    {
        delete wu_graph->A->at(i);
    }

    delete wu_graph->A;
}

void handle_delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    try
    {
        delete_weighed_undirected_graph(wu_graph);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Weighed_Undirected_Graph wu_graph {new vector<vector<int>*> {new vector<int> {0, 3, INT_MAX, INT_MAX, 7}, new vector<int> {3, 0, INT_MAX, INT_MAX, INT_MAX}, new vector<int> {INT_MAX, INT_MAX, 0, 8, INT_MAX}, new vector<int> {INT_MAX, INT_MAX, 8, 0, INT_MAX}, new vector<int> {7, INT_MAX, INT_MAX, INT_MAX, 0}}};

    handle_delete_weighed_undirected_graph(&wu_graph);

    return 0;
}