/*
Created by  : Vaisakh Dileep
Date        : 30, June, 2021
Description : This program removes an edge from a weighed directed graph.
*/

#include<iostream>

#include<iomanip>

using namespace std;

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

void remove_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge edge)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if(edge.vertex_1 >= wd_graph->n)
    {
        throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
    }

    if(wd_graph->A[edge.vertex_1] == nullptr)
    {
        throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
    }
    else
    {
        Node *last {wd_graph->A[edge.vertex_1]->head}, *previous_node {};

        while(last != nullptr)
        {
            if(last->vertex == edge.vertex_2)
            {
                break;
            }

            previous_node = last;

            last = last->next;
        }

        if(previous_node == nullptr)
        {
            wd_graph->A[edge.vertex_1]->head = last->next;

            delete last;

            if(wd_graph->A[edge.vertex_1]->head == nullptr)
            {
                delete wd_graph->A[edge.vertex_1];

                wd_graph->A[edge.vertex_1] = nullptr;
            }
        }
        else if(last == nullptr)
        {
            throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
        }
        else
        {
            previous_node->next = last->next;

            delete last;
        }
    }
}

void handle_remove_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge edge)
{
    try
    {
        remove_edge_weighed_directed_graph(wd_graph, edge);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Weighed_Directed_Graph wd_graph {new Linked_list*[3] {}, 3};

    wd_graph.A[0] = new Linked_list {new Node {2, 10, nullptr}};

    wd_graph.A[2] = new Linked_list {new Node {4, 15, nullptr}};

    wd_graph.A[0]->head->next = new Node {7, 45, nullptr};

    cout<<"wd_graph: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 2, 0}); // It is not necessary to provide the weight of the edge.

    cout<<"wd_graph [after removing {0, 2}]: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 7, 0});

    cout<<"wd_graph [after removing {0, 7}]: \n";
    display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 2, 0});
    cout<<"\n";

    handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {-1, 2, 0});
    cout<<"\n";

    return 0;
}