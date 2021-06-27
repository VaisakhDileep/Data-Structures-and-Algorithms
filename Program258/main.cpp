/*
Created by  : Vaisakh Dileep
Date		: 22, June, 2021
Description : This program creates a weighed undirected graph.
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

struct Weighed_Undirected_Graph // Using adjacency list.
{
	Linked_list **A; // array of linked lists.

	int n; // number of rows.
};

int main()
{
	Weighed_Undirected_Graph wu_graph {new Linked_list*[5] {}, 5};

	wu_graph.A[0] = new Linked_list {new Node {4, 15, nullptr}};
	wu_graph.A[4] = new Linked_list {new Node {0, 15, nullptr}};

	wu_graph.A[1] = new Linked_list {new Node {3, 20, nullptr}};
	wu_graph.A[3] = new Linked_list {new Node {1, 20, nullptr}};

	wu_graph.A[0]->head->next = new Node {2, 35, nullptr};
	wu_graph.A[2] = new Linked_list {new Node {0, 35, nullptr}};

	return 0;
}