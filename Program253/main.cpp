/*
Created by  : Vaisakh Dileep
Date		: 20, June, 2021
Description : This program deletes an undirected graph.
*/

#include<iostream>

using namespace std;

struct Node
{
	int data;

	Node *next;
};

struct Linked_list
{
	Node *head;
};

struct Undirected_Graph
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

void delete_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < u_graph->n; i++)
	{
		if(u_graph->A[i] != nullptr)
		{
			delete_linked_list(u_graph->A[i]);

			u_graph->A[i] = nullptr;
		}
	}
}

void handle_delete_undirected_graph(Undirected_Graph *u_graph)
{
	try
	{
		delete_undirected_graph(u_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {new Linked_list*[5] {}, 5};

	u_graph.A[0] = new Linked_list {new Node {4, nullptr}};
	u_graph.A[4] = new Linked_list {new Node {0, nullptr}};

	u_graph.A[1] = new Linked_list {new Node {3, nullptr}};
	u_graph.A[3] = new Linked_list {new Node {1, nullptr}};

	u_graph.A[3]->head->next = new Node {0, nullptr};
	u_graph.A[0]->head->next = new Node {3, nullptr};

	handle_delete_undirected_graph(&u_graph);

	return 0;
}