/*
Created by  : Vaisakh Dileep
Date        : 25, July, 2021
Description : This program detects whether there is a cycle in a weighed directed graph represented using adjacency list(depth first search).
*/

#include<iostream>

#include<iomanip>

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

bool depth_first_search(Weighed_Directed_Graph *wd_graph, int node, int *visited, int *recursive_call_stack_state) // Some changes were made compared to the traditional DFS algorithm.
{
    if(wd_graph->A[node] == nullptr) // This is a leaf node. We already checked for "node >= d_graph->n" in the while loop.
    {
        return false;
    }

    if(visited[node] == 0)
    {
        visited[node] = 1;

        recursive_call_stack_state[node] = 1;

        Node *last {wd_graph->A[node]->head};

        while(last != nullptr)
        {
            if(last->vertex >= wd_graph->n) // This is a leaf node.
            {
                last = last->next;

                continue;
            }

            if(visited[last->vertex] == 0) // If the child node is not visited, then propogate.
            {
                if(depth_first_search(wd_graph, last->vertex, visited, recursive_call_stack_state) == true)
                {
                    return true;
                }
            }
            else if(recursive_call_stack_state[last->vertex] == 1) // If the child node is visited and it's already in the recursive call stack.
            {
                return true;
            }

            last = last->next;
        }
    }

    recursive_call_stack_state[node] = 0; // Reset the node state.

    return false;
}

bool detect_cycle_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    int *visited = new int[wd_graph->n] {0}; // "visited" array does not contain any leaf node.

    int *recursive_call_stack_state = new int[wd_graph->n] {0}; // Checks if the node is visited in the recursive call stack. As we pop the function call stack, it is resetted. "recursive_call_stack_state" array does not contain any leaf nodes.

    for(int i {0}; i < wd_graph->n; i++) // In case if the graph is disconnected.
    {
        if(wd_graph->A[i] == nullptr)
        {
            continue;
        }
        else
        {
            if(visited[i] == 0)
            {
                if(depth_first_search(wd_graph, i, visited, recursive_call_stack_state) == true)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool handle_detect_cycle_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    try
    {
        return detect_cycle_weighed_directed_graph(wd_graph);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Weighed_Directed_Graph wd_graph {};

    // Weighed_Edge w_edges[5] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {2, 3, 30}, Weighed_Edge {3, 1, 40}, Weighed_Edge {3, 4, 50}}; // This test case contains a cycle.

    // Weighed_Edge w_edges[5] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {2, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {3, 5, 50}}; // This test case does not contain cycle.

    Weighed_Edge w_edges[6] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {3, 5, 50}, Weighed_Edge {1, 5, 60}}; // This test case does not contain cycle.

    // Weighed_Edge w_edges[5] {Weighed_Edge {0, 1, 10}, Weighed_Edge {2, 3, 20}, Weighed_Edge {3, 4, 30}, Weighed_Edge {4, 3, 40}, Weighed_Edge {4, 5, 50}}; // This test case is a disconnected graph that contains a cycle.

    // Weighed_Edge w_edges[5] {Weighed_Edge {0, 1, 10}, Weighed_Edge {2, 3, 20}, Weighed_Edge {3, 4, 30}, Weighed_Edge {4, 5, 40}, Weighed_Edge {4, 6, 50}}; // This test case is a disconnected graph that does not contain any cycle.

    handle_create_weighed_directed_graph(&wd_graph, w_edges, 6);

    cout<<"wd_graph: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    cout<<"detect_cycle_weighed_directed_graph(wd_graph): "<<handle_detect_cycle_weighed_directed_graph(&wd_graph)<<"\n";

    return 0;
}