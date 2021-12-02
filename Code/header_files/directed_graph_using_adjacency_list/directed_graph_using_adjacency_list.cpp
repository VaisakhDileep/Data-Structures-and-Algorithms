/*
Created by  : Vaisakh Dileep
Date        : 2, December, 2021
Description : Definition file for directed_graph_using_adjacency_list.
*/

#include "directed_graph_using_adjacency_list.hpp"

#include<iostream>

#include<iomanip>

using namespace std;

void DGAL::display_directed_graph(Directed_Graph *d_graph)
{
    if(d_graph == nullptr)
    {
        return ;
    }

    for(int i {0}; i < d_graph->n; i++)
    {
        if(d_graph->A[i] == nullptr)
        {
            continue;
        }
        else
        {
            cout<<setw(3)<<left<<i;

            Node *last {d_graph->A[i]->head};

            while(last != nullptr)
            {
                cout<<" -> "<<setw(3)<<last->vertex;

                last = last->next;
            }
            cout<<"\n";
        }
    }
}

void DGAL::delete_linked_list(Linked_list *L)
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

void DGAL::delete_directed_graph(Directed_Graph *d_graph)
{
    if(d_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < d_graph->n; i++)
    {
        if(d_graph->A[i] != nullptr)
        {
            delete_linked_list(d_graph->A[i]);

            d_graph->A[i] = nullptr;
        }
    }

    delete[] d_graph->A;
}

void DGAL::handle_delete_directed_graph(Directed_Graph *d_graph)
{
    try
    {
        delete_directed_graph(d_graph);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void DGAL::add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
    if(d_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if(edge.vertex_1 < d_graph->n)
    {
        if(d_graph->A[edge.vertex_1] == nullptr)
        {
            d_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
        }
        else
        {
            Node *last {d_graph->A[edge.vertex_1]->head}, *previous_node {};

            while(last != nullptr)
            {
                previous_node = last;

                if(last->vertex == edge.vertex_2)
                {
                    throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                }

                last = last->next;
            }

            previous_node->next = new Node {edge.vertex_2, nullptr};
        }
    }
    else
    {
        int new_n {edge.vertex_1 + 1};

        Directed_Graph temp {new Linked_list*[new_n] {}, new_n};

        for(int i {0}; i < d_graph->n; i++)
        {
            temp.A[i] = d_graph->A[i];
        }

        temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};

        d_graph->A = temp.A;

        temp.A = nullptr;

        d_graph->n = temp.n;
    }
}

void DGAL::handle_add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
    try
    {
        add_edge_directed_graph(d_graph, edge);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void DGAL::create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
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

void DGAL::handle_create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
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