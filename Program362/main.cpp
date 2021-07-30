/*
Created by  : Vaisakh Dileep
Date		: 29, July, 2021
Description : This program detects the presence of a negative cycle in a weighed directed graph represented using adjacency list(Bellman-Ford's algorithm).
*/

#include<iostream>

#include<iomanip>

#include<unordered_set>

#include<vector>

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

bool detect_negative_cycle_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	int max_node {wd_graph->n - 1};

	unordered_set<int> vertices {};

	for(int i {0}; i < wd_graph->n; i++)
	{
		if(wd_graph->A[i] == nullptr)
		{
			continue;
		}

		vertices.insert(i);

		Node *last {wd_graph->A[i]->head};

		while(last != nullptr)
		{
			max_node = (last->vertex > max_node) ? last->vertex : max_node;

			vertices.insert(last->vertex);

			last = last->next;
		}
	}

	vector<int> distance(max_node + 1, INT_MAX); // "INT_MAX" corresponds to infinity.

	int start_node {*(vertices.begin())};

	distance.at(start_node) = 0;

flag:
	for(int i {0}; i < (vertices.size() - 1); i++)
	{
		for(int i {0}; i < wd_graph->n; i++)
		{
			if(wd_graph->A[i] == nullptr)
			{
				continue;
			}

			if(distance.at(i) == INT_MAX)
			{
				continue;
			}

			Node *last {wd_graph->A[i]->head};

			while(last != nullptr)
			{
				int new_distance {distance.at(i) + last->weight};

				if(new_distance < distance.at(last->vertex))
				{
					distance.at(last->vertex) = new_distance;
				}

				last = last->next;
			}
		}
	}

	for(int i {0}; i < (vertices.size() - 1); i++)
	{
		if(wd_graph->A[i] == nullptr)
		{
			continue;
		}

		if(distance.at(i) == INT_MAX) // In case if the graph is disconnected, we end up with unvisited vertices.
		{
			distance.at(i) = 0;

			goto flag;
		}

		Node *last {wd_graph->A[i]->head};

		while(last != nullptr)
		{
			int new_distance {distance.at(i) + last->weight};

			if(new_distance < distance.at(last->vertex))
			{
				return true;
			}

			last = last->next;
		}
	}

	return false;
}

bool handle_detect_negative_cycle_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	try
	{
		return detect_negative_cycle_weighed_directed_graph(wd_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Directed_Graph wd_graph {};

	// Weighed_Edge w_edges[7] {Weighed_Edge {0, 1, 1}, Weighed_Edge {1, 2, 2}, Weighed_Edge {2, 3, 3}, Weighed_Edge {3, 1, -6}, Weighed_Edge {2, 4, 4}, Weighed_Edge {4, 5, 5}, Weighed_Edge {5, 4, -1}}; // This test case contains a negative cycle.

	// Weighed_Edge w_edges[7] {Weighed_Edge {0, 1, 1}, Weighed_Edge {1, 2, 2}, Weighed_Edge {2, 3, 3}, Weighed_Edge {3, 1, 6}, Weighed_Edge {2, 4, 4}, Weighed_Edge {4, 5, 5}, Weighed_Edge {5, 4, -1}}; // This test case does not contains a negative cycle.

	// Weighed_Edge w_edges[7] {Weighed_Edge {0, 1, 1}, Weighed_Edge {1, 2, 2}, Weighed_Edge {3, 4, 1}, Weighed_Edge {4, 5, 2}, Weighed_Edge {5, 3, -4}, Weighed_Edge {5, 6, 5}, Weighed_Edge {6, 5, 6}}; // This test case is a disconnected graph that containsa a negative cycle.

	Weighed_Edge w_edges[7] {Weighed_Edge {0, 1, 1}, Weighed_Edge {1, 2, 2}, Weighed_Edge {3, 4, 1}, Weighed_Edge {4, 5, 2}, Weighed_Edge {5, 3, 4}, Weighed_Edge {5, 6, 5}, Weighed_Edge {6, 5, 6}}; // This test case is a disconnected graph that does not containsa a negative cycle.

	handle_create_weighed_directed_graph(&wd_graph, w_edges, 7);

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	cout<<"detect_negative_cycle_weighed_directed_graph(wd_graph): "<<handle_detect_negative_cycle_weighed_directed_graph(&wd_graph)<<"\n";

	return 0;
}