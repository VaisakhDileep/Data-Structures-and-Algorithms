/*
Created by  : Vaisakh Dileep
Date		: 12, August, 2021
Description : This program finds the all pair shortest path for a weighed directed graph represented using adjacency matrix(Floyd Warshall's algorithm).
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


namespace Floyd_Warshall_All_Pair_Shortest_Path_For_Weighed_Directed_Graph
{
	vector<int> *non_reachable {new vector<int> {0}}; // Behaves like a flag.

	vector<int> *negative_cycle {new vector<int> {0}}; // Behaves like a flag.

	vector<vector<vector<int>*>*>* all_pair_shortest_path_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
	{
		if(wd_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
		{
			throw string {"ERROR - Invalid operation, graph is empty ....."};
		}

		int row_count {static_cast<int>(wd_graph->A->size())}, column_count {static_cast<int>(wd_graph->A->at(0)->size())};

		vector<vector<int>*> *distance {new vector<vector<int>*>(row_count, nullptr)};

		vector<vector<int>*> *next_node {new vector<vector<int>*>(row_count, nullptr)};

		for(int i {0}; i < row_count; i++)
		{
			distance->at(i) = new vector<int>(column_count, 0);

			next_node->at(i) = new vector<int>(column_count, 0);
		}

		int max_node {(row_count > column_count) ? row_count : column_count};

		for(int i {0}; i < row_count; i++)
		{
			for(int j {0}; j < column_count; j++)
			{
				distance->at(i)->at(j) = wd_graph->A->at(i)->at(j);

				if(wd_graph->A->at(i)->at(j) != INT_MAX)
				{
					next_node->at(i)->at(j) = j;
				}
				else
				{
					next_node->at(i)->at(j) = INT_MAX;
				}
			}
		}

		for(int k {0}; k < max_node; k++)
		{
			for(int i {0}; i < row_count; i++)
			{
				for(int j {0}; j < column_count; j++)
				{
					if((k >= row_count) or (k >= column_count) or (distance->at(i)->at(k) == INT_MAX) or (distance->at(k)->at(j) == INT_MAX)) // Either of them is infinity.
					{
						continue;
					}
					else if((distance->at(i)->at(k) + distance->at(k)->at(j)) < distance->at(i)->at(j))
					{
						distance->at(i)->at(j) = distance->at(i)->at(k) + distance->at(k)->at(j);

						next_node->at(i)->at(j) = next_node->at(i)->at(k);
					}
				}
			}
		}

		for(int k {0}; k < max_node; k++) // In order to propogate "INT_MIN".
		{
			for(int i {0}; i < row_count; i++)
			{
				for(int j {0}; j < column_count; j++)
				{
					if((k >= row_count) or (k >= column_count) or (distance->at(i)->at(k) == INT_MAX) or (distance->at(k)->at(j) == INT_MAX))
					{
						continue;
					}

					if((distance->at(i)->at(k) == INT_MIN) or (distance->at(k)->at(j) == INT_MIN))
					{
						distance->at(i)->at(j) = INT_MIN;

						next_node->at(i)->at(j) = INT_MIN; // 'INT_MIN' denotes the presense of infinite path.

						continue;
					}
					else if(distance->at(i)->at(k) + distance->at(k)->at(j) < distance->at(i)->at(j))
					{
						distance->at(i)->at(j) = INT_MIN;

						next_node->at(i)->at(j) = INT_MIN; // 'INT_MIN' denotes the presense of infinite path.
					}
				}
			}
		}

		vector<vector<vector<int>*>*> *all_pair_shortest_path {new vector<vector<vector<int>*>*>(row_count, nullptr)};

		for(int i {0}; i < row_count; i++)
		{
			all_pair_shortest_path->at(i) = new vector<vector<int>*>(column_count, nullptr);
		}

		for(int i {0}; i < row_count; i++)
		{
			for(int j {0}; j < column_count; j++)
			{
				all_pair_shortest_path->at(i)->at(j) = new vector<int> {};

				if(next_node->at(i)->at(j) == INT_MAX)
				{
					all_pair_shortest_path->at(i)->at(j) = non_reachable;

					continue;
				}
				else if(next_node->at(i)->at(j) == INT_MIN)
				{
					all_pair_shortest_path->at(i)->at(j) = negative_cycle;

					continue;
				}

				int current_node {i};

				for(; current_node != j; current_node = next_node->at(current_node)->at(j))
				{
					if(current_node == INT_MIN) // If the path contains a negative cycle.
					{
						all_pair_shortest_path->at(i)->at(j) = negative_cycle;

						break;
					}
					else
					{
						all_pair_shortest_path->at(i)->at(j)->push_back(current_node);
					}
				}
			}
		}

		return all_pair_shortest_path;
	}
}

using namespace Floyd_Warshall_All_Pair_Shortest_Path_For_Weighed_Directed_Graph;

vector<vector<vector<int>*>*>* handle_all_pair_shortest_path_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	try
	{
		all_pair_shortest_path_weighed_directed_graph(wd_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

void display_all_pair_shortest_path_weighed_directed_graph(vector<vector<vector<int>*>*>* all_pair_shortest_path)
{
	if((all_pair_shortest_path == nullptr) or (all_pair_shortest_path->size() == 0) or (all_pair_shortest_path->at(0) == nullptr) or (all_pair_shortest_path->at(0)->size() == 0))
	{
		return ;
	}

	for(int i {0}; i < all_pair_shortest_path->size(); i++)
	{
		cout<<i<<": \n";
		for(int j {0}; j < all_pair_shortest_path->at(0)->size(); j++)
		{
			cout<<"\t"<<setw(3)<<i<<" -> "<<setw(3)<<j<<": ";

			if(all_pair_shortest_path->at(i)->at(j) == non_reachable)
			{
				cout<<"non reachable\n";

				continue;
			}
			else if(all_pair_shortest_path->at(i)->at(j) == negative_cycle)
			{
				cout<<"negative cycle\n";

				continue;
			}

			cout<<"[ ";
			for(int k {0}; k < all_pair_shortest_path->at(i)->at(j)->size(); k++)
			{
				cout<<all_pair_shortest_path->at(i)->at(j)->at(k)<<" ";
			}
			cout<<j<<" ]\n";
		}
	}
}

int main()
{
	Weighed_Directed_Graph wd_graph {};

	Weighed_Edge w_edges[9] {{0, 1, 10}, {1, 2, 7}, {4, 2, -11}, {2, 3, 6}, {3, 4, 4}, {4, 5, 10}, {5, 6, 2}, {6, 4, 3}, {6, 7, 4}};

	handle_create_weighed_directed_graph(&wd_graph, w_edges, 9);

	vector<vector<vector<int>*>*> *all_pair_shortest_path {handle_all_pair_shortest_path_weighed_directed_graph(&wd_graph)};

	cout<<"all pair shortest path:\n";
	display_all_pair_shortest_path_weighed_directed_graph(all_pair_shortest_path);

	return 0;
}