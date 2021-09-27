/*
Created by  : Vaisakh Dileep
Date        : 27, June, 2021
Description : This program creates a directed graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<iostream>

using namespace std;

struct Node
{
    int vertex;

    Node *next;
};

struct Linked_list
{
    Node *head;
};

struct Directed_Graph // Using adjacency list.
{
    Linked_list **A; // array of linked lists.

    int n; // number of rows.
};

int main()
{
    Directed_Graph d_graph {new Linked_list*[5] {}, 5};

    d_graph.A[0] = new Linked_list {new Node {2, nullptr}};
    
    d_graph.A[2] = new Linked_list {new Node {5, nullptr}};

    d_graph.A[0]->head->next = new Node {7, nullptr};

    return 0;
}