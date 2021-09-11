/*
Created by  : Vaisakh Dileep
Date		: 10, September, 2021
Description : This program finds all the back edges in a DFS tree for an undirected graph represented using adjacency list.
*/

// Every other edge other than the tree edge in an undirected graph is considered as a back edge.

#include<iostream>

#include<iomanip>

#include<vector>

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

void depth_first_search(Undirected_Graph *u_graph, int node, int parent, int *visited, vector<pair<int, int>> *back_edges)
{
	if(visited[node] == 0)
	{
		visited[node] = 1;

		Node *last {u_graph->A[node]->head};

		while(last != nullptr)
		{
			if(visited[last->vertex] == 0)
			{
				depth_first_search(u_graph, last->vertex, node, visited, back_edges);
			}
			else if(last->vertex != parent)
			{
				back_edges->push_back(pair<int, int> {node, last->vertex});
			}

			last = last->next;
		}
	}
}

vector<pair<int, int>>* find_back_edges_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if(u_graph->n == 0)
	{
		throw string {"ERROR - Invalid operation, graph is empty ....."};
	}

	vector<pair<int, int>> *back_edges {new vector<pair<int, int>> {}};

	int *visited = new int[u_graph->n] {0};

	for(int i {0}; i < u_graph->n; i++)
	{
		if(u_graph->A[i] == nullptr)
		{
			continue;
		}
		else
		{
			if(visited[i] == 0)
			{
				depth_first_search(u_graph, i, -1, visited, back_edges);
			}
		}
	}

	return back_edges;
}

vector<pair<int, int>>* handle_find_back_edges_undirected_graph(Undirected_Graph *u_graph)
{
	try
	{
		return find_back_edges_undirected_graph(u_graph);
	}
	catch(string &ex)
	{
		cout<<ex;

		return nullptr;
	}
}

void display_back_edges_undirected_graph(vector<pair<int, int>> *back_edges)
{
	if(back_edges == nullptr)
	{
		return ;
	}

	for(int i {0}; i < back_edges->size(); i++)
	{
		cout<<"{"<<back_edges->at(i).first<<", "<<back_edges->at(i).second<<"} ";
	}
}

int main()
{
	Undirected_Graph u_graph {};

	Edge edges[18] {Edge {0, 1}, Edge {1, 1}, Edge {1, 2}, Edge {2, 3}, Edge {3, 7}, Edge {7, 6}, Edge {6, 2}, Edge {6, 3}, Edge {7, 2}, Edge {6, 5}, Edge {5, 2}, Edge {5, 1}, Edge {5, 4}, Edge {4, 0}, Edge {4, 1}, Edge {0, 5}, Edge {1, 6}, Edge {1, 3}};

	handle_create_undirected_graph(&u_graph, edges, 18);

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	vector<pair<int, int>> *back_edges {handle_find_back_edges_undirected_graph(&u_graph)};

	cout<<"back_edges(d_graph): ";
	display_back_edges_undirected_graph(back_edges);
	cout<<"\n";

	return 0;
}