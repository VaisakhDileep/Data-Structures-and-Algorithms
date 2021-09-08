/*
Created by  : Vaisakh Dileep
Date		: 10, July, 2021
Description : This program demonstrates breadth first search for a weighed directed graph represented using adjacency list.
*/

#include<iostream>

#include<iomanip>

#include<queue>

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

void breadth_first_search(Weighed_Directed_Graph *wd_graph, int root)
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if(root < 0)
	{
		throw string {"ERROR - Invalid root vertex, vertex cannot be negative ....."};
	}

	cout<<root<<" ";

	int max_node {root};

	for(int i {0}; i < wd_graph->n; i++)
	{
		if(wd_graph->A[i] == nullptr)
		{
			continue;
		}

		Weighed_Directed_Graph_Using_Adjacency_List::Node *last {wd_graph->A[i]->head};

		while(last != nullptr)
		{
			max_node = (last->vertex > max_node) ? last->vertex : max_node;

			last = last->next;
		}
	}

	int *visited = new int[max_node + 1] {0};

	visited[root] = 1;

	queue<int> Q {};

	Q.push(root);

	while(!Q.empty())
	{
		int node {Q.front()};

		Q.pop();

		if(wd_graph->A[node] == nullptr)
		{
			continue;
		}

		Weighed_Directed_Graph_Using_Adjacency_List::Node *last {wd_graph->A[node]->head};

		while(last != nullptr)
		{
			if(visited[last->vertex] == 0)
			{
				cout<<last->vertex<<" ";

				visited[last->vertex] = 1;

				Q.push(last->vertex);
			}

			last = last->next;
		}
	}
}

void handle_breadth_first_search(Weighed_Directed_Graph *wd_graph, int root = 0)
{
	try
	{
		breadth_first_search(wd_graph, root);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Directed_Graph wd_graph {};

	Weighed_Edge w_edges[10] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {4, 5, 50}, Weighed_Edge {4, 6, 60}, Weighed_Edge {4, 7, 70}, Weighed_Edge {5, 6, 80}, Weighed_Edge {7, 8, 90}, Weighed_Edge {8, 2, 100}};

	handle_create_weighed_directed_graph(&wd_graph, w_edges, 10);

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	cout<<"BFS(wd_graph): ";
	handle_breadth_first_search(&wd_graph);
	cout<<"\n";

	handle_breadth_first_search(&wd_graph, -1);
	cout<<"\n";

	return 0;
}