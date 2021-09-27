/*
Created by  : Vaisakh Dileep
Date        : 30, June, 2021
Description : This program creates a weighed directed graph.
*/

// Note: Nodes in the graph are labelled from '0'.

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

struct Weighed_Directed_Graph // Using adjacency list.
{
    Linked_list **A; // array of linked lists.

    int n; // number of rows.
};

int main()
{
    Weighed_Directed_Graph wd_graph {new Linked_list*[5] {}, 5};

    wd_graph.A[0] = new Linked_list {new Node {2, 10, nullptr}};

    wd_graph.A[2] = new Linked_list {new Node {4, 15, nullptr}};

    wd_graph.A[0]->head->next = new Node {7, 45, nullptr};

    return 0;
}