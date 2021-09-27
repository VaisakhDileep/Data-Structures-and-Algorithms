/*
Created by  : Vaisakh Dileep
Date        : 27, June, 2021
Description : This program creates a directed graph from an array of edges.
*/

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

struct Directed_Graph
{
    vector<vector<int>*> *A;
};

struct Edge
{
    int vertex_1;

    int vertex_2;
};

void display_directed_graph(Directed_Graph *d_graph)
{
    if((d_graph == nullptr) or (d_graph->A == nullptr) or (d_graph->A->size() == 0))
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n     ";
    for(int i {0}; i < d_graph->A->at(0)->size(); i++)
    {
        cout<<setw(3)<<i<<" ";
    }
    cout<<"\n";

    for(int i {0}; i < d_graph->A->size(); i++)
    {
        cout<<setw(3)<<left<<i<<right<<"[ ";
        for(int j {0}; j < d_graph->A->at(0)->size(); j++)
        {
            if(d_graph->A->at(i)->at(j) == INT_MAX)
            {
                cout<<"INF"<<" ";
            }
            else
            {
                cout<<setw(3)<<d_graph->A->at(i)->at(j)<<" ";
            }
        }
        cout<<"]\n";
    }
    cout<<"]";
}

void delete_directed_graph(Directed_Graph *d_graph)
{
    if(d_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((d_graph->A == nullptr) or (d_graph->A->size() == 0))
    {
        return ;
    }

    for(int i {0}; i < d_graph->A->size(); i++)
    {
        delete d_graph->A->at(i);
    }

    delete d_graph->A;
}

void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
    if(d_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((d_graph->A == nullptr) or (d_graph->A->size() == 0))
    {
        d_graph->A = new vector<vector<int>*> {new vector<int> {}};
    }

    if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if((edge.vertex_1 < d_graph->A->size()) and (edge.vertex_2 < d_graph->A->at(0)->size()))
    {
        d_graph->A->at(edge.vertex_1)->at(edge.vertex_2) = 1;
    }
    else
    {
        int new_rows {(edge.vertex_1 > (static_cast<int>(d_graph->A->size()) - 1)) ? edge.vertex_1 + 1 : d_graph->A->size()};

        int new_columns {(edge.vertex_2 > (static_cast<int>(d_graph->A->at(0)->size()) - 1)) ? edge.vertex_2 + 1 : d_graph->A->at(0)->size()};

        Directed_Graph temp {new vector<vector<int> *>(new_rows, nullptr)};

        for(int i {0}; i < new_rows; i++)
        {
            temp.A->at(i) = new vector<int>(new_columns, 0);
        }

        for(int i {0}; i < d_graph->A->size(); i++)
        {
            for(int j {0}; j < d_graph->A->at(0)->size(); j++)
            {
                temp.A->at(i)->at(j) = d_graph->A->at(i)->at(j);
            }
        }

        temp.A->at(edge.vertex_1)->at(edge.vertex_2) = 1;

        delete_directed_graph(d_graph);

        d_graph->A = temp.A;
    }
}

void create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
{
    if(d_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < num_edges; i++)
    {
        try
        {
            add_edge_directed_graph(d_graph, edges[i]);
        }
        catch(string &ex)
        {
            throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
        }
    }
}

void handle_create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
{
    try
    {
        create_directed_graph(d_graph, edges, num_edges);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Directed_Graph d_graph {};

    Edge edges[10] {Edge {0, 1}, Edge {1, 5}, Edge {9, 0}, Edge {0, 9}, Edge {10, 1}, Edge {2, 8}, Edge {11, 11}, Edge {4, 2}, Edge {9, 8}, Edge {5, 8}};

    handle_create_directed_graph(&d_graph, edges, 10);

    cout<<"d_graph: \n";
    display_directed_graph(&d_graph);
    cout<<"\n";

    return 0;
}