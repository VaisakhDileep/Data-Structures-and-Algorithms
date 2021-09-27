/*
Created by  : Vaisakh Dileep
Date        : 13, September, 2021
Description : This program finds all the strongly connected components in a directed graph represented using adjacency list(Tarjan's algorithm).
*/

#include<iostream>

#include<iomanip>

#include<vector>

#include<stack>

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

namespace Tarjans_Algorithm_For_Strongly_Connected_Components_Directed_Graph
{
    vector<int> *discover_time {}; // A unique "discover_time" is given to each node(nodes that arrive early have lesser "discover_time").

    vector<int> *low_link {}; // "low_link" of a node is the least "discover_time" of any node reachable from the node.

    vector<bool> *visited {};

    vector<vector<int>*> *strongly_connected_components {};

    vector<bool> *on_stack {}; // Checks if the node is present in the stack.

    stack<int> stk {};

    int clock {0};

    void depth_first_search(Directed_Graph *d_graph, int node)
    {
        if(visited->at(node) == false)
        {
            visited->at(node) = true;

            stk.push(node);

            on_stack->at(node) = true;

            clock++;

            low_link->at(node) = discover_time->at(node) = clock;

            Node *last {d_graph->A[node]->head};

            while(last != nullptr)
            {
                if(visited->at(last->vertex) == false)
                {
                    depth_first_search(d_graph, last->vertex);
                }

                if(on_stack->at(last->vertex) == true) // Only update "low_link", if it is present in the stack.
                {
                    low_link->at(node) = min(low_link->at(last->vertex), low_link->at(node));
                }

                last = last->next;
            }

            if(discover_time->at(node) == low_link->at(node)) // Start of the strongly connected component.
            {
                vector<int> *strongly_connected_component {new vector<int> {}};

                while(stk.top() != node)
                {
                    on_stack->at(stk.top()) = false;

                    strongly_connected_component->push_back(stk.top());

                    stk.pop();
                }

                on_stack->at(stk.top()) = false;

                strongly_connected_component->push_back(stk.top());

                stk.pop();

                strongly_connected_components->push_back(strongly_connected_component);
            }
        }
    }

    vector<vector<int>*>* find_strongly_connected_components_directed_graph(Directed_Graph *d_graph)
    {
        if(d_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
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

        clock = 0;

        discover_time = new vector<int>(max_node + 1, 0);

        low_link = new vector<int>(max_node + 1, 0);

        visited = new vector<bool>(max_node + 1, false);

        strongly_connected_components = new vector<vector<int>*> {};

        on_stack = new vector<bool>(max_node + 1, false);

        stk = stack<int> {};

        for(int i {0}; i <= max_node; i++)
        {
            if((i >= d_graph->n) or (d_graph->A[i] == nullptr)) // Leaf node or an unassigned node.
            {
                continue;
            }

            if(visited->at(i) == false)
            {
                depth_first_search(d_graph, i);
            }
        }

        return strongly_connected_components;
    }

    vector<vector<int>*>* handle_find_strongly_connected_components_directed_graph(Directed_Graph *d_graph)
    {
        try
        {
            return find_strongly_connected_components_directed_graph(d_graph);
        }
        catch(string &ex)
        {
            cout<<ex;
        }
    }

    void display_strongly_connected_components(vector<vector<int>*> *strongly_connected_components)
    {
        if((strongly_connected_components == nullptr) or (strongly_connected_components->size() == 0))
        {
            return ;
        }

        for(int i {0}; i < strongly_connected_components->size(); i++)
        {
            for(int j {0}; j < strongly_connected_components->at(i)->size(); j++)
            {
                cout<<strongly_connected_components->at(i)->at(j)<<" ";
            }
            cout<<"\n";
        }
    }
}

using namespace Tarjans_Algorithm_For_Strongly_Connected_Components_Directed_Graph;

int main()
{
    Directed_Graph d_graph {};

    Edge edges[13] {Edge {0, 1}, Edge {0, 4}, Edge {4, 0}, Edge {4, 3}, Edge {1, 5}, Edge {5, 2}, Edge {5, 6}, Edge {2, 1}, Edge {2, 6}, Edge {3, 6}, Edge {6, 7}, Edge {7, 3}, Edge {2, 3}};

    handle_create_directed_graph(&d_graph, edges, 13);

    cout<<"d_graph: \n";
    display_directed_graph(&d_graph);
    cout<<"\n";

    vector<vector<int>*>* strongly_connected_components {handle_find_strongly_connected_components_directed_graph(&d_graph)};

    cout<<"strongly_connected_components(d_graph): \n";

    display_strongly_connected_components(strongly_connected_components);

    return 0;
}