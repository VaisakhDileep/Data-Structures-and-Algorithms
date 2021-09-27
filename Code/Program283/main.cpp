/*
Created by  : Vaisakh Dileep
Date        : 29, June, 2021
Description : This program removes an edge from a weighed directed graph.
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

void remove_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((wd_graph->A == nullptr) or (wd_graph->A->size() == 0)) // If the graph is empty.
    {
        return ;
    }

    if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if((w_edge.vertex_1 >= wd_graph->A->size()) or (w_edge.vertex_2 >= wd_graph->A->at(0)->size()))
    {
        throw string {"ERROR - Invalid operation, given edge not present in the graph ....."};
    }

    if(w_edge.vertex_1 == w_edge.vertex_2)
    {
        wd_graph->A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = 0;
    }
    else
    {
        wd_graph->A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = INT_MAX;
    }
}

void handle_remove_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
{
    try
    {
        remove_edge_weighed_directed_graph(wd_graph, w_edge);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Weighed_Directed_Graph wd_graph {new vector<vector<int>*> {new vector<int> {10, INT_MAX, 4}, new vector<int> {1, 0, INT_MAX}, new vector<int> {1, 2, 0}, new vector<int> {7, 5, INT_MAX}, new vector<int> {8, 3, 2}}};

    cout<<"wd_graph: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 2, 0}); // Providing "weight" is not necessary.

    cout<<"wd_graph [after removing {0, 2}]: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 0, 0});

    cout<<"wd_graph [after removing {0, 0}]: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {-1, 2});
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 3});
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 5});
    cout<<"\n";

    return 0;
}