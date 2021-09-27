/*
Created by  : Vaisakh Dileep
Date        : 1, September, 2021
Description : This program finds all the tree edges in a DFS tree for a directed graph represented using adjacency list.
*/

// Tree edges are the edges that participate in the DFS traversal.

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

namespace Directed_Graph_Using_Adjacency_List // Directed Graph is designed using Adjacency List representation.
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

    void display_directed_graph(Directed_Graph *d_graph)
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

    void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
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

    void create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
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

    void handle_create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
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
}

using namespace Directed_Graph_Using_Adjacency_List;

void depth_first_search(Directed_Graph *d_graph, int node, int *visited, vector<pair<int, int>> *tree_edges)
{
    if((node >= d_graph->n) or (d_graph->A[node] == nullptr)) // This is a leaf node, leaf nodes do not have any outgoing edges.
    {
        visited[node] = 1;

        return ;
    }

    if(visited[node] == 0)
    {
        visited[node] = 1;

        Node *last {d_graph->A[node]->head};

        while(last != nullptr)
        {
            if(visited[last->vertex] == 0) // If the child node is not visited, then propogate.
            {
                tree_edges->push_back(pair<int, int> {node, last->vertex});

                depth_first_search(d_graph, last->vertex, visited, tree_edges);
            }

            last = last->next;
        }
    }
}

vector<pair<int, int>>* find_tree_edges_directed_graph(Directed_Graph *d_graph)
{
    if(d_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if(d_graph->n == 0)
    {
        throw string {"ERROR - Invalid operation, graph is empty ....."};
    }

    int max_node {d_graph->n - 1};

    for(int i {0}; i < d_graph->n; i++)
    {
        if(d_graph->A[i] == nullptr)
        {
            continue;
        }

        Node *last {d_graph->A[i]->head};

        while(last != nullptr)
        {
            max_node = (last->vertex > max_node) ? last->vertex : max_node;

            last = last->next;
        }
    }

    vector<pair<int, int>> *tree_edges {new vector<pair<int, int>> {}};

    int *visited = new int[max_node + 1] {0};

    for(int i {0}; i < d_graph->n; i++) // In case if the graph is disconnected.
    {
        if(d_graph->A[i] == nullptr)
        {
            continue;
        }
        else
        {
            if(visited[i] == 0)
            {
                depth_first_search(d_graph, i, visited, tree_edges);
            }
        }
    }

    return tree_edges;
}

vector<pair<int, int>>* handle_find_tree_edges_directed_graph(Directed_Graph *d_graph)
{
    try
    {
        return find_tree_edges_directed_graph(d_graph);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

void display_tree_edges_directed_graph(vector<pair<int, int>> *tree_edges)
{
    if(tree_edges == nullptr)
    {
        return ;
    }

    for(int i {0}; i < tree_edges->size(); i++)
    {
        cout<<"{"<<tree_edges->at(i).first<<", "<<tree_edges->at(i).second<<"} ";
    }
}

int main()
{
    Directed_Graph d_graph {};

    Edge edges[14] {Edge {0, 1}, Edge {1, 2}, Edge {2, 3}, Edge {3, 7}, Edge {6, 7}, Edge {6, 3}, Edge {2, 6}, Edge {5, 6}, Edge {5, 2}, Edge {1, 5}, Edge {0, 4}, Edge {4, 5}, Edge {4, 1}, Edge {0, 5}};

    // Edge edges[6] {Edge {0, 1}, Edge {0, 2}, Edge {2, 1}, Edge {0, 5}, Edge {0, 3}, Edge {3, 4}};

    handle_create_directed_graph(&d_graph, edges, 14);

    cout<<"d_graph: \n";
    display_directed_graph(&d_graph);
    cout<<"\n";

    vector<pair<int, int>> *tree_edges {handle_find_tree_edges_directed_graph(&d_graph)};

    cout<<"tree_edges(d_graph): ";
    display_tree_edges_directed_graph(tree_edges);
    cout<<"\n";

    return 0;
}