/*
Created by  : Vaisakh Dileep
Date        : 2, December, 2021
Description : Definition file for weighed_directed_graph_using_adjacency_matrix.
*/

#include "weighed_directed_graph_using_adjacency_matrix.hpp"

#include<iostream>

#include<iomanip>

using namespace std;

void WDGAM::display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
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

void WDGAM::delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
    {
        return ;
    }

    for(int i {0}; i < wd_graph->A->size(); i++)
    {
        delete wd_graph->A->at(i);
    }

    delete wd_graph->A;
}

void WDGAM::handle_delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    try
    {
        delete_weighed_directed_graph(wd_graph);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void WDGAM::add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
    {
        wd_graph->A = new vector<vector<int>*> {new vector<int> {}};
    }

    if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if((w_edge.vertex_1 < wd_graph->A->size()) and (w_edge.vertex_2 < wd_graph->A->at(0)->size()))
    {
        wd_graph->A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = w_edge.weight;
    }
    else
    {
        int new_rows {(w_edge.vertex_1 > (static_cast<int>(wd_graph->A->size()) - 1)) ? w_edge.vertex_1 + 1 : wd_graph->A->size()};

        int new_columns {(w_edge.vertex_2 > (static_cast<int>(wd_graph->A->at(0)->size()) - 1)) ? w_edge.vertex_2 + 1 : wd_graph->A->at(0)->size()};

        Weighed_Directed_Graph temp {new vector<vector<int>*>(new_rows, nullptr)};

        for(int i {0}; i < new_rows; i++)
        {
            temp.A->at(i) = new vector<int>(new_columns, INT_MAX);
        }

        for(int i {0}; i < wd_graph->A->size(); i++)
        {
            for(int j {0}; j < wd_graph->A->at(0)->size(); j++)
            {
                temp.A->at(i)->at(j) = wd_graph->A->at(i)->at(j);
            }
        }

        temp.A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = w_edge.weight;

        delete_weighed_directed_graph(wd_graph);

        wd_graph->A = temp.A;
    }

    for(int i {0}; i < wd_graph->A->size(); i++)
    {
        if(i == wd_graph->A->at(0)->size())
        {
            break;
        }

        if(wd_graph->A->at(i)->at(i) == INT_MAX)
        {
            wd_graph->A->at(i)->at(i) = 0;
        }
    }
}

void WDGAM::handle_add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
{
    try
    {
        add_edge_weighed_directed_graph(wd_graph, w_edge);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void WDGAM::create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < num_edges; i++)
    {
        try
        {
            add_edge_weighed_directed_graph(wd_graph, w_edges[i]);
        }
        catch(string &ex)
        {
            throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
        }
    }
}

void WDGAM::handle_create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
{
    try
    {
        create_weighed_directed_graph(wd_graph, w_edges, num_edges);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}