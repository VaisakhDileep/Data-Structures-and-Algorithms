/*
Created by  : Vaisakh Dileep
Date        : 2, December, 2021
Description : Declaration file for weighed_directed_graph_using_adjacency_list.
*/

#include "weighed_directed_graph_using_adjacency_list.hpp"

#include<iostream>

#include<iomanip>

using namespace std;

void WDGAL::display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    if(wd_graph == nullptr)
    {
        return ;
    }

    for(int i {0}; i < wd_graph->n; i++)
    {
        if(wd_graph->A[i] == nullptr)
        {
            continue;
        }
        else
        {
            cout<<setw(3)<<left<<i;

            Node *last {wd_graph->A[i]->head};

            while(last != nullptr)
            {
                cout<<" -["<<setw(3)<<last->weight<<"]-> "<<setw(3)<<last->vertex;

                last = last->next;
            }
            cout<<"\n";
        }
    }
}

void WDGAL::delete_linked_list(Linked_list *L)
{
    Node *last {L->head};

    while(last != nullptr)
    {
        Node *temp {last->next};

        delete last;

        last = temp;
    }

    L->head = nullptr;
}

void WDGAL::delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < wd_graph->n; i++)
    {
        if(wd_graph->A[i] != nullptr)
        {
            delete_linked_list(wd_graph->A[i]);

            wd_graph->A[i] = nullptr;
        }
    }

    delete[] wd_graph->A;
}

void WDGAL::handle_delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
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

void WDGAL::add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if(w_edge.vertex_1 < wd_graph->n)
    {
        if(wd_graph->A[w_edge.vertex_1] == nullptr)
        {
            wd_graph->A[w_edge.vertex_1] = new Linked_list {new Node {w_edge.vertex_2, w_edge.weight, nullptr}};
        }
        else
        {
            Node *last {wd_graph->A[w_edge.vertex_1]->head}, *previous_node {};

            while(last != nullptr)
            {
                previous_node = last;

                if(last->vertex == w_edge.vertex_2)
                {
                    throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                }

                last = last->next;
            }

            previous_node->next = new Node {w_edge.vertex_2, w_edge.weight, nullptr};
        }
    }
    else
    {
        int new_n {w_edge.vertex_1 + 1};

        Weighed_Directed_Graph temp {new Linked_list*[new_n] {}, new_n};

        for(int i {0}; i < wd_graph->n; i++)
        {
            temp.A[i] = wd_graph->A[i];
        }

        temp.A[w_edge.vertex_1] = new Linked_list {new Node {w_edge.vertex_2, w_edge.weight, nullptr}};

        wd_graph->A = temp.A;

        temp.A = nullptr;

        wd_graph->n = temp.n;
    }
}

void WDGAL::handle_add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
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

void WDGAL::create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
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

void WDGAL::handle_create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
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