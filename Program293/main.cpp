/*
Created by  : Vaisakh Dileep
Date		: 1, July, 2021
Description : This program creates a weighed directed graph from an array of edges.
*/

#include<iostream>

#include<iomanip>

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

struct Weighed_Directed_Graph
{
	Linked_list **A;

	int n;
};

struct Weighed_Edge
{
	int vertex_1;

	int vertex_2;

	int weight;
};

void display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	if(wd_graph == nullptr)
	{
		return ;
	}

	for(int i {0}; i < wd_graph->n; i++)
	{
		if(wd_graph->A[i] == nullptr)
		{
			continue;
		}
		else
		{
			cout<<setw(3)<<left<<i;

			Node *last {wd_graph->A[i]->head};

			while(last != nullptr)
			{
				cout<<" -["<<setw(3)<<last->weight<<"]-> "<<setw(3)<<last->vertex;

				last = last->next;
			}
			cout<<"\n";
		}
	}
}

void add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge edge)
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if(edge.vertex_1 < wd_graph->n)
	{
		if(wd_graph->A[edge.vertex_1] == nullptr)
		{
			wd_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};
		}
		else
		{
			Node *last {wd_graph->A[edge.vertex_1]->head}, *previous_node {};

			while(last != nullptr)
			{
				previous_node = last;

				if(last->vertex == edge.vertex_2)
				{
					throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
				}

				last = last->next;
			}

			previous_node->next = new Node {edge.vertex_2, edge.weight, nullptr};
		}
	}
	else
	{
		int new_n {edge.vertex_1 + 1};

		Weighed_Directed_Graph temp {new Linked_list*[new_n] {}, new_n};

		for(int i {0}; i < wd_graph->n; i++)
		{
			temp.A[i] = wd_graph->A[i];
		}

		temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};

		wd_graph->A = temp.A;

		temp.A = nullptr;

		wd_graph->n = temp.n;
	}
}

void create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < num_edges; i++)
	{
		try
		{
			add_edge_weighed_directed_graph(wd_graph, w_edges[i]);
		}
		catch(string &ex)
		{
			throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
		}
	}
}

void handle_create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
{
	try
	{
		create_weighed_directed_graph(wd_graph, w_edges, num_edges);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Directed_Graph wd_graph {};

	Weighed_Edge w_edges[10] {Weighed_Edge {0, 1, 10}, Weighed_Edge {0, 8, 20}, Weighed_Edge {0, 10, 30}, Weighed_Edge {1, 3, 40}, Weighed_Edge {10, 4, 50}, Weighed_Edge {10, 11, 60}, Weighed_Edge {7, 9, 70}, Weighed_Edge {7, 11, 80}, Weighed_Edge {15, 12, 90}, Weighed_Edge {15, 0, 100}};

	handle_create_weighed_directed_graph(&wd_graph, w_edges, 10);

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	return 0;
}