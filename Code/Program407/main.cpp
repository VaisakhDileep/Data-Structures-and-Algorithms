/*
Created by  : Vaisakh Dileep
Date        : 2, September, 2021
Description : This program finds all the forward edges in a DFS tree for a directed graph represented using adjacency list.
*/

// Forward edges are the edges from the ancestor node to the descendent node except tree edges.

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

namespace Start_Time_Finish_Time_DFS_Traversal_Directed_Graph
{
    struct Exploration_Time
    {
        int node {-1};

        int start_time {-1};

        int finish_time {-1};
    };

    void depth_first_search(Directed_Graph *d_graph, int node, int *visited, int &clock, vector<Exploration_Time> *node_exploration_time)
    {
        if((node >= d_graph->n) or (d_graph->A[node] == nullptr)) // This is a leaf node.
        {
            if(visited[node] == 0)
            {
                node_exploration_time->at(node).node = node;

                node_exploration_time->at(node).start_time = clock++;

                visited[node] = 1;

                node_exploration_time->at(node).finish_time = clock++;
            }
        }

        if(visited[node] == 0)
        {
            visited[node] = 1;

            node_exploration_time->at(node).node = node;

            node_exploration_time->at(node).start_time = clock++;

            Node *last {d_graph->A[node]->head};

            while(last != nullptr)
            {
                if(visited[last->vertex] == 0) // If the child is not visited, then propogate.
                {
                    depth_first_search(d_graph, last->vertex, visited, clock, node_exploration_time);
                }

                last = last->next;
            }

            node_exploration_time->at(node).finish_time = clock++;
        }
    }

    vector<Exploration_Time>* find_start_finish_time_directed_graph(Directed_Graph *d_graph)
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

        vector<Exploration_Time> *node_exploration_time {new vector<Exploration_Time>(max_node + 1, Exploration_Time {-1, -1, -1})};

        int *visited = new int[max_node + 1] {0};

        int clock {0};

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
                    depth_first_search(d_graph, i, visited, clock, node_exploration_time);
                }
            }
        }

        return node_exploration_time;
    }

    vector<Exploration_Time>* handle_find_start_finish_time_directed_graph(Directed_Graph *d_graph)
    {
        try
        {
            return find_start_finish_time_directed_graph(d_graph);
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
}

using namespace Start_Time_Finish_Time_DFS_Traversal_Directed_Graph;

void depth_first_search(Directed_Graph *d_graph, int node, int *visited, vector<Exploration_Time> *node_exploration_time, vector<pair<int, int>> *forward_edges)
{
    if((node >= d_graph->n) or (d_graph->A[node] == nullptr)) // This is a leaf node.
    {
        if(visited[node] == 0)
        {
            visited[node] = 1;
        }
    }

    if(visited[node] == 0)
    {
        visited[node] = 1;

        Node *last {d_graph->A[node]->head};

        while(last != nullptr)
        {
            if(visited[last->vertex] == 0) // If the child is not visited, then propogate.
            {
                depth_first_search(d_graph, last->vertex, visited, node_exploration_time, forward_edges);
            }
            else // This edge does not participate in the DFS tree(could be a forward edge, back edge or a cross edge).
            {
                if((node_exploration_time->at(node).start_time < node_exploration_time->at(last->vertex).start_time) and (node_exploration_time->at(node).finish_time > node_exploration_time->at(last->vertex).finish_time))
                {
                    forward_edges->push_back(pair<int, int> {node, last->vertex});
                }
            }

            last = last->next;
        }
    }
}

vector<pair<int, int>>* find_forward_edges_directed_graph(Directed_Graph *d_graph)
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

    vector<pair<int, int>> *forward_edges {new vector<pair<int, int>> {}};

    vector<Exploration_Time> *node_exploration_time {handle_find_start_finish_time_directed_graph(d_graph)};

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
                depth_first_search(d_graph, i, visited, node_exploration_time, forward_edges);
            }
        }
    }

    return forward_edges;
}

vector<pair<int, int>>* handle_find_forward_edges_directed_graph(Directed_Graph *d_graph)
{
    try
    {
        return find_forward_edges_directed_graph(d_graph);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

void display_forward_edges_directed_graph(vector<pair<int, int>> *forward_edges)
{
    if(forward_edges == nullptr)
    {
        return ;
    }

    for(int i {0}; i < forward_edges->size(); i++)
    {
        cout<<"{"<<forward_edges->at(i).first<<", "<<forward_edges->at(i).second<<"} ";
    }
}

int main()
{
    Directed_Graph d_graph {};

    Edge edges[18] {Edge {1, 3}, Edge {1, 6}, Edge {7, 2}, Edge {5, 0}, Edge {0, 1}, Edge {1, 2}, Edge {2, 3}, Edge {3, 7}, Edge {6, 7}, Edge {6, 3}, Edge {2, 6}, Edge {5, 6}, Edge {5, 2}, Edge {1, 5}, Edge {0, 4}, Edge {4, 5}, Edge {4, 1}, Edge {0, 5}};

    handle_create_directed_graph(&d_graph, edges, 18);

    cout<<"d_graph: \n";
    display_directed_graph(&d_graph);
    cout<<"\n";

    vector<pair<int, int>> *forward_edges {handle_find_forward_edges_directed_graph(&d_graph)};

    cout<<"forward_edges(d_graph): ";
    display_forward_edges_directed_graph(forward_edges);
    cout<<"\n";

    return 0;
}