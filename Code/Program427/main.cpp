/*
Created by  : Vaisakh Dileep
Date		: 16, September, 2021
Description : This program finds the minimum spanning tree of a weighed undirected graph represented using adjacency list.(Kruskal's algorithm)
*/

// Kruskal's algorithm will not work for disconnected graphs. Negative weights are allowed.

#include<iostream>

#include<iomanip>

#include<set>

#include<queue>

using namespace std;

namespace Weighed_Undirected_Graph_Using_Adjacency_List // Weighed Undirected Graph is designed using Adjacency List representation.
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

	struct Weighed_Undirected_Graph
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

	void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
	{
		if(wu_graph == nullptr)
		{
			return ;
		}

		for(int i {0}; i < wu_graph->n; i++)
		{
			if(wu_graph->A[i] == nullptr)
			{
				continue;
			}
			else
			{
				cout<<setw(3)<<left<<i;

				Node *last {wu_graph->A[i]->head};

				while(last != nullptr)
				{
					cout<<" -["<<setw(3)<<last->weight<<"]-> "<<setw(3)<<last->vertex;

					last = last->next;
				}
				cout<<"\n";
			}
		}
	}

	void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge edge)
	{
		if(wu_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
		{
			throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
		}

		if((edge.vertex_1 < wu_graph->n) and (edge.vertex_2 < wu_graph->n))
		{
			if(wu_graph->A[edge.vertex_1] == nullptr)
			{
				wu_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};
			}
			else
			{
				Node *last {wu_graph->A[edge.vertex_1]->head}, *previous_node {};

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

			if(edge.vertex_1 == edge.vertex_2)
			{
				return ;
			}

			if(wu_graph->A[edge.vertex_2] == nullptr)
			{
				wu_graph->A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, edge.weight, nullptr}};
			}
			else
			{
				Node *last {wu_graph->A[edge.vertex_2]->head}, *previous_node {};

				while(last != nullptr)
				{
					previous_node = last;

					if(last->vertex == edge.vertex_1)
					{
						throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
					}

					last = last->next;
				}

				previous_node->next = new Node {edge.vertex_1, edge.weight, nullptr};
			}
		}
		else
		{
			int new_n {edge.vertex_1 > edge.vertex_2 ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

			Weighed_Undirected_Graph temp {new Linked_list*[new_n] {}, new_n};

			for(int i {0}; i < wu_graph->n; i++)
			{
				temp.A[i] = wu_graph->A[i];
			}

			if(temp.A[edge.vertex_1] == nullptr)
			{
				temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};
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

				previous_node->next = new Node {edge.vertex_2, edge.weight, nullptr};
			}

			if(edge.vertex_1 == edge.vertex_2)
			{
				wu_graph->A = temp.A;

				temp.A = nullptr;

				wu_graph->n = temp.n;

				return ;
			}

			if(temp.A[edge.vertex_2] == nullptr)
			{
				temp.A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, edge.weight, nullptr}};
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

				previous_node->next = new Node {edge.vertex_1, edge.weight, nullptr};
			}

			wu_graph->A = temp.A;

			temp.A = nullptr;

			wu_graph->n = temp.n;
		}
	}

	void create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
	{
		if(wu_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		for(int i {0}; i < num_edges; i++)
		{
			try
			{
				add_edge_weighed_undirected_graph(wu_graph, w_edges[i]);
			}
			catch(string &ex)
			{
				throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
			}
		}
	}

	void handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
	{
		try
		{
			create_weighed_undirected_graph(wu_graph, w_edges, num_edges);
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

using namespace Weighed_Undirected_Graph_Using_Adjacency_List;

using namespace Union_Find_Algorithm;

class Custom_Compare // Custom compare function for "priority_queue".
{
public:
	bool operator() (tuple<int, int, int> &t_1, tuple<int, int, int> &t_2)
	{
		return get<2>(t_1) > get<2>(t_2); // Priority is higher for edges with lesser weights.
	}
};

Weighed_Undirected_Graph* kruskals_minimum_spanning_tree_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	set<tuple<int, int, int>> weighed_edge_list {};

	set<int> vertices {};

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Custom_Compare> p_queue {};

	for(int i {0}; i < wu_graph->n; i++)
	{
		if(wu_graph->A[i] == nullptr) // Redundant Node.
		{
			continue;
		}

		vertices.insert(i);

		Node *last {wu_graph->A[i]->head};

		while(last != nullptr)
		{
			if((weighed_edge_list.find(tuple<int, int, int> {i, last->vertex, last->weight}) == weighed_edge_list.end()) and (weighed_edge_list.find(tuple<int, int, int> {last->vertex, i, last->weight}) == weighed_edge_list.end()))
			{
				weighed_edge_list.insert(tuple<int, int, int> {i, last->vertex, last->weight});
			}

			last = last->next;
		}
	}

	for(auto itr {weighed_edge_list.begin()}; itr != weighed_edge_list.end(); itr++)
	{
		p_queue.push(tuple<int, int, int> {get<0>(*itr), get<1>(*itr), get<2>(*itr)});
	}

	int edge_count {vertices.size() - 1};

	Weighed_Undirected_Graph *minimum_spanning_tree {new Weighed_Undirected_Graph {}};

	vector<int> *disjoint_sets {create_disjoint_sets(wu_graph->n)};

	tuple<int, int, int> target {p_queue.top()};

	p_queue.pop();

	while(edge_count > 0)
	{
		int vertex_1_root {Find(disjoint_sets, get<0>(target))};

		int vertex_2_root {Find(disjoint_sets, get<1>(target))};

		if(vertex_1_root != vertex_2_root)
		{
			add_edge_weighed_undirected_graph(minimum_spanning_tree, Weighed_Edge {get<0>(target), get<1>(target), get<2>(target)});

			Union(disjoint_sets, get<0>(target), get<1>(target));

			edge_count--;
		}

		target = p_queue.top();

		p_queue.pop();
	}

	return minimum_spanning_tree;
}

Weighed_Undirected_Graph* handle_kruskals_minimum_spanning_tree_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	try
	{
		return kruskals_minimum_spanning_tree_weighed_undirected_graph(wu_graph);
	}
	catch(string &ex)
	{
		cout<<ex;

		return nullptr;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {};

	Weighed_Edge w_edges[6] {Weighed_Edge {0, 1, -2}, Weighed_Edge {1, 2, -5}, Weighed_Edge {0, 2, -3}, Weighed_Edge {2, 4, 13}, Weighed_Edge {2, 3, 10}, Weighed_Edge {3, 4, 2}};

	handle_create_weighed_undirected_graph(&wu_graph, w_edges, 6);

	cout<<"wu_graph: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	Weighed_Undirected_Graph *minimum_spanning_tree {handle_kruskals_minimum_spanning_tree_weighed_undirected_graph(&wu_graph)};

	cout<<"minimum_spanning_tree: \n";
	display_weighed_undirected_graph(minimum_spanning_tree);
	cout<<"\n";

	return 0;
}