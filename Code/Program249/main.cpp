/*
Created by  : Vaisakh Dileep
Date        : 19, June, 2021
Description : This program creates a weighed undirected graph from an array of edges.
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

void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
    {
        wu_graph->A = new vector<vector<int>*> {new vector<int> {}};
    }

    if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if((w_edge.vertex_1 < wu_graph->A->size()) and (w_edge.vertex_2 < wu_graph->A->size()))
    {
        wu_graph->A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = wu_graph->A->at(w_edge.vertex_2)->at(w_edge.vertex_1) = w_edge.weight;
    }
    else
    {
        int new_n {(w_edge.vertex_1 > w_edge.vertex_2) ? w_edge.vertex_1 + 1 : w_edge.vertex_2 + 1};

        Weighed_Undirected_Graph temp {new vector<vector<int>*>(new_n, nullptr)};

        for(int i {0}; i < new_n; i++)
        {
            temp.A->at(i) = new vector<int>(new_n, INT_MAX);
        }

        for(int i {0}; i < wu_graph->A->size(); i++)
        {
            for(int j {0}; j < wu_graph->A->at(0)->size(); j++)
            {
                temp.A->at(i)->at(j) = wu_graph->A->at(i)->at(j);
            }
        }

        temp.A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = temp.A->at(w_edge.vertex_2)->at(w_edge.vertex_1) = w_edge.weight;

        delete_weighed_undirected_graph(wu_graph);

        wu_graph->A = temp.A;

        for(int i {0}; i < wu_graph->A->size(); i++)
        {
            if(wu_graph->A->at(i)->at(i) == INT_MAX)
            {
                wu_graph->A->at(i)->at(i) = 0;
            }
        }
    }
}

void create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < num_edges; i++)
    {
        try
        {
            add_edge_weighed_undirected_graph(wu_graph, w_edges[i]);
        }
        catch(string &ex)
        {
            throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
        }
    }
}

void handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
{
    try
    {
        create_weighed_undirected_graph(wu_graph, w_edges, num_edges);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Weighed_Undirected_Graph wu_graph {};

    Weighed_Edge w_edges[10] {Weighed_Edge {0, 5, 3}, Weighed_Edge {1, 2, 6}, Weighed_Edge {3, 2, 10}, Weighed_Edge {9, 1, 14}, Weighed_Edge {3, 5, 9}, Weighed_Edge {8, 7, 20}, Weighed_Edge {2, 6, 1}, Weighed_Edge {8, 4, 3}, Weighed_Edge {8, 3, 2}, Weighed_Edge {7, 6, 3}};

    create_weighed_undirected_graph(&wu_graph, w_edges, 10);

    cout<<"wu_graph: \n";
    display_weighed_undirected_graph(&wu_graph);
    cout<<"\n";

    return 0;
}