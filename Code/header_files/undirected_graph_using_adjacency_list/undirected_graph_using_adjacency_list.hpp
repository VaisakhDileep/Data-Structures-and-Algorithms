/*
Created by  : Vaisakh Dileep
Date        : 29, November, 2021
Description : Declaration file for undirected_graph_using_adjacency_list.
*/

#ifndef _UNDIRECTED_GRAPH_USING_ADJACENCY_LIST_HPP_
#define _UNDIRECTED_GRAPH_USING_ADJACENCY_LIST_HPP_

namespace undirected_graph_using_adjacency_list
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

    struct Undirected_Graph
    {
        Linked_list **A;

        int n;
    };

    void display_undirected_graph(Undirected_Graph *u_graph);

    void delete_linked_list(Linked_list *L);

    void delete_undirected_graph(Undirected_Graph *u_graph);

    void handle_delete_undirected_graph(Undirected_Graph *u_graph);

    void add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge);

    void handle_add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge);

    void create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges);

    void handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges);
}

namespace UGAL = undirected_graph_using_adjacency_list;

#endif