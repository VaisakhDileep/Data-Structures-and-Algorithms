/*
Created by  : Vaisakh Dileep
Date		: 21, June, 2021
Description : This program removes an edge from an undirected graph.
*/

#include<iostream>

#include<iomanip>

using namespace std;

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

void remove_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative index ....."};
	}

	if((edge.vertex_1 >= u_graph->n) or (edge.vertex_2 >= u_graph->n))
	{
		throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
	}

	if(u_graph->A[edge.vertex_1] == nullptr)
	{
		throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
	}
	else
	{
		Node *last {u_graph->A[edge.vertex_1]->head}, *previous_node {};

		while(last != nullptr)
		{
			if(last->vertex == edge.vertex_2)
			{
				break;
			}

			previous_node = last;

			last = last->next;
		}

		if(previous_node == nullptr)
		{
			u_graph->A[edge.vertex_1]->head = last->next;

			delete last;

			if(u_graph->A[edge.vertex_1]->head == nullptr)
			{
				delete u_graph->A[edge.vertex_1];

				u_graph->A[edge.vertex_1] = nullptr;
			}
		}
		else if(last == nullptr)
		{
			throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
		}
		else
		{
			previous_node->next = last->next;

			delete last;
		}
	}

	if(u_graph->A[edge.vertex_2] == nullptr)
	{
		throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
	}
	else
	{
		Node *last {u_graph->A[edge.vertex_2]->head}, *previous_node {};

		while(last != nullptr)
		{
			if(last->vertex == edge.vertex_1)
			{
				break;
			}

			previous_node = last;

			last = last->next;
		}

		if(previous_node == nullptr)
		{
			u_graph->A[edge.vertex_2]->head = last->next;

			delete last;

			if(u_graph->A[edge.vertex_2]->head == nullptr)
			{
				delete u_graph->A[edge.vertex_2];

				u_graph->A[edge.vertex_2] = nullptr;
			}
		}
		else if(last == nullptr)
		{
			throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
		}
		else
		{
			previous_node->next = last->next;

			delete last;
		}
	}
}

void handle_remove_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
{
	try
	{
		remove_edge_undirected_graph(u_graph, edge);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {new Linked_list*[5] {}, 5};

	u_graph.A[0] = new Linked_list {new Node {4, nullptr}};
	u_graph.A[4] = new Linked_list {new Node {0, nullptr}};

	u_graph.A[1] = new Linked_list {new Node {3, nullptr}};
	u_graph.A[3] = new Linked_list {new Node {1, nullptr}};

	u_graph.A[3]->head->next = new Node {0, nullptr};
	u_graph.A[0]->head->next = new Node {3, nullptr};

	cout<<"u_graph:\n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	handle_remove_edge_undirected_graph(&u_graph, Edge {3, 1});

	cout<<"u_graph: [after removing {3, 1}]\n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	handle_remove_edge_undirected_graph(&u_graph, Edge {0, 4});

	cout<<"u_graph: [after removing {0, 4}]\n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	handle_remove_edge_undirected_graph(&u_graph, Edge {0, 4});
	cout<<"\n";

	handle_remove_edge_undirected_graph(&u_graph, Edge {0, -1});
	cout<<"\n";

	return 0;
}