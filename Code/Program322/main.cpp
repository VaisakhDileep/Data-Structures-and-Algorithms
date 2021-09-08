/*
Created by  : Vaisakh Dileep
Date		: 11, July, 2021
Description : This program demonstrates depth first search for a weighed directed graph represented using adjacency list.
*/

#include<iostream>

#include<iomanip>

using namespace std;

namespace Weighed_Directed_Graph_Using_Adjacency_List // Weighed Directed Graph is designed using Adjacency List representation.
{
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
}

using namespace Weighed_Directed_Graph_Using_Adjacency_List;

void depth_first_search(Weighed_Directed_Graph *wd_graph, int node, int *visited)
{
	if(wd_graph->A[node] == nullptr)
	{
		if(visited[node] == 0)
		{
			cout<<node<<" ";

			visited[node] = 1;
		}

		return ;
	}

	if(visited[node] == 0)
	{
		cout<<node<<" ";

		visited[node] = 1;

		Node *last {wd_graph->A[node]->head};

		while(last != nullptr)
		{
			if(visited[last->vertex] == 0) // Not necessary to include "visited[last->vertex] == 0", but saves recursive calls.
			{
				depth_first_search(wd_graph, last->vertex, visited);
			}

			last = last->next;
		}
	}
}

void handle_depth_first_search(Weighed_Directed_Graph *wd_graph, int root = 0)
{
	if(wd_graph == nullptr)
	{
		cout<<"ERROR - Invalid operation, graph is not valid .....";

		return ;
	}

	if(root < 0)
	{
		cout<<"ERROR - Invalid root vertex, vertex cannot be negative .....";

		return ;
	}

	int max_node {wd_graph->n - 1};

	for(int i {0}; i < wd_graph->n; i++)
	{
		if(wd_graph->A[i] == nullptr)
		{
			continue;
		}

		Node *last {wd_graph->A[i]->head};

		while(last != nullptr)
		{
			max_node = (last->vertex > max_node) ? last->vertex : max_node;

			last = last->next;
		}
	}

	depth_first_search(wd_graph, root, new int[max_node + 1] {0});
}

int main()
{
	Weighed_Directed_Graph wd_graph {};

	// Weighed_Edge w_edges[11] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {4, 5, 50}, Weighed_Edge {4, 6, 60}, Weighed_Edge {4, 7, 70}, Weighed_Edge {5, 6, 80}, Weighed_Edge {5, 8, 90}, Weighed_Edge {7, 8, 100}, Weighed_Edge {8, 2, 110}};

	Weighed_Edge w_edges[6] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {3, 5, 50}, Weighed_Edge {1, 5, 60}};

	handle_create_weighed_directed_graph(&wd_graph, w_edges, 6);

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	cout<<"DFS(wd_graph): ";
	handle_depth_first_search(&wd_graph);
	cout<<"\n";

	handle_depth_first_search(&wd_graph, -1);
	cout<<"\n";

	return 0;
}