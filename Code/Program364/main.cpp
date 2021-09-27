/*
Created by  : Vaisakh Dileep
Date        : 31, July, 2021
Description : This program finds the single source shortest path for a weighed directed graph represented using adjacency list(Bellman-Ford's algorithm).
*/

#include<iostream>

#include<iomanip>

#include<vector>

#include<unordered_set>

#include<list>

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

namespace Bellman_Ford_Single_Source_Shortest_Path_For_Weighed_Directed_Graph
{
    int *non_reachable {new int {0}}; // Behaves like a flag.

    int *negative_cycle {new int {0}}; // Behaves like a flag.

    vector<int*>* single_source_shortest_path_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, int source) // Bellman-Ford's algorithm.
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

        unordered_set<int> vertices {};

        for(int i {0}; i < wd_graph->n; i++)
        {
            if(wd_graph->A[i] == nullptr)
            {
                continue;
            }

            vertices.insert(i);

            Node *last {wd_graph->A[i]->head};

            while(last != nullptr)
            {
                max_node = (last->vertex > max_node) ? last->vertex : max_node;

                vertices.insert(last->vertex);

                last = last->next;
            }
        }

        if(source > max_node)
        {
            throw string {"ERROR - Invalid source vertex, source vertex exceeds the largest vertex in the graph ....."};
        }

        vector<int *> *previous_node {new vector<int*>(max_node + 1, non_reachable)};

        vector<int> *distance {new vector<int>(max_node + 1, INT_MAX)}; // "INT_MAX" corresponds to infinity.

        distance->at(source) = 0;

        for(unsigned long long i {0}; i < (vertices.size() - 1); i++) // In order to propogate minimum distance.
        {
            for(int j {0}; j < wd_graph->n; j++)
            {
                if(wd_graph->A[j] == nullptr)
                {
                    continue;
                }

                if(distance->at(j) == INT_MAX)
                {
                    continue;
                }

                Node *last {wd_graph->A[j]->head};

                while(last != nullptr)
                {
                    int new_distance {distance->at(j) + last->weight};

                    if(new_distance < distance->at(last->vertex))
                    {
                        previous_node->at(last->vertex) = new int {j};

                        distance->at(last->vertex) = new_distance;
                    }

                    last = last->next;
                }
            }
        }

        for(unsigned long long i {0}; i < (vertices.size() - 1); i++) // In order to propogate "-infinity" for vertices that participate in a negative cycle or reachable from a negative cycle.
        {
            for(int j {0}; j < wd_graph->n; j++)
            {
                if(wd_graph->A[j] == nullptr)
                {
                    continue;
                }

                if(distance->at(j) == INT_MAX) // Vertices that are not reachable from the source vertex.
                {
                    continue;
                }

                if(distance->at(j) == INT_MIN)
                {
                    Node *last {wd_graph->A[j]->head};

                    while(last != nullptr)
                    {
                        previous_node->at(last->vertex) = negative_cycle;

                        distance->at(last->vertex) = INT_MIN;

                        last = last->next;
                    }
                }

                Node *last {wd_graph->A[j]->head};

                while(last != nullptr)
                {
                    int new_distance {distance->at(j) + last->weight};

                    if(new_distance < distance->at(last->vertex))
                    {
                        previous_node->at(last->vertex) = negative_cycle;

                        distance->at(last->vertex) = INT_MIN;
                    }

                    last = last->next;
                }
            }
        }

        return previous_node;
    }

    void display_single_source_shortest_path(vector<int*> *previous_node, int source)
    {
        if(previous_node == nullptr)
        {
            return ;
        }

        for(int i {0}; i < previous_node->size(); i++)
        {
            if(i == source)
            {
                if(previous_node->at(i) == non_reachable)
                {
                    cout<<source<<" -> "<<i<<" : "<<i<<"\n";
                }
                else
                {
                    cout<<source<<" -> "<<i<<" : "<<"Negative cycle present in the path\n";
                }
            }
            else if(previous_node->at(i) == non_reachable)
            {
                cout<<source<<" -> "<<i<<" : "<<"Not reachable\n";
            }
            else if(previous_node->at(i) == negative_cycle)
            {
                cout<<source<<" -> "<<i<<" : "<<"Negative cycle present in the path\n";
            }
            else
            {
                list<int> path {};

                path.push_back(i);

                int *last_vertex {previous_node->at(i)};

                while(last_vertex != non_reachable)
                {
                    path.push_front(*last_vertex);

                    last_vertex = previous_node->at(*last_vertex);
                }

                cout<<source<<" -> "<<i<<" : ";

                for(auto itr {path.begin()}; itr != path.end(); itr++)
                {
                    cout<<(*itr)<<" ";
                }
                cout<<"\n";
            }
        }
    }

    vector<int*>* handle_single_source_shortest_path_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, int source)
    {
        try
        {
            return single_source_shortest_path_weighed_directed_graph(wd_graph, source);
        }
        catch(string &ex)
        {
            cout<<ex;
        }
    }
}

using namespace Bellman_Ford_Single_Source_Shortest_Path_For_Weighed_Directed_Graph;

int main()
{
    Weighed_Directed_Graph wd_graph {};

    Weighed_Edge w_edges[7] {Weighed_Edge {0, 1, 1}, Weighed_Edge {1, 2, 2}, Weighed_Edge {2, 3, 3}, Weighed_Edge {3, 1, -6}, Weighed_Edge {2, 4, 4}, Weighed_Edge {4, 5, 5}, Weighed_Edge {5, 4, -1}}; // This test case contains a negative cycle.

    // Weighed_Edge w_edges[7] {Weighed_Edge {0, 1, 1}, Weighed_Edge {1, 2, 2}, Weighed_Edge {2, 3, 3}, Weighed_Edge {3, 1, 6}, Weighed_Edge {2, 4, 4}, Weighed_Edge {4, 5, 5}, Weighed_Edge {5, 4, -1}}; // This test case does not contains a negative cycle.

    // Weighed_Edge w_edges[7] {Weighed_Edge {0, 1, 1}, Weighed_Edge {1, 2, 2}, Weighed_Edge {3, 4, 1}, Weighed_Edge {4, 5, 2}, Weighed_Edge {5, 3, -4}, Weighed_Edge {5, 6, 5}, Weighed_Edge {6, 5, 6}}; // This test case is a disconnected graph that containsa a negative cycle.

    // Weighed_Edge w_edges[7] {Weighed_Edge {0, 1, 1}, Weighed_Edge {1, 2, 2}, Weighed_Edge {3, 4, 1}, Weighed_Edge {4, 5, 2}, Weighed_Edge {5, 3, 4}, Weighed_Edge {5, 6, 5}, Weighed_Edge {6, 5, 6}}; // This test case is a disconnected graph that does not containsa a negative cycle.

    handle_create_weighed_directed_graph(&wd_graph, w_edges, 7);

    cout<<"wd_graph: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    vector<int*> *path {handle_single_source_shortest_path_weighed_directed_graph(&wd_graph, 1)};

    display_single_source_shortest_path(path, 1);

    return 0;
}