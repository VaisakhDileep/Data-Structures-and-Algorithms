/*
Created by  : Vaisakh Dileep
Date		: 15, September, 2021
Description : This program detects whether there is a cycle in an undirected graph represented using adjacency list(union-find algorithm).
*/

#include<iostream>

#include<iomanip>

#include<vector>

#include<set>

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

namespace Union_Find_Algorithm
{
	vector<int>* create_disjoint_sets(int size)
	{
		return new vector<int>(size, -1);
	}

	int Find(vector<int>* disjoint_sets, int target) // Finds the root of the disjoint set.
	{
		if(disjoint_sets->at(target) == -1)
		{
			return target;
		}

		return Find(disjoint_sets, disjoint_sets->at(target));
	}

	void Union(vector<int>* disjoint_sets, int target_1, int target_2) // Preforms Union operator on the two subsets.
	{
		int target_1_root {Find(disjoint_sets, target_1)};

		int target_2_root {Find(disjoint_sets, target_2)};

		if(target_1_root == target_2_root) // Both the elements are already in the same set.
		{
			return ;
		}

		disjoint_sets->at(target_1_root) = target_2_root;
	}
}

using namespace Undirected_Graph_Using_Adjacency_List;

using namespace Union_Find_Algorithm;

bool detect_cycle_undirected_graph(Undirected_Graph *u_graph)
{
	set<pair<int, int>> edge_list {};

	for(int i {0}; i < u_graph->n; i++)
	{
		Node *last {u_graph->A[i]->head};

		while(last != nullptr)
		{
			if((edge_list.find(pair<int, int> {i, last->vertex}) == edge_list.end()) and (edge_list.find(pair<int, int> {last->vertex, i}) == edge_list.end()))
			{
				edge_list.insert(pair<int, int> {i, last->vertex});
			}

			last = last->next;
		}
	}

	vector<int> *disjoint_sets {create_disjoint_sets(u_graph->n)};

	for(auto itr {edge_list.begin()}; itr != edge_list.end(); itr++)
	{
		int vertex_1_root {Find(disjoint_sets, itr->first)};

		int vertex_2_root {Find(disjoint_sets, itr->second)};

		if(vertex_1_root == vertex_2_root)
		{
			return true;
		}

		Union(disjoint_sets, itr->first, itr->second);
	}

	return false;
}

bool handle_detect_cycle_undirected_graph(Undirected_Graph *u_graph)
{
	try
	{
		return detect_cycle_undirected_graph(u_graph);
	}
	catch(string &ex)
	{
		cout<<ex;

		return false;
	}
}

int main()
{
	Undirected_Graph u_graph {};

	Edge edges[5] {Edge {0, 1}, Edge {1, 4}, Edge {4, 3}, Edge {2, 3}, Edge {1, 2}}; // This test case contains a cycle.

	// Edge edges[5] {Edge {0, 1}, Edge {1, 4}, Edge {4, 3}, Edge {1, 2}, Edge {4, 5}}; // This test case does not contain any cycle.

	// Edge edges[5] {Edge {0, 1}, Edge {2, 3}, Edge {2, 4}, Edge {3, 4}, Edge {4, 5}}; // This test case is a disconnected graph that contains a cycle.

	// Edge edges[5] {Edge {0, 1}, Edge {1, 2}, Edge {3, 4}, Edge {4, 5}, Edge {5, 6}}; // This test case is a disconnected graph that does not contain any cycle.

	handle_create_undirected_graph(&u_graph, edges, 5);

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	cout<<"detect_cycle_undirected_graph(u_graph): "<<handle_detect_cycle_undirected_graph(&u_graph)<<"\n";

	return 0;
}