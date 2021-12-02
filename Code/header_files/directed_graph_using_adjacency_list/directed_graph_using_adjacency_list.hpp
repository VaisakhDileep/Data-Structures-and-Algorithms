/*
Created by  : Vaisakh Dileep
Date        : 1, December, 2021
Description : Declaration file for directed_graph_using_adjacency_list.
*/

#ifndef _DIRECTED_GRAPH_USING_ADJACENCY_LIST_HPP_
#define _DIRECTED_GRAPH_USING_ADJACENCY_LIST_HPP_

namespace directed_graph_using_adjacency_list
{
    struct Node
    {
        int vertex;

        Node *next;
    };

    struct Linked_list
    {
        Node *head;
    };

    struct Edge
    {
        int vertex_1;

        int vertex_2;
    };

    struct Directed_Graph
    {
        Linked_list **A;

        int n;
    };

    void display_directed_graph(Directed_Graph *d_graph);

    void delete_linked_list(Linked_list *L);

    void delete_directed_graph(Directed_Graph *d_graph);

    void handle_delete_directed_graph(Directed_Graph *d_graph);

    void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge);

    void handle_add_edge_directed_graph(Directed_Graph *d_graph, Edge edge);

    void create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges);

    void handle_create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges);
}

namespace DGAL = directed_graph_using_adjacency_list;

#endif