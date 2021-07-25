/*
Created by  : Vaisakh Dileep
Date		: 23, July, 2021
Description :  This program detects whether there is a cycle in an undirected graph represented using adjacency list(depth first search).
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

bool depth_first_search(Directed_Graph *d_graph, int node, int *visited, int *recursive_call_stack_state) // Some changes were made compared to the traditional DFS algorithm.
{
	if(d_graph->A[node] == nullptr) // This is a leaf node.
	{
		return false;
	}

	if(visited[node] == 0)
	{
		visited[node] = 1;

		recursive_call_stack_state[node] = 1;

		Node *last {d_graph->A[node]->head};

		while(last != nullptr)
		{
			if(last->vertex >= d_graph->n) // This is a leaf node.
			{
				last = last->next;

				continue;
			}

			if(visited[last->vertex] == 0) // If the child node is not visited, then propogate.
			{
				if(depth_first_search(d_graph, last->vertex, visited, recursive_call_stack_state) == true)
				{
					return true;
				}
			}
			else if(recursive_call_stack_state[last->vertex] == 1) // If the child node is visited and it's already in the recursive call stack.
			{
				return true;
			}

			last = last->next;
		}
	}

	recursive_call_stack_state[node] = 0; // Reset the node state.

	return false;
}

bool detect_cycle_directed_graph(Directed_Graph *d_graph)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	int *visited = new int[d_graph->n] {0}; // "visited" array does not contain any leaf nodes.

	int *recursive_call_stack_state = new int[d_graph->n] {0}; // Checks if the node is visited in the recursive call stack. As we pop the function call stack, it is resetted. "recursive_call_stack_state" array does not contain any leaf nodes.

	for(int i {0}; i < d_graph->n; i++) // In case if the graph is disconnected.
	{
		if(d_graph->A[i] == nullptr)
		{
			continue;
		}
		else
		{
			if(visited[i] == 0)
			{
				if(depth_first_search(d_graph, i, visited, recursive_call_stack_state) == true)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool handle_detect_cycle_directed_graph(Directed_Graph *d_graph)
{
	try
	{
		return detect_cycle_directed_graph(d_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Directed_Graph d_graph {};

	// Edge edges[5] {Edge {0, 1}, Edge {1, 2}, Edge {2, 3}, Edge {3, 1}, Edge {3, 4}}; // This test case contains a cycle.

	// Edge edges[5] {Edge {0, 1}, Edge {1, 2}, Edge {2, 3}, Edge {3, 4}, Edge {3, 5}}; // This test case does not contain any cycle.

	// Edge edges[5] {Edge {0, 1}, Edge {2, 3}, Edge {3, 4}, Edge {4, 3}, Edge {4, 5}}; // This test case is a disconnected graph that contains a cycle.

	Edge edges[5] {Edge {0, 1}, Edge {2, 3}, Edge {3, 4}, Edge {4, 5}, Edge {4, 6}}; // This test case is a disconnected graph that does not contain any cycle.

	handle_create_directed_graph(&d_graph, edges, 5);

	cout<<"d_graph: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	cout<<"detect_cycle_directed_graph(d_graph): "<<handle_detect_cycle_directed_graph(&d_graph)<<"\n";

	return 0;
}