/*
Created by  : Vaisakh Dileep
Date		: 28, June, 2021
Description : This program removes an edge from a directed graph.
*/

#include<iostream>

#include<iomanip>

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

void remove_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if(edge.vertex_1 >= d_graph->n)
	{
		throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
	}

	if(d_graph->A[edge.vertex_1] == nullptr)
	{
		throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
	}
	else
	{
		Node *last {d_graph->A[edge.vertex_1]->head}, *previous_node {};

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
			d_graph->A[edge.vertex_1]->head = last->next;

			delete last;

			if(d_graph->A[edge.vertex_1]->head == nullptr)
			{
				delete d_graph->A[edge.vertex_1];

				d_graph->A[edge.vertex_1] = nullptr;
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

void handle_remove_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
	try
	{
		remove_edge_directed_graph(d_graph, edge);
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

	cout<<"d_graph: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_remove_edge_directed_graph(&d_graph, Edge {0, 7});

	cout<<"d_graph: [after removing {0, 7}] \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_remove_edge_directed_graph(&d_graph, Edge {0, 2});

	cout<<"d_graph: [after removing {0, 2}] \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_remove_edge_directed_graph(&d_graph, Edge {0, 2});
	cout<<"\n";

	handle_remove_edge_directed_graph(&d_graph, Edge {-1, 2});
	cout<<"\n";

	return 0;
}