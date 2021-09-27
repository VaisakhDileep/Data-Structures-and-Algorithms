/*
Created by  : Vaisakh Dileep
Date        : 9, July, 2021
Description : This program demonstrates depth first search for a weighed undirected graph represented using adjacency list.
*/

#include<iostream>

#include<iomanip>

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

void depth_first_search(Weighed_Undirected_Graph *wu_graph, int node, int *visited)
{
    if(visited[node] == 0)
    {
        cout<<node<<" ";

        visited[node] = 1;

        Node *last {wu_graph->A[node]->head};

        while(last != nullptr)
        {
            if(visited[last->vertex] == 0) // Not necessary to include "visited[last->vertex] == 0", but saves recursive calls.
            {
                depth_first_search(wu_graph, last->vertex, visited);
            }

            last = last->next;
        }
    }
}

void handle_depth_first_search(Weighed_Undirected_Graph *wu_graph, int root = 0)
{
    if(wu_graph == nullptr)
    {
        cout<<"ERROR - Invalid operation, graph is not valid .....";

        return ;
    }

    if(root < 0)
    {
        cout<<"ERROR - Invalid root vertex, vertex cannot be negative .....";

        return ;
    }

    depth_first_search(wu_graph, root, new int[wu_graph->n] {0});
}

int main()
{
    Weighed_Undirected_Graph wu_graph {};

    Weighed_Edge w_edges[9] {Weighed_Edge {0, 1, 10}, Weighed_Edge {0, 2, 20}, Weighed_Edge {0, 3, 30}, Weighed_Edge {1, 2, 40}, Weighed_Edge {3, 4, 50}, Weighed_Edge {2, 4, 60}, Weighed_Edge {4, 5, 70}, Weighed_Edge {4, 6, 80}, Weighed_Edge {3, 2, 90}};

    handle_create_weighed_undirected_graph(&wu_graph, w_edges, 9);

    cout<<"wu_graph: \n";
    display_weighed_undirected_graph(&wu_graph);
    cout<<"\n";

    cout<<"DFS(wu_graph): ";
    handle_depth_first_search(&wu_graph);
    cout<<"\n";

    handle_depth_first_search(&wu_graph, -1);
    cout<<"\n";

    return 0;
}