/*
Created by  : Vaisakh Dileep
Date		: 18, June, 2021
Description : This program creates an undirected graph from user.
*/

#include<iostream>

#include<iomanip>

#include<limits>

#include<vector>

using namespace std;

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
	cout<<"\n";

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	return 0;
}