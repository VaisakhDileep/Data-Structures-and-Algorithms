/*
Created by  : Vaisakh Dileep
Date		: 10, July, 2021
Description : This program demonstrates depth first search for a directed graph represented using adjacency matrix.
*/

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

namespace Directed_Graph_Using_Adjacency_Matrix // Directed Graph is designed using Adjacency Matrix representation.
{
	struct Directed_Graph
	{
		vector<vector<int>*> *A;
	};

	struct Edge
	{
		int vertex_1;

		int vertex_2;
	};

	void display_directed_graph(Directed_Graph *d_graph)
	{
		if((d_graph == nullptr) or (d_graph->A == nullptr) or (d_graph->A->size() == 0))
		{
			cout<<"[\n]";

			return ;
		}

		cout<<"[\n     ";
		for(int i {0}; i < d_graph->A->at(0)->size(); i++)
		{
			cout<<setw(3)<<i<<" ";
		}
		cout<<"\n";

		for(int i {0}; i < d_graph->A->size(); i++)
		{
			cout<<setw(3)<<left<<i<<right<<"[ ";
			for(int j {0}; j < d_graph->A->at(0)->size(); j++)
			{
				if(d_graph->A->at(i)->at(j) == INT_MAX)
				{
					cout<<"INF"<<" ";
				}
				else
				{
					cout<<setw(3)<<d_graph->A->at(i)->at(j)<<" ";
				}
			}
			cout<<"]\n";
		}
		cout<<"]";
	}

	void delete_directed_graph(Directed_Graph *d_graph)
	{
		if(d_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((d_graph->A == nullptr) or (d_graph->A->size() == 0))
		{
			return ;
		}

		for(int i {0}; i < d_graph->A->size(); i++)
		{
			delete d_graph->A->at(i);
		}

		delete d_graph->A;
	}

	void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
	{
		if(d_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((d_graph->A == nullptr) or (d_graph->A->size() == 0))
		{
			d_graph->A = new vector<vector<int>*> {new vector<int> {}};
		}

		if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
		{
			throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
		}

		if((edge.vertex_1 < d_graph->A->size()) and (edge.vertex_2 < d_graph->A->at(0)->size()))
		{
			d_graph->A->at(edge.vertex_1)->at(edge.vertex_2) = 1;
		}
		else
		{
			int new_rows {(edge.vertex_1 > (static_cast<int>(d_graph->A->size()) - 1)) ? edge.vertex_1 + 1 : d_graph->A->size()};

			int new_columns {(edge.vertex_2 > (static_cast<int>(d_graph->A->at(0)->size()) - 1)) ? edge.vertex_2 + 1 : d_graph->A->at(0)->size()};

			Directed_Graph temp {new vector<vector<int> *>(new_rows, nullptr)};

			for(int i {0}; i < new_rows; i++)
			{
				temp.A->at(i) = new vector<int>(new_columns, 0);
			}

			for(int i {0}; i < d_graph->A->size(); i++)
			{
				for(int j {0}; j < d_graph->A->at(0)->size(); j++)
				{
					temp.A->at(i)->at(j) = d_graph->A->at(i)->at(j);
				}
			}

			temp.A->at(edge.vertex_1)->at(edge.vertex_2) = 1;

			delete_directed_graph(d_graph);

			d_graph->A = temp.A;
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

using namespace Directed_Graph_Using_Adjacency_Matrix;

void depth_first_search(Directed_Graph *d_graph, int node, int *visited)
{
	if(visited[node] == 0)
	{
		cout<<node<<" ";

		visited[node] = 1;

		if(node >= d_graph->A->size()) // If "node" exceeds the row size.
		{
			return ;
		}

		for(int i {0}; i < d_graph->A->at(0)->size(); i++)
		{
			if((d_graph->A->at(node)->at(i) == 1) and (visited[i] == 0)) // Not necessary to include "visited[i] == 0", but saves recursive calls.
			{
				depth_first_search(d_graph, i, visited);
			}
		}
	}
}

void handle_depth_first_search(Directed_Graph *d_graph, int root = 0)
{
	if(d_graph == nullptr)
	{
		cout<<"ERROR - Invalid operation, graph is not valid .....";

		return ;
	}

	if((d_graph->A == nullptr) or (d_graph->A->size() == 0))
	{
		cout<<"ERROR - Invalid operation, graph is empty .....";

		return ;
	}

	if(root < 0)
	{
		cout<<"ERROR - Invalid root vertex, vertex cannot be negative .....";

		return ;
	}

	int max_node {(d_graph->A->size() > d_graph->A->at(0)->size()) ? d_graph->A->size() : d_graph->A->at(0)->size()};

	depth_first_search(d_graph, root, new int[max_node] {0});
}

int main()
{
	Directed_Graph d_graph {};

	// Edge edges[11] {Edge {0, 1}, Edge {1, 2}, Edge {1, 3}, Edge {3, 4}, Edge {4, 5}, Edge {4, 6}, Edge {4, 7}, Edge {5, 6}, Edge {5, 8}, Edge {7, 8}, Edge {8, 2}};

	Edge edges[6] {Edge {0, 1}, Edge {1, 2}, Edge {1, 3}, Edge {3, 4}, Edge {3, 5}, Edge {1, 5}};

	handle_create_directed_graph(&d_graph, edges, 6);

	cout<<"d_graph: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	cout<<"DFS(d_graph): ";
	handle_depth_first_search(&d_graph);
	cout<<"\n";

	handle_depth_first_search(&d_graph, -1);
	cout<<"\n";

	return 0;
}