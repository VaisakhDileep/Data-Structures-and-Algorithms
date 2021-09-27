/*
Created by  : Vaisakh Dileep
Date        : 2, September, 2021
Description : This program finds the start and finish time of the vertices in DFS traversal for an undirected graph represented using adjacency list.
*/

// Start time: The time at which the vertex was first explored in the DFS traversal.

// Finish time: The time at which we completely explored the vertex in the DFS traversal.

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

namespace Undirected_Graph_Using_Adjacency_List // Undirected Graph is designed using Adjacency List representation.
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

    void display_undirected_graph(Undirected_Graph *u_graph)
    {
        if(u_graph == nullptr)
        {
            return ;
        }

        for(int i {0}; i < u_graph->n; i++)
        {
            if(u_graph->A[i] == nullptr)
            {
                continue;
            }
            else
            {
                cout<<setw(3)<<left<<i;

                Node *last {u_graph->A[i]->head};

                while(last != nullptr)
                {
                    cout<<" -> "<<setw(3)<<last->vertex;

                    last = last->next;
                }
                cout<<"\n";
            }
        }
    }

    void add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
    {
        if(u_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
        {
            throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
        }

        if((edge.vertex_1 < u_graph->n) and (edge.vertex_2 < u_graph->n))
        {
            if(u_graph->A[edge.vertex_1] == nullptr)
            {
                u_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
            }
            else
            {
                Node *last {u_graph->A[edge.vertex_1]->head}, *previous_node {};

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

            if(edge.vertex_1 == edge.vertex_2)
            {
                return ;
            }

            if(u_graph->A[edge.vertex_2] == nullptr)
            {
                u_graph->A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, nullptr}};
            }
            else
            {
                Node *last {u_graph->A[edge.vertex_2]->head}, *previous_node {};

                while(last != nullptr)
                {
                    previous_node = last;

                    if(last->vertex == edge.vertex_1)
                    {
                        throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
                    }

                    last = last->next;
                }

                previous_node->next = new Node {edge.vertex_1, nullptr};
            }
        }
        else
        {
            int new_n {edge.vertex_1 > edge.vertex_2 ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

            Undirected_Graph temp {new Linked_list*[new_n] {}, new_n};

            for(int i {0}; i < u_graph->n; i++)
            {
                temp.A[i] = u_graph->A[i];
            }

            if(temp.A[edge.vertex_1] == nullptr)
            {
                temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
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

                previous_node->next = new Node {edge.vertex_2, nullptr};
            }

            if(edge.vertex_1 == edge.vertex_2)
            {
                u_graph->A = temp.A;

                temp.A = nullptr;

                u_graph->n = temp.n;

                return ;
            }

            if(temp.A[edge.vertex_2] == nullptr)
            {
                temp.A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, nullptr}};
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

                previous_node->next = new Node {edge.vertex_1, nullptr};
            }

            u_graph->A = temp.A;

            temp.A = nullptr;

            u_graph->n = temp.n;
        }
    }

    void create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
    {
        if(u_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        for(int i {0}; i < num_edges; i++)
        {
            try
            {
                add_edge_undirected_graph(u_graph, edges[i]);
            }
            catch(string &ex)
            {
                throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
            }
        }
    }

    void handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
    {
        try
        {
            create_undirected_graph(u_graph, edges, num_edges);
        }
        catch(string &ex)
        {
            cout<<ex;
        }
    }
}

using namespace Undirected_Graph_Using_Adjacency_List;

struct Exploration_Time
{
    int node {-1};

    int start_time {-1};

    int finish_time {-1};
};

void depth_first_search(Undirected_Graph *u_graph, int node, int *visited, int &clock, vector<Exploration_Time> *node_exploration_time)
{
    if(visited[node] == 0)
    {
        node_exploration_time->at(node).node = node;

        node_exploration_time->at(node).start_time = clock++;

        visited[node] = 1;

        Node *last {u_graph->A[node]->head};

        while(last != nullptr)
        {
            if(visited[last->vertex] == 0) // If the child node is not visited, then propogate.
            {
                depth_first_search(u_graph, last->vertex, visited, clock, node_exploration_time);
            }

            last = last->next;
        }

        node_exploration_time->at(node).finish_time = clock++;
    }
}

vector<Exploration_Time>* find_start_finish_time_undirected_graph(Undirected_Graph *u_graph)
{
    if(u_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if(u_graph->n == 0)
    {
        throw string {"ERROR - Invalid operation, graph is empty ....."};
    }

    int clock {0};

    int *visited = new int[u_graph->n + 1] {0};

    vector<Exploration_Time> *node_exploration_time {new vector<Exploration_Time>(u_graph->n, Exploration_Time {-1, -1, -1})};

    for(int i {0}; i < u_graph->n; i++) // In case if the graph is disconnected.
    {
        if(u_graph->A[i] == nullptr)
        {
            continue;
        }
        else
        {
            if(visited[i] == 0)
            {
                depth_first_search(u_graph, i , visited, clock, node_exploration_time);
            }
        }
    }

    return node_exploration_time;
}

vector<Exploration_Time>* handle_find_start_finish_time_undirected_graph(Undirected_Graph *u_graph)
{
    try
    {
        return find_start_finish_time_undirected_graph(u_graph);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void display_exploration_time(vector<Exploration_Time> *node_exploration_time)
{
    if(node_exploration_time == nullptr)
    {
        return ;
    }

    cout<<"node    start    finish\n";

    for(int i {0}; i < node_exploration_time->size(); i++)
    {
        if(node_exploration_time->at(i).node == -1)
        {
            continue;
        }

        cout<<setw(8)<<left<<node_exploration_time->at(i).node;
        cout<<setw(9)<<left<<node_exploration_time->at(i).start_time;
        cout<<left<<node_exploration_time->at(i).finish_time<<"\n";
    }
}

int main()
{
    Undirected_Graph u_graph {};

    // Edge edges[14] {Edge {0, 1}, Edge {1, 2}, Edge {2, 3}, Edge {3, 7}, Edge {6, 7}, Edge {6, 3}, Edge {2, 6}, Edge {5, 6}, Edge {5, 2}, Edge {1, 5}, Edge {0, 4}, Edge {4, 5}, Edge {4, 1}, Edge {0, 5}};

    Edge edges[6] {Edge {0, 1}, Edge {0, 2}, Edge {2, 1}, Edge {0, 5}, Edge {0, 3}, Edge {3, 4}};

    handle_create_undirected_graph(&u_graph, edges, 6);

    cout<<"u_graph: ";
    display_undirected_graph(&u_graph);
    cout<<"\n";

    vector<Exploration_Time> *node_exploration_time {handle_find_start_finish_time_undirected_graph(&u_graph)};

    display_exploration_time(node_exploration_time);
    cout<<"\n";

    return 0;
}