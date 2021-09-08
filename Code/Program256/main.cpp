/*
Created by  : Vaisakh Dileep
Date		: 21, June, 2021
Description : This program creates an undirected graph from an array of edges.
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

struct Undirected_Graph
{
	Linked_list **A;

	int n;
};

void display_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		return ;
	}

	for(int i {0}; i < u_graph->n; i++)
	{
		if(u_graph->A[i] == nullptr)
		{
			continue;
		}
		else
		{
			cout<<setw(3)<<left<<i;

			Node *last {u_graph->A[i]->head};

			while(last != nullptr)
			{
				cout<<" -> "<<setw(3)<<last->vertex;

				last = last->next;
			}
			cout<<"\n";
		}
	}
}

void add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((edge.vertex_1 < u_graph->n) and (edge.vertex_2 < u_graph->n))
	{
		if(u_graph->A[edge.vertex_1] == nullptr)
		{
			u_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
		}
		else
		{
			Node *last {u_graph->A[edge.vertex_1]->head}, *previous_node {};

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

		if(edge.vertex_1 == edge.vertex_2)
		{
			return ;
		}

		if(u_graph->A[edge.vertex_2] == nullptr)
		{
			u_graph->A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, nullptr}};
		}
		else
		{
			Node *last {u_graph->A[edge.vertex_2]->head}, *previous_node {};

			while(last != nullptr)
			{
				previous_node = last;

				if(last->vertex == edge.vertex_1)
				{
					throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
				}

				last = last->next;
			}

			previous_node->next = new Node {edge.vertex_1, nullptr};
		}
	}
	else
	{
		int new_n {edge.vertex_1 > edge.vertex_2 ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

		Undirected_Graph temp {new Linked_list*[new_n] {}, new_n};

		for(int i {0}; i < u_graph->n; i++)
		{
			temp.A[i] = u_graph->A[i];
		}

		if(temp.A[edge.vertex_1] == nullptr)
		{
			temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
		}
		else
		{
			Node *last {temp.A[edge.vertex_1]->head}, *previous_node {};

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

		if(edge.vertex_1 == edge.vertex_2)
		{
			u_graph->A = temp.A;

			temp.A = nullptr;

			u_graph->n = temp.n;

			return ;
		}

		if(temp.A[edge.vertex_2] == nullptr)
		{
			temp.A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, nullptr}};
		}
		else
		{
			Node *last {temp.A[edge.vertex_2]->head}, *previous_node {};

			while(last != nullptr)
			{
				previous_node = last;

				if(last->vertex == edge.vertex_1)
				{
					throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
				}

				last = last->next;
			}

			previous_node->next = new Node {edge.vertex_1, nullptr};
		}

		u_graph->A = temp.A;

		temp.A = nullptr;

		u_graph->n = temp.n;
	}
}

void create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < num_edges; i++)
	{
		try
		{
			add_edge_undirected_graph(u_graph, edges[i]);
		}
		catch(string &ex)
		{
			throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
		}
	}
}

void handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
{
	try
	{
		create_undirected_graph(u_graph, edges, num_edges);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {};

	Edge edges[10] {Edge {1, 2}, Edge {8, 8}, Edge {8, 9}, Edge {11, 10}, Edge {5, 2}, Edge {3, 7}, Edge {7, 11}, Edge {0, 10}, Edge {3, 4}, Edge {11, 7}};

	handle_create_undirected_graph(&u_graph, edges, 10);

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	return 0;
}