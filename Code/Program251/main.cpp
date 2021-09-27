/*
Created by  : Vaisakh Dileep
Date        : 20, June, 2021
Description : This program creates an undirected graph.
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

struct Undirected_Graph // Using adjacency list.
{
    Linked_list **A; // array of linked lists.

    int n; // number of rows.
};

int main()
{
    Undirected_Graph u_graph {new Linked_list*[5] {}, 5};

    u_graph.A[0] = new Linked_list {new Node {4, nullptr}};
    u_graph.A[4] = new Linked_list {new Node {0, nullptr}};

    u_graph.A[1] = new Linked_list {new Node {3, nullptr}};
    u_graph.A[3] = new Linked_list {new Node {1, nullptr}};

    u_graph.A[0]->head->next = new Node {2, nullptr};
    u_graph.A[2] = new Linked_list {new Node {0, nullptr}};

    return 0;
}