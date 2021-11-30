/*
Created by  : Vaisakh Dileep
Date        : 30, November, 2021
Description : Definition file for weighed_undirected_graph_using_adjacency_list.
*/

#include "weighed_undirected_graph_using_adjacency_list.hpp"

#include<iostream>

#include<iomanip>

using namespace std;

void WUGAL::display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    if(wu_graph == nullptr)
    {
        return ;
    }

    for(int i {0}; i < wu_graph->n; i++)
    {
        if(wu_graph->A[i] == nullptr)
        {
            continue;
        }
        else
        {
            cout<<setw(3)<<left<<i;

            Node *last {wu_graph->A[i]->head};

            while(last != nullptr)
            {
                cout<<" -["<<setw(3)<<last->weight<<"]-> "<<setw(3)<<last->vertex;

                last = last->next;
            }
            cout<<"\n";
        }
    }
}

void WUGAL::delete_linked_list(Linked_list *L)
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

void WUGAL::delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < wu_graph->n; i++)
    {
        if(wu_graph->A[i] != nullptr)
        {
            delete_linked_list(wu_graph->A[i]);

            wu_graph->A[i] = nullptr;
        }
    }

    delete[] wu_graph->A;
}

void WUGAL::handle_delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    try
    {
        delete_weighed_undirected_graph(wu_graph);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void WUGAL::add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if((w_edge.vertex_1 < wu_graph->n) and (w_edge.vertex_2 < wu_graph->n))
    {
        if(wu_graph->A[w_edge.vertex_1] == nullptr)
        {
            wu_graph->A[w_edge.vertex_1] = new Linked_list {new Node {w_edge.vertex_2, w_edge.weight, nullptr}};
        }
        else
        {
            Node *last {wu_graph->A[w_edge.vertex_1]->head}, *previous_node {};

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

        if(w_edge.vertex_1 == w_edge.vertex_2)
        {
            return ;
        }

        if(wu_graph->A[w_edge.vertex_2] == nullptr)
        {
            wu_graph->A[w_edge.vertex_2] = new Linked_list {new Node {w_edge.vertex_1, w_edge.weight, nullptr}};
        }
        else
        {
            Node *last {wu_graph->A[w_edge.vertex_2]->head}, *previous_node {};

            while(last != nullptr)
            {
                previous_node = last;

                if(last->vertex == w_edge.vertex_1)
                {
                    throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                }

                last = last->next;
            }

            previous_node->next = new Node {w_edge.vertex_1, w_edge.weight, nullptr};
        }
    }
    else
    {
        int new_n {w_edge.vertex_1 > w_edge.vertex_2 ? w_edge.vertex_1 + 1 : w_edge.vertex_2 + 1};

        Weighed_Undirected_Graph temp {new Linked_list*[new_n] {}, new_n};

        for(int i {0}; i < wu_graph->n; i++)
        {
            temp.A[i] = wu_graph->A[i];
        }

        if(temp.A[w_edge.vertex_1] == nullptr)
        {
            temp.A[w_edge.vertex_1] = new Linked_list {new Node {w_edge.vertex_2, w_edge.weight, nullptr}};
        }
        else
        {
            Node *last {temp.A[w_edge.vertex_1]->head}, *previous_node {};

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

        if(w_edge.vertex_1 == w_edge.vertex_2)
        {
            wu_graph->A = temp.A;

            temp.A = nullptr;

            wu_graph->n = temp.n;

            return ;
        }

        if(temp.A[w_edge.vertex_2] == nullptr)
        {
            temp.A[w_edge.vertex_2] = new Linked_list {new Node {w_edge.vertex_1, w_edge.weight, nullptr}};
        }
        else
        {
            Node *last {temp.A[w_edge.vertex_2]->head}, *previous_node {};

            while(last != nullptr)
            {
                previous_node = last;

                if(last->vertex == w_edge.vertex_1)
                {
                    throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                }

                last = last->next;
            }

            previous_node->next = new Node {w_edge.vertex_1, w_edge.weight, nullptr};
        }

        wu_graph->A = temp.A;

        temp.A = nullptr;

        wu_graph->n = temp.n;
    }
}

void WUGAL::handle_add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
    try
    {
        add_edge_weighed_undirected_graph(wu_graph, w_edge);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void WUGAL::create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
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

void WUGAL::handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
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