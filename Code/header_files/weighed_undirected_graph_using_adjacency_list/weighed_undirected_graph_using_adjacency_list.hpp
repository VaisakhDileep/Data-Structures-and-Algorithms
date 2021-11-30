/*
Created by  : Vaisakh Dileep
Date        : 30, November, 2021
Description : Declaration file for weighed_undirected_graph_using_adjacency_list.
*/

#ifndef _WEIGHED_UNDIRECTED_GRAPH_USING_ADJACENCY_LIST_HPP_
#define _WEIGHED_UNDIRECTED_GRAPH_USING_ADJACENCY_LIST_HPP_

namespace weighed_undirected_graph_using_adjacency_list
{
    struct Node
    {
        int vertex;

        int weight;

        Node *next;
    };

    struct Linked_list
    {
        Node *head;
    };

    struct Weighed_Undirected_Graph
    {
        Linked_list **A;

        int n;
    };

    struct Weighed_Edge
    {
        int vertex_1;

        int vertex_2;

        int weight;
    };

    void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph);

    void delete_linked_list(Linked_list *L);

    void delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph);

    void handle_delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph);

    void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge edge);

    void handle_add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge edge);

    void create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges);

    void handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges);
}

namespace WUGAL = weighed_undirected_graph_using_adjacency_list;

#endif