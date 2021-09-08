/*
Created by  : Vaisakh Dileep
Date		: 22, July, 2021
Description : This program finds the shortest path from one node to the other for an undirected graph represented using adjacency list(breadth first search).
*/

#include<iostream>

#include<iomanip>

#include<vector>

#include<algorithm>

#include<queue>

using namespace std;

namespace Undirected_Graph_Using_Adjacency_List // Undirected Graph is designed using Adjacency List representation.
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
}

using namespace Undirected_Graph_Using_Adjacency_List;

int** breadth_first_search(Undirected_Graph *u_graph, int root) // Some changes were made compared to the traditional BFS algorithm.
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if(root < 0)
	{
		throw string {"ERROR - Invalid root vertex, vertex cannot be negative ....."};
	}

	int *visited = new int[u_graph->n] {0};

	int **previous_node = new int*[u_graph->n] {nullptr};

	visited[root] = 1;

	queue<int> Q {};

	Q.push(root);

	while(!Q.empty())
	{
		int node {Q.front()};

		Q.pop();

		Undirected_Graph_Using_Adjacency_List::Node *last {u_graph->A[node]->head};

		while(last != nullptr)
		{
			if(visited[last->vertex] == 0)
			{
				visited[last->vertex] = 1;

				previous_node[last->vertex] = new int {node};

				Q.push(last->vertex);
			}

			last = last->next;
		}
	}

	return previous_node;
}

void shortest_path_undirected_graph(Undirected_Graph *u_graph, int start_node, int end_node)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((start_node < 0) or (end_node < 0))
	{
		throw string {"ERROR - Invalid vertex, vertex cannot be negative ....."};
	}

	int **previous_nodes {breadth_first_search(u_graph, start_node)};

	vector<int> path {};

	path.push_back(end_node);

	for(int *i {previous_nodes[end_node]}; i != nullptr; i = previous_nodes[*i])
	{
		path.push_back(*i);
	}

	reverse(path.begin(), path.end()); // Reverses the vector.

	if(path.at(0) != start_node)
	{
		throw string {"ERROR - Invalid operation, no path exists between the nodes ....."};
	}

	for(unsigned long long i {0}; i < path.size(); i++)
	{
		cout<<path.at(i)<<" ";
	}
}

void handle_shortest_path_undirected_graph(Undirected_Graph *u_graph, int start_node, int end_node)
{
	try
	{
		shortest_path_undirected_graph(u_graph, start_node, end_node);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {};

	Edge edges[10] {Edge {0, 1}, Edge {1, 6}, Edge {1, 2}, Edge {1, 5}, Edge {6, 7}, Edge {7, 8}, Edge {2, 3}, Edge {3, 8}, Edge {3, 4}, Edge {5, 4}};

	handle_create_undirected_graph(&u_graph, edges, 10);

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	cout<<"shortest_path_undirected_graph(u_graph, 1, 3): \n";
	handle_shortest_path_undirected_graph(&u_graph, 1, 3);
	cout<<"\n";

	return 0;
}