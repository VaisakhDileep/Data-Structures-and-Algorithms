/*
Created by  : Vaisakh Dileep
Date        : 29, November, 2021
Description : Declaration file for undirected_graph_using_adjacency_matrix.
*/

#include<vector>

#ifndef UNDIRECTED_GRAPH_USING_ADJACENCY_MATRIX_HPP
#define UNDIRECTED_GRAPH_USING_ADJACENCY_MATRIX_HPP

namespace undirected_graph_using_adjacency_matrix
{
    struct Undirected_Graph
    {
        std::vector<std::vector<int>*> *A;
    };

    struct Edge
    {
        int vertex_1;

        int vertex_2;
    };

    void display_undirected_graph(Undirected_Graph *u_graph);

    void delete_undirected_graph(Undirected_Graph *u_graph);

    void handle_delete_undirected_graph(Undirected_Graph *u_graph);

    void add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge);

    void handle_add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge);

    void create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges);

    void handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges);
}

namespace UGAM = undirected_graph_using_adjacency_matrix;

#endif