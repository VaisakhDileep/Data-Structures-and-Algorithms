/*
Created by  : Vaisakh Dileep
Date		: 10, July, 2021
Description : This program demonstrates depth first search for a directed graph represented using adjacency list.
*/

#include<iostream>

#include<iomanip>

using namespace std;

namespace Directed_Graph_Using_Adjacency_List // Directed Graph is designed using Adjacency List representation.
{
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
}

using namespace Directed_Graph_Using_Adjacency_List;

void depth_first_search(Directed_Graph *d_graph, int node, int *visited)
{
	if(visited[node] == 0)
	{
		cout<<node<<" ";

		visited[node] = 1;

		Node *last {d_graph->A[node]->head};

		while(last != nullptr)
		{
			if(visited[last->vertex] == 0) // Not necessary to include "visited[last->vertex] == 0", but saves recursive calls.
			{
				depth_first_search(d_graph, last->vertex, visited);
			}

			last = last->next;
		}
	}
}

void handle_depth_first_search(Directed_Graph *d_graph, int root = 0)
{
	if(d_graph == nullptr)
	{
		cout<<"ERROR - Invalid operation, graph is not valid .....";

		return ;
	}

	if()
}

int main()
{
	return 0;
}