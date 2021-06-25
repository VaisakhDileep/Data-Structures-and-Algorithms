/*
Created by  : Vaisakh Dileep
Date		: 23, June, 2021
Description : This program deletes a weighed undirected graph.
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

struct Weighed_Undirected_Graph
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

void delete_weighed_undirected_graph(Weighed_Undirected_Graph *u_graph)
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

void handle_delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	try
	{
		delete_weighed_undirected_graph(wu_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {new Linked_list*[10] {}, 10};

	wu_graph.A[0] = new Linked_list {new Node {9, 15, nullptr}};
	wu_graph.A[9] = new Linked_list {new Node {0, 15, nullptr}};

	wu_graph.A[1] = new Linked_list {new Node {3, 200, nullptr}};
	wu_graph.A[3] = new Linked_list {new Node {1, 200, nullptr}};

	wu_graph.A[0]->head->next = new Node {2, 35, nullptr};
	wu_graph.A[2] = new Linked_list {new Node {0, 35, nullptr}};

	handle_delete_weighed_undirected_graph(&wu_graph);

	return 0;
}