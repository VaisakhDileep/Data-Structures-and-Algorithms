/*
Created by  : Vaisakh Dileep
Date        : 16, September, 2021
Description : This program finds the minimum spanning tree of a weighed undirected graph represented using adjacency list.(Prim's algorithm)
*/

// Prim's algorithm will only work for disconnected graphs. Negative weights are allowed.

#include<iostream>

#include<iomanip>

#include<vector>

#include<queue>

using namespace std;

namespace Weighed_Undirected_Graph_Using_Adjacency_List // Weighed Undirected Graph is designed using Adjacency List representation.
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

    void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
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

    void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge edge)
    {
        if(wu_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
        {
            throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
        }

        if((edge.vertex_1 < wu_graph->n) and (edge.vertex_2 < wu_graph->n))
        {
            if(wu_graph->A[edge.vertex_1] == nullptr)
            {
                wu_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};
            }
            else
            {
                Node *last {wu_graph->A[edge.vertex_1]->head}, *previous_node {};

                while(last != nullptr)
                {
                    previous_node = last;

                    if(last->vertex == edge.vertex_2)
                    {
                        throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                    }

                    last = last->next;
                }

                previous_node->next = new Node {edge.vertex_2, edge.weight, nullptr};
            }

            if(edge.vertex_1 == edge.vertex_2)
            {
                return ;
            }

            if(wu_graph->A[edge.vertex_2] == nullptr)
            {
                wu_graph->A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, edge.weight, nullptr}};
            }
            else
            {
                Node *last {wu_graph->A[edge.vertex_2]->head}, *previous_node {};

                while(last != nullptr)
                {
                    previous_node = last;

                    if(last->vertex == edge.vertex_1)
                    {
                        throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                    }

                    last = last->next;
                }

                previous_node->next = new Node {edge.vertex_1, edge.weight, nullptr};
            }
        }
        else
        {
            int new_n {edge.vertex_1 > edge.vertex_2 ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

            Weighed_Undirected_Graph temp {new Linked_list*[new_n] {}, new_n};

            for(int i {0}; i < wu_graph->n; i++)
            {
                temp.A[i] = wu_graph->A[i];
            }

            if(temp.A[edge.vertex_1] == nullptr)
            {
                temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};
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

                previous_node->next = new Node {edge.vertex_2, edge.weight, nullptr};
            }

            if(edge.vertex_1 == edge.vertex_2)
            {
                wu_graph->A = temp.A;

                temp.A = nullptr;

                wu_graph->n = temp.n;

                return ;
            }

            if(temp.A[edge.vertex_2] == nullptr)
            {
                temp.A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, edge.weight, nullptr}};
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

                previous_node->next = new Node {edge.vertex_1, edge.weight, nullptr};
            }

            wu_graph->A = temp.A;

            temp.A = nullptr;

            wu_graph->n = temp.n;
        }
    }

    void create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
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

    void handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
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
}

using namespace Weighed_Undirected_Graph_Using_Adjacency_List;

class Custom_Compare // Custom compare functor for "priority_queue".
{
public:
    bool operator() (pair<int, int> &p_1, pair<int, int> &p_2)
    {
        return (p_1.second > p_2.second); // Priority is higher for vertices with lesser weights.
    }
};

Weighed_Undirected_Graph* construct_minimum_spanning_tree_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph) // Prim's algorithm for Minimum Spanning Tree.
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    int source {};

    for(int i {0}; i < wu_graph->n; i++) // Choosing a random "source_node".
    {
        if(wu_graph->A[i] == nullptr)
        {
            continue;
        }
        else
        {
            source = i;

            break;
        }
    }

    int *visited = new int[wu_graph->n] {0};

    vector<pair<int, int>> *previous_node {new vector<pair<int, int>>(wu_graph->n, make_pair(-1, -1))};

    vector<int> *distance {new vector<int>(wu_graph->n, INT_MAX)}; // "INT_MAX" corresponds to infinity.

    priority_queue<pair<int, int>, vector<pair<int, int>>, Custom_Compare> p_queue {};

    distance->at(source) = 0;

    p_queue.push(make_pair(source, 0));

    while(!p_queue.empty())
    {
        int vertex {p_queue.top().first};

        p_queue.pop();

        visited[vertex] = 1;

        if(wu_graph->A[vertex] == nullptr) // This is a leaf node.
        {
            continue;
        }

        Node *last {wu_graph->A[vertex]->head};

        while(last != nullptr)
        {
            if(last->weight < distance->at(last->vertex))
            {
                if(visited[last->vertex])
                {
                    last = last->next;

                    continue;
                }

                previous_node->at(last->vertex) = make_pair(vertex, last->weight);

                distance->at(last->vertex) = last->weight;

                p_queue.push(make_pair(last->vertex,last->weight));
            }

            last = last->next;
        }
    }

    Weighed_Undirected_Graph *minimum_spanning_tree {new Weighed_Undirected_Graph {}};

    for(int i {0}; i < previous_node->size(); i++)
    {
        if(previous_node->at(i).first != -1)
        {
            add_edge_weighed_undirected_graph(minimum_spanning_tree, Weighed_Edge {i, previous_node->at(i).first, previous_node->at(i).second});
        }
    }

    return minimum_spanning_tree;
}

Weighed_Undirected_Graph* handle_construct_minimum_spanning_tree_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    try
    {
        return construct_minimum_spanning_tree_weighed_undirected_graph(wu_graph);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

int main()
{
    Weighed_Undirected_Graph wu_graph {};

    Weighed_Edge w_edges[6] {Weighed_Edge {0, 1, -2}, Weighed_Edge {1, 2, -5}, Weighed_Edge {0, 2, -3}, Weighed_Edge {2, 4, 13}, Weighed_Edge {2, 3, 10}, Weighed_Edge {3, 4, 2}};

    handle_create_weighed_undirected_graph(&wu_graph, w_edges, 6);

    cout<<"wu_graph: \n";
    display_weighed_undirected_graph(&wu_graph);
    cout<<"\n";

    Weighed_Undirected_Graph *minimum_spanning_tree {handle_construct_minimum_spanning_tree_weighed_undirected_graph(&wu_graph)};

    cout<<"minimum_spanning_tree: \n";
    display_weighed_undirected_graph(minimum_spanning_tree);
    cout<<"\n";

    return 0;
}