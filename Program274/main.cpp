/*
Created by  : Vaisakh Dileep
Date		: 27, June, 2021
Description : This program deletes a directed graph.
*/

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

struct Directed_Graph
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

void delete_directed_graph(Directed_Graph *d_graph)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < d_graph->n; i++)
	{
		if(d_graph->A[i] != nullptr)
		{
			delete_linked_list(d_graph->A[i]);

			d_graph->A[i] = nullptr;
		}
	}
}

void handle_delete_directed_graph(Directed_Graph *d_graph)
{
	try
	{
		delete_directed_graph(d_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Directed_Graph d_graph {new Linked_list*[5] {}, 5};

	d_graph.A[0] = new Linked_list {new Node {2, nullptr}};
	
	d_graph.A[2] = new Linked_list {new Node {5, nullptr}};

	d_graph.A[0]->head->next = new Node {7, nullptr};

	handle_delete_directed_graph(&d_graph);

	return 0;
}