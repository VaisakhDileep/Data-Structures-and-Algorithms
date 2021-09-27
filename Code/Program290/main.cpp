/*
Created by  : Vaisakh Dileep
Date        : 30, June, 2021
Description : This program deletes a weighed directed graph.
*/

#include<iostream>

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

void delete_linked_list(Linked_list *L)
{
    Node *last {L->head};

    while(last != nullptr)
    {
        Node *temp {last->next};

        delete last;

        last = temp;
    }

    L->head = nullptr;
}

void delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    if(wd_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    for(int i {0}; i < wd_graph->n; i++)
    {
        if(wd_graph->A[i] != nullptr)
        {
            delete_linked_list(wd_graph->A[i]);

            wd_graph->A[i] = nullptr;
        }
    }

    delete[] wd_graph->A;
}

void handle_delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
    try
    {
        delete_weighed_directed_graph(wd_graph);
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

    handle_delete_weighed_directed_graph(&wd_graph);

    return 0; 
}