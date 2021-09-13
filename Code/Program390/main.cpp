/*
Created by  : Vaisakh Dileep
Date		: 16, August, 2021
Description : This program finds all the bridges in an undirected graph represented using adjacency list(Tarjan's algorithm).
*/

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

void depth_first_search(Undirected_Graph *u_graph, int node, int parent, vector<int> *discover_time, vector<int> *low_link, vector<bool> *visited, vector<vector<int>*> *bridges, int &clock)
{
	visited->at(node) = true;

	clock++;

	low_link->at(node) = discover_time->at(node) = clock;

	Node *last {u_graph->A[node]->head};

	while(last != nullptr)
	{
		if(last->vertex == parent) // Since we have already defined the link(forward link or backward link) and don't want to include both forward link and backward link.
		{
			last = last->next;

			continue;
		}

		if(visited->at(last->vertex) == false)
		{
			depth_first_search(u_graph, last->vertex, node, discover_time, low_link, visited, bridges, clock);

			low_link->at(node) = min(low_link->at(node), low_link->at(last->vertex));

			if(discover_time->at(node) < low_link->at(last->vertex)) // If "low_link" of node is greater than it's previous node, then there is no back edge and therefore the edge is a bridge.
			{
				bridges->push_back(new vector<int> {node, last->vertex});
			}
		}
		else
		{
			low_link->at(node) = min(low_link->at(node), discover_time->at(last->vertex));
		}

		last = last->next;
	}
}

vector<vector<int>*>* find_bridges_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	int clock {0};

	int max_node {u_graph->n - 1};

	vector<int> *disover_time {new vector<int>(max_node + 1, 0)}; // A unique "discover_time" is given to each node(nodes that arrive early have lesser "discover_time").

	vector<int> *low_link {new vector<int>(max_node + 1, 0)}; // "low_link" of a node is the least "discover time" of any node reachable from the node.

	vector<bool> *visited {new vector<bool>(max_node + 1, false)};

	vector<vector<int>*> *bridges {new vector<vector<int>*> {}};

	for(int i {0}; i <= max_node; i++)
	{
		if(u_graph->A[i] == nullptr)
		{
			continue;
		}

		if(visited->at(i) == false)
		{
			depth_first_search(u_graph, i, -1, disover_time, low_link, visited, bridges, clock);
		}
	}

	return bridges;
}

vector<vector<int>*>* handle_find_bridges_undirected_graph(Undirected_Graph *u_graph)
{
	try
	{
		return find_bridges_undirected_graph(u_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

void display_bridges(vector<vector<int>*> *bridges)
{
	if((bridges == nullptr) or (bridges->size() == 0))
	{
		return ;
	}

	for(int i {0}; i < bridges->size(); i++)
	{
		cout<<bridges->at(i)->at(0)<<" -> "<<bridges->at(i)->at(1)<<"\n";
	}
}

int main()
{
	Undirected_Graph u_graph {};

	Edge edges[10] {Edge {0, 1}, Edge {1, 2}, Edge {2, 3}, Edge {3, 4}, Edge {4, 5}, Edge {5, 3}, Edge {5, 6}, Edge {7, 8}, Edge {8, 9}, Edge {10, 11}};

	handle_create_undirected_graph(&u_graph, edges, 10);

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	vector<vector<int>*>* bridges {handle_find_bridges_undirected_graph(&u_graph)};

	cout<<"bridges: \n";

	display_bridges(bridges);

	return 0;
}