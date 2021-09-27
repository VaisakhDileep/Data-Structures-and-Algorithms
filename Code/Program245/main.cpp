/*
Created by  : Vaisakh Dileep
Date        : 19, June, 2021
Description : This program displays a weighed undirected graph.
*/

#include<iostream>

#include<iomanip>

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

void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    if((wu_graph == nullptr) or (wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n     ";
    for(int i {0}; i < wu_graph->A->size(); i++)
    {
        cout<<setw(3)<<i<<" ";
    }
    cout<<"\n";

    for(int i {0}; i < wu_graph->A->size(); i++)
    {
        cout<<setw(3)<<left<<i<<right<<"[ ";
        for(int j {0}; j < wu_graph->A->size(); j++)
        {
            if(wu_graph->A->at(i)->at(j) == INT_MAX)
            {
                cout<<"INF"<<" ";
            }
            else
            {
                cout<<setw(3)<<wu_graph->A->at(i)->at(j)<<" ";
            }
        }
        cout<<"]\n";
    }
    cout<<"]";
}

int main()
{
    Weighed_Undirected_Graph wu_graph {new vector<vector<int>*> {new vector<int> {0, 3, INT_MAX, INT_MAX, 7}, new vector<int> {3, 0, INT_MAX, INT_MAX, INT_MAX}, new vector<int> {INT_MAX, INT_MAX, 0, 8, INT_MAX}, new vector<int> {INT_MAX, INT_MAX, 8, 0, INT_MAX}, new vector<int> {7, INT_MAX, INT_MAX, INT_MAX, 0}}};

    cout<<"wu_graph: \n";
    display_weighed_undirected_graph(&wu_graph);
    cout<<"\n";

    return 0;
}