/*
Created by  : Vaisakh Dileep
Date        : 26, July, 2021
Description : This program finds the single source shortest path cost for a weighed directed graph represented using adjacency list(Dijkstra's algorithm).
*/

// This version of single source shortest path cost algorithm will work only for weighed directed graphs that do not contain any negative weights.

#include<iostream>

#include<iomanip>

#include<vector>

#include<queue> // For "priority_queue".

#include<utility> // For "std::pair".

using namespace std;

namespace Weighed_Directed_Graph_Using_Adjacency_List // Weighed Directed Graph is designed using Adjacency List representation.
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

    void display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
    {
        if(wd_graph == nullptr)
        {
            return ;
        }

        for(int i {0}; i < wd_graph->n; i++)
        {
            if(wd_graph->A[i] == nullptr)
            {
                continue;
            }
            else
            {
                cout<<setw(3)<<left<<i;

                Node *last {wd_graph->A[i]->head};

                while(last != nullptr)
                {
                    cout<<" -["<<setw(3)<<last->weight<<"]-> "<<setw(3)<<last->vertex;

                    last = last->next;
                }
                cout<<"\n";
            }
        }
    }

    void add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge edge)
    {
        if(wd_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
        {
            throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
        }

        if(edge.vertex_1 < wd_graph->n)
        {
            if(wd_graph->A[edge.vertex_1] == nullptr)
            {
                wd_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};
            }
            else
            {
                Node *last {wd_graph->A[edge.vertex_1]->head}, *previous_node {};

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
        }
        else
        {
            int new_n {edge.vertex_1 + 1};

            Weighed_Directed_Graph temp {new Linked_list*[new_n] {}, new_n};

            for(int i {0}; i < wd_graph->n; i++)
            {
                temp.A[i] = wd_graph->A[i];
            }

            temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};

            wd_graph->A = temp.A;

            temp.A = nullptr;

            wd_graph->n = temp.n;
        }
    }

    void create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
    {
        if(wd_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        for(int i {0}; i < num_edges; i++)
        {
            try
            {
                add_edge_weighed_directed_graph(wd_graph, w_edges[i]);
            }
            catch(string &ex)
            {
                throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
            }
        }
    }

    void handle_create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
    {
        try
        {
            create_weighed_directed_graph(wd_graph, w_edges, num_edges);
        }
        catch(string &ex)
        {
            cout<<ex;
        }
    }
}

using namespace Weighed_Directed_Graph_Using_Adjacency_List;

class Custom_Compare // Custom compare function for "priority_queue".
{
public:
    bool operator() (pair<int, int> &p_1, pair<int, int> &p_2)
    {
        return (p_1.second > p_2.second); // Priority is higher for vertices with lesser weights.
    }
};

vector<int>* single_source_shortest_path_cost_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, int source) // Dijkstra's algorithm.
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if(source < 0)
    {
        throw string {"ERROR - Invalid source vertex, source vertex cannot be negative ....."};
    }

    int max_node {wd_graph->n - 1};

    for(int i {0}; i < wd_graph->n; i++)
    {
        if(wd_graph->A[i] == nullptr)
        {
            continue;
        }

        Node *last {wd_graph->A[i]->head};

        while(last != nullptr)
        {
            max_node = (last->vertex > max_node) ? last->vertex : max_node;

            last = last->next;
        }
    }

    if(source > max_node)
    {
        throw string {"ERROR - Invalid source vertex, source vertex exceeds the largest vertex in the graph ....."};
    }

    int *visited = new int[max_node + 1] {0};

    vector<int> *distance {new vector<int>(max_node + 1, INT_MAX)}; // "INT_MAX" corresponds to infinity.

    priority_queue<pair<int, int>, vector<pair<int, int>>, Custom_Compare> p_queue {};

    distance->at(source) = 0;

    p_queue.push(make_pair(source, 0));

    while(!p_queue.empty())
    {
        int vertex {p_queue.top().first};

        p_queue.pop();

        visited[vertex] = 1;

        if((vertex >= wd_graph->n) or (wd_graph->A[vertex] == nullptr)) // This is a leaf node
        {
            continue;
        }

        Node *last {wd_graph->A[vertex]->head};

        while(last != nullptr)
        {
            if(last->weight < 0)
            {
                throw string {"ERROR - Invalid operation, negative vertices present in the graph ....."};
            }

            int new_distance {distance->at(vertex) + last->weight};

            if(new_distance < distance->at(last->vertex))
            {
                if(visited[last->vertex] == 1)
                {
                    last = last->next;

                    continue;
                }

                distance->at(last->vertex) = new_distance;

                p_queue.push(make_pair(last->vertex, new_distance));
            }

            last = last->next;
        }
    }

    return distance;
}

vector<int>* handle_single_source_shortest_path_cost_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, int source)
{
    try
    {
        return single_source_shortest_path_cost_weighed_directed_graph(wd_graph, source);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void display_single_source_shortest_path_cost(vector<int> *distance, int source)
{
    if(distance == nullptr)
    {
        return ;
    }

    for(int i {0}; i < distance->size(); i++)
    {
        cout<<source<<" -> "<<i<<" : "<<((distance->at(i) == INT_MAX) ? "Not reachable" : to_string(distance->at(i)))<<"\n";
    }
}

int main()
{
    Weighed_Directed_Graph wd_graph {};

    // Weighed_Edge w_edges[8] {Weighed_Edge {0, 1, 10}, Weighed_Edge {0, 2, 20}, Weighed_Edge {1, 2, 5}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 10}, Weighed_Edge {4, 5, 5}, Weighed_Edge {5, 3, 15}, Weighed_Edge {3, 5, 30}};

    Weighed_Edge w_edges[8] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {2, 3, 15}, Weighed_Edge {3, 1, 5}, Weighed_Edge {3, 4, 5}, Weighed_Edge {4, 5, 5}, Weighed_Edge {0, 5, 100}, Weighed_Edge {0, 4, 25}};

    handle_create_weighed_directed_graph(&wd_graph, w_edges, 8);

    cout<<"wd_graph: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    vector<int> *distance {handle_single_source_shortest_path_cost_weighed_directed_graph(&wd_graph, 0)};

    display_single_source_shortest_path_cost(distance, 0);

    return 0;
}