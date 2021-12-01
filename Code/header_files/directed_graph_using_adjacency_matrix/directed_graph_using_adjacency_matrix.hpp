/*
Created by  : Vaisakh Dileep
Date        : 1, December, 2021
Description : Declaration file for directed_graph_using_adjacency_matrix.
*/

#include<vector>

#ifndef _DIRECTED_GRAPH_USING_ADJACENCY_MATRIX_HPP_
#define _DIRECTED_GRAPH_USING_ADJACENCY_MATRIX_HPP_

namespace directed_graph_using_adjacency_matrix
{
    struct Directed_Graph
    {
        std::vector<std::vector<int>*> *A;
    };

    struct Edge
    {
        int vertex_1;

        int vertex_2;
    };

    void display_directed_graph(Directed_Graph *d_graph);

    void delete_directed_graph(Directed_Graph *d_graph);

    void handle_delete_directed_graph(Directed_Graph *d_graph);

    void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge);

    void handle_add_edge_directed_graph(Directed_Graph *d_graph, Edge edge);

    void create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges);

    void handle_create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges);
}

namespace DGAM = directed_graph_using_adjacency_matrix;

#endif