/*
Created by  : Vaisakh Dileep
Date        : 28, June, 2021
Description : This program displays a weighed directed graph.
*/

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

struct Weighed_Directed_Graph
{
    vector<vector<int>*> *A;
};

struct Weighed_Edge
{
    int vertex_1;

    int vertex_2;

    int weight;
};

void display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    if((wd_graph == nullptr) or (wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n     ";
    for(int i {0}; i < wd_graph->A->at(0)->size(); i++)
    {
        cout<<setw(3)<<i<<" ";
    }
    cout<<"\n";

    for(int i {0}; i < wd_graph->A->size(); i++)
    {
        cout<<setw(3)<<left<<i<<right<<"[ ";
        for(int j {0}; j < wd_graph->A->at(0)->size(); j++)
        {
            if(wd_graph->A->at(i)->at(j) == INT_MAX)
            {
                cout<<"INF"<<" ";
            }
            else
            {
                cout<<setw(3)<<wd_graph->A->at(i)->at(j)<<" ";
            }
        }
        cout<<"]\n";
    }
    cout<<"]";
}

int main()
{
    Weighed_Directed_Graph wd_graph {new vector<vector<int>*> {new vector<int> {0, INT_MAX, 4}, new vector<int> {1, 0, INT_MAX}, new vector<int> {1, 2, 0}, new vector<int> {7, 5, INT_MAX}, new vector<int> {8, 3, 2}}};

    cout<<"wd_graph: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    return 0;
}