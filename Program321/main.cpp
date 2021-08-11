/*
Created by  : Vaisakh Dileep
Date		: 11, July, 2021
Description : This program demonstrates depth first search for a weighed directed graph represented using adjacency matrix.
*/

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

namespace Weighed_Directed_Graph_Using_Adjacency_Matrix // Weighed Directed Graph is designed using Adjacency Matrix representation.
{
	struct Weighed_Directed_Graph
	{
		vector<vector<int>*> *A;
	};

	struct Weighed_Edge
	{
		int vertex_1;

		int vertex_2;

		int weight;
	};

	void display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
	{
		if((wd_graph == nullptr) or (wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
		{
			cout<<"[\n]";

			return ;
		}

		cout<<"[\n     ";
		for(int i {0}; i < wd_graph->A->at(0)->size(); i++)
		{
			cout<<setw(3)<<i<<" ";
		}
		cout<<"\n";

		for(int i {0}; i < wd_graph->A->size(); i++)
		{
			cout<<setw(3)<<left<<i<<right<<"[ ";
			for(int j {0}; j < wd_graph->A->at(0)->size(); j++)
			{
				if(wd_graph->A->at(i)->at(j) == INT_MAX)
				{
					cout<<"INF"<<" ";
				}
				else
				{
					cout<<setw(3)<<wd_graph->A->at(i)->at(j)<<" ";
				}
			}
			cout<<"]\n";
		}
		cout<<"]";
	}

	void delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
	{
		if(wd_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
		{
			return ;
		}

		for(int i {0}; i < wd_graph->A->size(); i++)
		{
			delete wd_graph->A->at(i);
		}

		delete wd_graph->A;
	}

	void add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
	{
		if(wd_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
		{
			wd_graph->A = new vector<vector<int>*> {new vector<int> {}};
		}

		if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
		{
			throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
		}

		if((w_edge.vertex_1 < wd_graph->A->size()) and (w_edge.vertex_2 < wd_graph->A->at(0)->size()))
		{
			wd_graph->A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = w_edge.weight;
		}
		else
		{
			int new_rows {(w_edge.vertex_1 > (static_cast<int>(wd_graph->A->size()) - 1)) ? w_edge.vertex_1 + 1 : wd_graph->A->size()};

			int new_columns {(w_edge.vertex_2 > (static_cast<int>(wd_graph->A->at(0)->size()) - 1)) ? w_edge.vertex_2 + 1 : wd_graph->A->at(0)->size()};

			Weighed_Directed_Graph temp {new vector<vector<int>*>(new_rows, nullptr)};

			for(int i {0}; i < new_rows; i++)
			{
				temp.A->at(i) = new vector<int>(new_columns, INT_MAX);
			}

			for(int i {0}; i < wd_graph->A->size(); i++)
			{
				for(int j {0}; j < wd_graph->A->at(0)->size(); j++)
				{
					temp.A->at(i)->at(j) = wd_graph->A->at(i)->at(j);
				}
			}

			temp.A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = w_edge.weight;

			delete_weighed_directed_graph(wd_graph);

			wd_graph->A = temp.A;
		}

		for(int i {0}; i < wd_graph->A->size(); i++)
		{
			if(i == wd_graph->A->at(0)->size())
			{
				break;
			}

			if(wd_graph->A->at(i)->at(i) == INT_MAX)
			{
				wd_graph->A->at(i)->at(i) = 0;
			}
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

using namespace Weighed_Directed_Graph_Using_Adjacency_Matrix;

void depth_first_search(Weighed_Directed_Graph *wd_graph, int node, int *visited)
{
	if(visited[node] == 0)
	{
		cout<<node<<" ";

		visited[node] = 1;

		if(node >= wd_graph->A->size())
		{
			return ;
		}

		for(int i {0}; i < wd_graph->A->at(0)->size(); i++)
		{
			if((wd_graph->A->at(node)->at(i) != INT_MAX) and (visited[i] == 0)) // Not necessary to include "visited[i] == 0", but saves recursive calls.
			{
				depth_first_search(wd_graph, i, visited);
			}
		}
	}
}

void handle_depth_first_search(Weighed_Directed_Graph *wd_graph, int root = 0)
{
	if(wd_graph == nullptr)
	{
		cout<<"ERROR - Invalid operation, graph is not valid .....";

		return ;
	}

	if((wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
	{
		cout<<"ERROR - Invalid operation, graph is empty .....";

		return ;
	}

	if(root < 0)
	{
		cout<<"ERROR - Invalid root vertex, vertex cannot be negative .....";

		return ;
	}

	int max_node {(wd_graph->A->size() > wd_graph->A->at(0)->size()) ? wd_graph->A->size() : wd_graph->A->at(0)->size()};

	depth_first_search(wd_graph, root, new int[max_node] {0});
}

int main()
{
	Weighed_Directed_Graph wd_graph {};

	// Weighed_Edge w_edges[11] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {4, 5, 50}, Weighed_Edge {4, 6, 60}, Weighed_Edge {4, 7, 70}, Weighed_Edge {5, 6, 80}, Weighed_Edge {5, 8, 90}, Weighed_Edge {7, 8, 100}, Weighed_Edge {8, 2, 110}};

	Weighed_Edge w_edges[6] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {3, 5, 50}, Weighed_Edge {1, 5, 60}};

	handle_create_weighed_directed_graph(&wd_graph, w_edges, 6);

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	cout<<"DFS(wd_graph): ";
	handle_depth_first_search(&wd_graph);
	cout<<"\n";

	handle_depth_first_search(&wd_graph, -1);
	cout<<"\n";

	return 0;
}