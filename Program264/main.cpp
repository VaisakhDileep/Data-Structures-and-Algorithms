/*
Created by  : Vaisakh Dileep
Date		: 25, June, 2021
Description : This program creates a weighed undirected graph from user.
*/

#include<iostream>

#include<iomanip>

#include<sstream>

#include<limits>

using namespace std;

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

struct Weighed_Undirected_Graph
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

void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	if(wu_graph == nullptr)
	{
		return ;
	}

	for(int i {0}; i < wu_graph->n; i++)
	{
		if(wu_graph->A[i] == nullptr)
		{
			continue;
		}
		else
		{
			cout<<setw(3)<<left<<i;

			Node *last {wu_graph->A[i]->head};

			while(last != nullptr)
			{
				cout<<" -["<<setw(3)<<last->weight<<"]-> "<<setw(3)<<last->vertex;

				last = last->next;
			}
			cout<<"\n";
		}
	}
}

void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge edge)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((edge.vertex_1 < wu_graph->n) and (edge.vertex_2 < wu_graph->n))
	{
		if(wu_graph->A[edge.vertex_1] == nullptr)
		{
			wu_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};
		}
		else
		{
			Node *last {wu_graph->A[edge.vertex_1]->head}, *previous_node {};

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

		if(wu_graph->A[edge.vertex_2] == nullptr)
		{
			wu_graph->A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, edge.weight, nullptr}};
		}
		else
		{
			Node *last {wu_graph->A[edge.vertex_2]->head}, *previous_node {};

			while(last != nullptr)
			{
				previous_node = last;

				if(last->vertex == edge.vertex_1)
				{
					throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
				}

				last = last->next;
			}

			previous_node->next = new Node {edge.vertex_1, edge.weight, nullptr};
		}
	}
	else
	{
		int new_n {edge.vertex_1 > edge.vertex_2 ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

		Weighed_Undirected_Graph temp {new Linked_list*[new_n] {}, new_n};

		for(int i {0}; i < wu_graph->n; i++)
		{
			temp.A[i] = wu_graph->A[i];
		}

		if(temp.A[edge.vertex_1] == nullptr)
		{
			temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, edge.weight, nullptr}};
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

			previous_node->next = new Node {edge.vertex_2, edge.weight, nullptr};
		}

		if(temp.A[edge.vertex_2] == nullptr)
		{
			temp.A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, edge.weight, nullptr}};
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

			previous_node->next = new Node {edge.vertex_1, edge.weight, nullptr};
		}

		wu_graph->A = temp.A;

		temp.A = nullptr;

		wu_graph->n = temp.n;
	}
}

void create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	int num_edges {};

	cout<<"Enter the number of edges present in the graph: ";

	cin>>num_edges;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout<<"\nStart entering the edges in the format \"{vertex_1, vertex_2, weight}\": \n";

	for(int i {0}; i < num_edges; i++)
	{
		int vertex_1 {}, vertex_2 {}, weight {};

		string user_input {};

		cout<<"> ";

		getline(cin, user_input);

		istringstream iss {user_input};

		iss.ignore(); // This will ignore "{".

		iss>>vertex_1;

		iss.ignore(); // This will ignore ",".

		iss>>vertex_2;

		iss.ignore(); // This will ignore ",".

		iss>>weight;

		try
		{
			add_edge_weighed_undirected_graph(wu_graph, Weighed_Edge {vertex_1, vertex_2, weight});
		}
		catch(string &ex)
		{
			throw string {"ERROR - Invalid operation, given edge is not valid ....."};
		}
	}
}

void handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	try
	{
		create_weighed_undirected_graph(wu_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {};

	handle_create_weighed_undirected_graph(&wu_graph);
	cout<<"\n\n";

	cout<<"wu_graph:\n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	return 0;
}