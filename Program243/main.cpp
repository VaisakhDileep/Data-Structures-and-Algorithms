/*
Created by  : Vaisakh Dileep
Date		: 18, June, 2021
Description : This program creates an undirected graph from user.
*/

#include<iostream>

#include<iomanip>

#include<sstream>

#include<limits>

using namespace std;

struct Undirected_Graph
{
	int **A;

	int n;
};

struct Edge
{
	int vertex_1;

	int vertex_2;
};

void display_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < u_graph->n; i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < u_graph->n; i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < u_graph->n; j++)
		{
			cout<<setw(3)<<u_graph->A[i][j]<<" ";
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

	for(int i {0}; i < u_graph->n; i++)
	{
		delete[] u_graph->A[i];
	}

	delete[] u_graph->A;
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
		u_graph->A[edge.vertex_1][edge.vertex_2] = u_graph->A[edge.vertex_2][edge.vertex_1] = 1;
	}
	else
	{
		int new_n {(edge.vertex_1 > edge.vertex_2) ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

		Undirected_Graph temp {new int*[new_n] {}, new_n};

		for(int i {0}; i < new_n; i++)
		{
			temp.A[i] = new int[new_n] {};
		}

		for(int i {0}; i < u_graph->n; i++)
		{
			for(int j {0}; j < u_graph->n; j++)
			{
				temp.A[i][j] = u_graph->A[i][j];
			}
		}

		temp.A[edge.vertex_1][edge.vertex_2] = temp.A[edge.vertex_2][edge.vertex_1] = 1;

		delete_undirected_graph(u_graph);

		u_graph->A = temp.A;

		u_graph->n = temp.n;
	}
}

void create_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	int num_edges {};

	cout<<"Enter the number of edges present in the graph: ";

	cin>>num_edges;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout<<"\nStart entering the edges in the format \"{vertex_1, vertex_2}\": \n";

	for(int i {0}; i < num_edges; i++)
	{
		int vertex_1 {}, vertex_2 {};

		string user_input {};

		cout<<"> ";

		getline(cin, user_input);

		istringstream iss {user_input};

		iss.ignore(); // This will ignore "{".

		iss>>vertex_1;

		iss.ignore(); // This will ignore ",".

		iss>>vertex_2;

		try
		{
			add_edge_undirected_graph(u_graph, Edge {vertex_1, vertex_2});
		}
		catch(string &ex)
		{
			throw string {"ERROR - Invalid operation, given edge is not valid ....."};
		}
	}
}

void handle_create_undirected_graph(Undirected_Graph *u_graph)
{
	try
	{
		create_undirected_graph(u_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {};

	handle_create_undirected_graph(&u_graph);
	cout<<"\n\n";

	cout<<"u_graph:\n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	return 0;
}