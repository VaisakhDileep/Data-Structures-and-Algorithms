/*
Created by  : Vaisakh Dileep
Date        : 2, December, 2021
Description : Declaration file for weighed_directed_graph_using_adjacency_list.
*/

#ifndef _WEIGHED_DIRECTED_GRAPH_USING_ADJACENCY_LIST_HPP_
#define _WEIGHED_DIRECTED_GRAPH_USING_ADJACENCY_LIST_HPP_

namespace weighed_directed_graph_using_adjacency_list
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

    struct Weighed_Directed_Graph
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

    void display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph);

    void delete_linked_list(Linked_list *L);

    void delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph);

    void handle_delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph);

    void add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge);

    void handle_add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge);

    void create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges);

    void handle_create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges);
}

namespace WDGAL = weighed_directed_graph_using_adjacency_list;

#endif