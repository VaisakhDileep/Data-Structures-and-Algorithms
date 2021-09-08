/*
Created by  : Vaisakh Dileep
Date		: 29, June, 2021
Description : This program demonstrates breadth first search for an undirected graph represented using adjacency matrix.
*/

#include<iostream>

#include<iomanip>

#include<queue>

using namespace std;

namespace Undirected_Graph_Using_Adjacency_Matrix // Undirected Graph is designed using Adjacency Matrix representation.
{
	struct Undirected_Graph
	{
		vector<vector<int>*> *A;
	};

	struct Edge
	{
		int vertex_1;

		int vertex_2;
	};

	void display_undirected_graph(Undirected_Graph *u_graph)
	{
		if((u_graph == nullptr) or (u_graph->A == nullptr) or (u_graph->A->size() == 0))
		{
			cout<<"[\n]";

			return ;
		}

		cout<<"[\n     ";
		for(int i {0}; i < u_graph->A->size(); i++)
		{
			cout<<setw(3)<<i<<" ";
		}
		cout<<"\n";

		for(int i {0}; i < u_graph->A->size(); i++)
		{
			cout<<setw(3)<<left<<i<<right<<"[ ";
			for(int j {0}; j < u_graph->A->size(); j++)
			{
				cout<<setw(3)<<u_graph->A->at(i)->at(j)<<" ";
			}
			cout<<"]\n";
		}
		cout<<"]";
	}

	void delete_undirected_graph(Undirected_Graph *u_graph)
	{
		if(u_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((u_graph->A == nullptr) or (u_graph->A->size() == 0))
		{
			return ;
		}

		for(int i {0}; i < u_graph->A->size(); i++)
		{
			delete u_graph->A->at(i);
		}

		delete u_graph->A;
	}

	void add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
	{
		if(u_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((u_graph->A == nullptr) or (u_graph->A->size() == 0))
		{
			u_graph->A = new vector<vector<int>*> {new vector<int> {}};
		}

		if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
		{
			throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
		}

		if((edge.vertex_1 < u_graph->A->size()) and (edge.vertex_2 < u_graph->A->size()))
		{
			u_graph->A->at(edge.vertex_1)->at(edge.vertex_2) = u_graph->A->at(edge.vertex_2)->at(edge.vertex_1) = 1;
		}
		else
		{
			int new_n {(edge.vertex_1 > edge.vertex_2) ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

			Undirected_Graph temp {new vector<vector<int>*>(new_n, nullptr)};

			for(int i {0}; i < new_n; i++)
			{
				temp.A->at(i) = new vector<int>(new_n, 0);
			}

			for(int i {0}; i < u_graph->A->size(); i++)
			{
				for(int j {0}; j < u_graph->A->at(0)->size(); j++)
				{
					temp.A->at(i)->at(j) = u_graph->A->at(i)->at(j);
				}
			}

			temp.A->at(edge.vertex_1)->at(edge.vertex_2) = temp.A->at(edge.vertex_2)->at(edge.vertex_1) = 1;

			delete_undirected_graph(u_graph);

			u_graph->A = temp.A;
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

using namespace Undirected_Graph_Using_Adjacency_Matrix;

void breadth_first_search(Undirected_Graph *u_graph, int root)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((u_graph->A == nullptr) or (u_graph->A->size() == 0))
	{
		throw string {"ERROR - Invalid operation, graph is empty ....."} ;
	}

	if(root < 0)
	{
		throw string {"ERROR - Invalid root vertex, vertex cannot be negative ....."};
	}

	cout<<root<<" ";

	int *visited = new int[u_graph->A->size()] {0};

	visited[root] = 1;

	queue<int> Q {};

	Q.push(root);

	while(!Q.empty())
	{
		int node {Q.front()};

		Q.pop();

		for(int i {0}; i < u_graph->A->size(); i++)
		{
			if((u_graph->A->at(node)->at(i) == 1) and (visited[i] == 0))
			{
				cout<<i<<" ";

				visited[i] = 1;

				Q.push(i);
			}
		}
	}
}

void handle_breadth_first_search(Undirected_Graph *u_graph, int root = 0)
{
	try
	{
		breadth_first_search(u_graph, root);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {new vector<vector<int>*> {}};

	Edge edges[9] {Edge {0, 1}, Edge {0, 2}, Edge {0, 3}, Edge {1, 2}, Edge {3, 4}, Edge {2, 4}, Edge {4, 5}, Edge {4, 6}, Edge {3, 2}};

	handle_create_undirected_graph(&u_graph, edges, 9);

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	cout<<"BFS(u_graph): ";
	handle_breadth_first_search(&u_graph);
	cout<<"\n";

	handle_breadth_first_search(&u_graph, -1);
	cout<<"\n";

	return 0;
}