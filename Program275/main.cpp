/*
Created by  : Vaisakh Dileep
Date		: 27, June, 2021
Description : This program inserts an edge to a directed graph.
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

void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if(edge.vertex_1 < d_graph->n)
	{
		if(d_graph->A[edge.vertex_1] == nullptr)
		{
			d_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
		}
		else
		{
			Node *last {d_graph->A[edge.vertex_1]->head}, *previous_node {};

			while(last != nullptr)
			{
				previous_node = last;

				if(last->vertex == edge.vertex_2)
				{
					throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
				}

				last = last->next;
			}

			previous_node->next = new Node {edge.vertex_2, nullptr};
		}
	}
	else
	{
		int new_n {edge.vertex_1 + 1};

		Directed_Graph temp {new Linked_list*[new_n] {}, new_n};

		for(int i {0}; i < d_graph->n; i++)
		{
			temp.A[i] = d_graph->A[i];
		}

		temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};

		d_graph->A = temp.A;

		temp.A = nullptr;

		d_graph->n = temp.n;
	}
}

void handle_add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
	try
	{
		add_edge_directed_graph(d_graph, edge);
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

	handle_add_edge_directed_graph(&d_graph, Edge {10, 2});

	cout<<"d_graph [after adding {10, 2}]: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_add_edge_directed_graph(&d_graph, Edge {2, 10});

	cout<<"d_graph [after adding {2, 10}]: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_add_edge_directed_graph(&d_graph, Edge {5, 4});

	cout<<"d_graph [after adding {5, 4}]: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_add_edge_directed_graph(&d_graph, Edge {12, 12});

	cout<<"d_graph [after adding {12, 12}]: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_add_edge_directed_graph(&d_graph, Edge {5, 4});
	cout<<"\n";

	handle_add_edge_directed_graph(&d_graph, Edge {-1, 2});
	cout<<"\n";

	return 0;
}