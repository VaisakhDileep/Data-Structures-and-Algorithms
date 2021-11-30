/*
Created by  : Vaisakh Dileep
Date        : 29, November, 2021
Description : Definition file for undirected_graph_using_adjacency_list.
*/

#include "undirected_graph_using_adjacency_list.hpp"

#include<iostream>

#include<iomanip>

using namespace std;

void UGAL::display_undirected_graph(Undirected_Graph *u_graph)
{
    if(u_graph == nullptr)
    {
        return ;
    }

    for(int i {0}; i < u_graph->n; i++)
    {
        if(u_graph->A[i] == nullptr)
        {
            continue;
        }
        else
        {
            cout<<setw(3)<<left<<i;

            Node *last {u_graph->A[i]->head};

            while(last != nullptr)
            {
                cout<<" -> "<<setw(3)<<last->vertex;

                last = last->next;
            }
            cout<<"\n";
        }
    }
}

void UGAL::delete_linked_list(Linked_list *L)
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

void UGAL::delete_undirected_graph(Undirected_Graph *u_graph)
{
    if(u_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < u_graph->n; i++)
    {
        if(u_graph->A[i] != nullptr)
        {
            delete_linked_list(u_graph->A[i]);

            u_graph->A[i] = nullptr;
        }
    }

    delete[] u_graph->A;
}

void UGAL::handle_delete_undirected_graph(Undirected_Graph *u_graph)
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

void UGAL::add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
{
    if(u_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if((edge.vertex_1 < u_graph->n) and (edge.vertex_2 < u_graph->n))
    {
        if(u_graph->A[edge.vertex_1] == nullptr)
        {
            u_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
        }
        else
        {
            Node *last {u_graph->A[edge.vertex_1]->head}, *previous_node {};

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

        if(edge.vertex_1 == edge.vertex_2)
        {
            return ;
        }

        if(u_graph->A[edge.vertex_2] == nullptr)
        {
            u_graph->A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, nullptr}};
        }
        else
        {
            Node *last {u_graph->A[edge.vertex_2]->head}, *previous_node {};

            while(last != nullptr)
            {
                previous_node = last;

                if(last->vertex == edge.vertex_1)
                {
                    throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                }

                last = last->next;
            }

            previous_node->next = new Node {edge.vertex_1, nullptr};
        }
    }
    else
    {
        int new_n {edge.vertex_1 > edge.vertex_2 ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

        Undirected_Graph temp {new Linked_list*[new_n] {}, new_n};

        for(int i {0}; i < u_graph->n; i++)
        {
            temp.A[i] = u_graph->A[i];
        }

        if(temp.A[edge.vertex_1] == nullptr)
        {
            temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
        }
        else
        {
            Node *last {temp.A[edge.vertex_1]->head}, *previous_node {};

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

        if(edge.vertex_1 == edge.vertex_2)
        {
            u_graph->A = temp.A;

            temp.A = nullptr;

            u_graph->n = temp.n;

            return ;
        }

        if(temp.A[edge.vertex_2] == nullptr)
        {
            temp.A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, nullptr}};
        }
        else
        {
            Node *last {temp.A[edge.vertex_2]->head}, *previous_node {};

            while(last != nullptr)
            {
                previous_node = last;

                if(last->vertex == edge.vertex_1)
                {
                    throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                }

                last = last->next;
            }

            previous_node->next = new Node {edge.vertex_1, nullptr};
        }

        u_graph->A = temp.A;

        temp.A = nullptr;

        u_graph->n = temp.n;
    }
}

void UGAL::handle_add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
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

void UGAL::create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
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

void UGAL::handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
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