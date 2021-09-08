/*
Created by  : Vaisakh Dileep
Date		: 19, June, 2021
Description : This program inserts an edge to a weighed undirected graph.
*/

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

struct Weighed_Undirected_Graph
{
	vector<vector<int>*> *A;
};

struct Weighed_Edge
{
	int vertex_1;

	int vertex_2;

	int weight;
};

void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	if((wu_graph == nullptr) or (wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < wu_graph->A->size(); i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < wu_graph->A->size(); i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < wu_graph->A->size(); j++)
		{
			if(wu_graph->A->at(i)->at(j) == INT_MAX)
			{
				cout<<"INF"<<" ";
			}
			else
			{
				cout<<setw(3)<<wu_graph->A->at(i)->at(j)<<" ";
			}
		}
		cout<<"]\n";
	}
	cout<<"]";
}

void delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
	{
		return ;
	}

	for(int i {0}; i < wu_graph->A->size(); i++)
	{
		delete wu_graph->A->at(i);
	}

	delete wu_graph->A;
}

void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((wu_graph->A == nullptr) or (wu_graph->A->size() ==0))
	{
		wu_graph->A = new vector<vector<int>*> {new vector<int> {}};
	}

	if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((w_edge.vertex_1 < wu_graph->A->size()) and (w_edge.vertex_2 < wu_graph->A->size()))
	{
		wu_graph->A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = wu_graph->A->at(w_edge.vertex_2)->at(w_edge.vertex_1) = w_edge.weight;
	}
	else
	{
		int new_n {(w_edge.vertex_1 > w_edge.vertex_2) ? w_edge.vertex_1 + 1 : w_edge.vertex_2 + 1};

		Weighed_Undirected_Graph temp {new vector<vector<int>*>(new_n, nullptr)};

		for(int i {0}; i < new_n; i++)
		{
			temp.A->at(i) = new vector<int>(new_n, INT_MAX);
		}

		for(int i {0}; i < wu_graph->A->size(); i++)
		{
			for(int j {0}; j < wu_graph->A->at(0)->size(); j++)
			{
				temp.A->at(i)->at(j) = wu_graph->A->at(i)->at(j);
			}
		}

		temp.A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = temp.A->at(w_edge.vertex_2)->at(w_edge.vertex_1) = w_edge.weight;

		delete_weighed_undirected_graph(wu_graph);

		wu_graph->A = temp.A;

		for(int i {0}; i < wu_graph->A->size(); i++)
		{
			if(wu_graph->A->at(i)->at(i) == INT_MAX)
			{
				wu_graph->A->at(i)->at(i) = 0;
			}
		}
	}
}

void handle_add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
	try
	{
		add_edge_weighed_undirected_graph(wu_graph, w_edge);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {new vector<vector<int>*> {new vector<int> {0, 3, INT_MAX, INT_MAX, 7}, new vector<int> {3, 0, INT_MAX, INT_MAX, INT_MAX}, new vector<int> {INT_MAX, INT_MAX, 0, 8, INT_MAX}, new vector<int> {INT_MAX, INT_MAX, 8, 0, INT_MAX}, new vector<int> {7, INT_MAX, INT_MAX, INT_MAX, 0}}};

	cout<<"wu_graph: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_add_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {0, 4, 10});

	cout<<"wu_graph [after adding {0, 4, 10}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_add_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {1, 1, 11});

	cout<<"wu_graph [after adding {1, 1, 11}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_add_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {2, 6, 15});

	cout<<"wu_graph [after adding {2, 6, 15}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_add_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {-1, 2, 12});
	cout<<"\n";

	return 0;
}