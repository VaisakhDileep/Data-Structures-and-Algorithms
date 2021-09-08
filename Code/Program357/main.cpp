/*
Created by  : Vaisakh Dileep
Date		: 26, July, 2021
Description : This program finds the single source longest path cost for a weighed directed acyclic graph represented using adjacency list(topological sort).
*/

// This version of single source longest path cost will work only for a weighed directed acyclic graph.

#include<iostream>

#include<iomanip>

#include<list>

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

namespace Detect_Cycles_Weighed_Directed_Graph // "detect_cycle_weighed_directed_graph()" is implemented using DFS algorithm.
{
	bool depth_first_search(Weighed_Directed_Graph *wd_graph, int node, int *visited, int *recursive_call_stack_state) // Some changes were made compared to the traditional DFS algorithm.
	{
		if(wd_graph->A[node] == nullptr) // This is a leaf node. We already checked for "node >= d_graph->n" in the while loop.
		{
			return false;
		}

		if(visited[node] == 0)
		{
			visited[node] = 1;

			recursive_call_stack_state[node] = 1;

			Node *last {wd_graph->A[node]->head};

			while(last != nullptr)
			{
				if(last->vertex >= wd_graph->n) // This is a leaf node.
				{
					last = last->next;

					continue;
				}

				if(visited[last->vertex] == 0) // If the child node is not visited, then propogate.
				{
					if(depth_first_search(wd_graph, last->vertex, visited, recursive_call_stack_state) == true)
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

	bool detect_cycle_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
	{
		if(wd_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		int *visited = new int[wd_graph->n] {0}; // "visited" array does not contain any leaf node.

		int *recursive_call_stack_state = new int[wd_graph->n] {0}; // Checks if the node is visited in the recursive call stack. As we pop the function call stack, it is resetted. "recursive_call_stack_state" array does not contain any leaf nodes.

		for(int i {0}; i < wd_graph->n; i++) // In case if the graph is disconnected.
		{
			if(wd_graph->A[i] == nullptr)
			{
				continue;
			}
			else
			{
				if(visited[i] == 0)
				{
					if(depth_first_search(wd_graph, i, visited, recursive_call_stack_state) == true)
					{
						return true;
					}
				}
			}
		}

		return false;
	}

	bool handle_detect_cycle_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
	{
		try
		{
			return detect_cycle_weighed_directed_graph(wd_graph);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

namespace Topological_Sort_Weighed_Directed_Graph // "topological_sort_weighed_directed_graph()" is implemented using DFS algorithm.
{
	void depth_first_search(Weighed_Directed_Graph *wd_graph, int node, int *visited, list<int> *topological_order) // Some changes were made compared to the traditional DFS algorithm.
	{
		if((node >= wd_graph->n) or (wd_graph->A[node] == nullptr)) // This is a leaf node.
		{
			if(visited[node] == 0)
			{
				visited[node] = 1;

				topological_order->push_front(node);
			}
		}

		if(visited[node] == 0)
		{
			visited[node] = 1;

			Node *last {wd_graph->A[node]->head};

			while(last != nullptr)
			{
				if(visited[last->vertex] == 0)
				{
					depth_first_search(wd_graph, last->vertex, visited, topological_order);
				}

				last = last->next;
			}

			topological_order->push_front(node);
		}
	}

	list<int>* topological_sort_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
	{
		using namespace Detect_Cycles_Weighed_Directed_Graph; // This will prevent the conflict between the two DFS algorithm.

		if(wd_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if(handle_detect_cycle_weighed_directed_graph(wd_graph) == true)
		{
			throw string {"ERROR - Invalid operation, weighed directed graph contains cycle ....."};
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

		list<int> *topological_order {new list<int> {}};

		int *visited = new int[max_node + 1] {0};

		for(int i {0}; i <= max_node; i++)
		{
			if(wd_graph->A[i] == nullptr) // This is a leaf node or an unassigned node.
			{
				continue; // There is no point doing DFS on a leaf node or an unassigned node.
			}

			depth_first_search(wd_graph, i, visited, topological_order);
		}

		return topological_order;
	}

	list<int>* handle_topological_sort_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
	{
		try
		{
			return topological_sort_weighed_directed_graph(wd_graph);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

vector<int>* single_source_longest_path_cost_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, int source)
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if(source < 0)
	{
		throw string {"ERROR - Invalid source vertex, source vertex cannot be negative ....."};
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

	if(source > max_node)
	{
		throw string {"ERROR - Invalid source vertex, source vertex exceeds the largest vertex in the graph ....."};
	}

	using namespace Topological_Sort_Weighed_Directed_Graph;

	list<int> *topological_order {topological_sort_weighed_directed_graph(wd_graph)};

	vector<int> *distance {new vector<int>((max_node + 1), 1)};

	distance->at(source) = 0;

	for(auto itr {topological_order->begin()}; itr != topological_order->end(); itr++)
	{
		if(distance->at(*itr) != 1)
		{
			if((*itr >= wd_graph->n) or (wd_graph->A[*itr] == nullptr)) // This is a leaf node.
			{
				continue;
			}

			Node *last {wd_graph->A[*itr]->head};

			while(last != nullptr)
			{
				if(distance->at(last->vertex) == 1)
				{
					distance->at(last->vertex) = -last->weight + distance->at(*itr);
				}
				else
				{
					distance->at(last->vertex) = min(distance->at(last->vertex), (-(last->weight) + distance->at(*itr)));
				}

				last = last->next;
			}
		}
	}

	for(int i {0}; i < distance->size(); i++)
	{
		distance->at(i) *= -1;
	}

	return distance;
}

vector<int>* handle_single_source_longest_path_cost_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, int source)
{
	try
	{
		return single_source_longest_path_cost_weighed_directed_graph(wd_graph, source);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

void display_single_source_longest_path_cost(vector<int> *distance, int source)
{
	if(distance == nullptr)
	{
		return ;
	}

	for(int i {0}; i < distance->size(); i++)
	{
		cout<<source<<" -> "<<i<<" : "<<((distance->at(i) == -1) ? "Not reachable" : to_string(distance->at(i)))<<"\n";
	}
}

int main()
{
	Weighed_Directed_Graph wd_graph {};

	// Weighed_Edge w_edges[6] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {3, 5, 50}, Weighed_Edge {1, 5, 60}};

	Weighed_Edge w_edges[6] {Weighed_Edge {0, 1, 10}, Weighed_Edge {2, 1, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {1, 4, 50}, Weighed_Edge {4, 5, 60}};

	handle_create_weighed_directed_graph(&wd_graph, w_edges, 6);

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	vector<int> *distance {handle_single_source_longest_path_cost_weighed_directed_graph(&wd_graph, 1)};

	display_single_source_longest_path_cost(distance, 1);

	return 0;
}