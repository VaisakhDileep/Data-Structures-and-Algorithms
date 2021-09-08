/*
Created by  : Vaisakh Dileep
Date		: 28, June, 2021
Description : This program creates a directed graph from an array of edges.
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

void create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < num_edges; i++)
	{
		try
		{
			add_edge_directed_graph(d_graph, edges[i]);
		}
		catch(string &ex)
		{
			throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
		}
	}
}

void handle_create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
{
	try
	{
		create_directed_graph(d_graph, edges, num_edges);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Directed_Graph d_graph {};

	Edge edges[10] {Edge {0, 1}, Edge {2, 8}, Edge {2, 6}, Edge {1, 10}, Edge {10, 1}, Edge {7, 0}, Edge {3, 4}, Edge {10, 5}, Edge {11, 1}, Edge {7, 9}};

	handle_create_directed_graph(&d_graph, edges, 10);

	cout<<"d_graph: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	return 0;
}