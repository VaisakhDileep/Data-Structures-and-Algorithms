/*
Created by  : Vaisakh Dileep
Date        : 29, November, 2021
Description : Definition file for undirected_graph_using_adjacency_matrix.
*/

#include "undirected_graph_using_adjacency_matrix.hpp"

#include<iostream>

#include<iomanip>

using namespace std;

void UGAM::display_undirected_graph(Undirected_Graph *u_graph)
{
    if((u_graph == nullptr) or (u_graph->A == nullptr) or (u_graph->A->size() == 0))
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n     ";
    for(int i {0}; i < u_graph->A->size(); i++)
    {
        cout<<setw(3)<<i<<" ";
    }
    cout<<"\n";

    for(int i {0}; i < u_graph->A->size(); i++)
    {
        cout<<setw(3)<<left<<i<<right<<"[ ";
        for(int j {0}; j < u_graph->A->size(); j++)
        {
            cout<<setw(3)<<u_graph->A->at(i)->at(j)<<" ";
        }
        cout<<"]\n";
    }
    cout<<"]";
}

void UGAM::delete_undirected_graph(Undirected_Graph *u_graph)
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

void UGAM::handle_delete_undirected_graph(Undirected_Graph *u_graph)
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

void UGAM::add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
{
    if(u_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((u_graph->A == nullptr) or (u_graph->A->size() == 0))
    {
        u_graph->A = new vector<vector<int>*> {new vector<int> {}};
    }

    if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if((edge.vertex_1 < u_graph->A->size()) and (edge.vertex_2 < u_graph->A->size()))
    {
        u_graph->A->at(edge.vertex_1)->at(edge.vertex_2) = u_graph->A->at(edge.vertex_2)->at(edge.vertex_1) = 1;
    }
    else
    {
        int new_n {(edge.vertex_1 > edge.vertex_2) ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

        Undirected_Graph temp {new vector<vector<int>*>(new_n, nullptr)};

        for(int i {0}; i < new_n; i++)
        {
            temp.A->at(i) = new vector<int>(new_n, 0);
        }

        for(int i {0}; i < u_graph->A->size(); i++)
        {
            for(int j {0}; j < u_graph->A->at(0)->size(); j++)
            {
                temp.A->at(i)->at(j) = u_graph->A->at(i)->at(j);
            }
        }

        temp.A->at(edge.vertex_1)->at(edge.vertex_2) = temp.A->at(edge.vertex_2)->at(edge.vertex_1) = 1;

        UGAM::delete_undirected_graph(u_graph);

        u_graph->A = temp.A;
    }
}

void UGAM::handle_add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
{
    try
    {
        add_edge_undirected_graph(u_graph, edge);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void UGAM::create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
{
    if(u_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < num_edges; i++)
    {
        try
        {
            add_edge_undirected_graph(u_graph, edges[i]);
        }
        catch(string &ex)
        {
            throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
        }
    }
}

void UGAM::handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
{
    try
    {
        create_undirected_graph(u_graph, edges, num_edges);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}