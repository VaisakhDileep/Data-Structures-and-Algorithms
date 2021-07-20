/*
Created by  : Vaisakh Dileep
Date		: 25, June, 2021
Description : This program removes an edge from a weighed undirected graph.
*/

#include<iostream>

#include<iomanip>

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

void remove_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge edge)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative index ....."};
	}

	if((edge.vertex_1 >= wu_graph->n) or (edge.vertex_2 >= wu_graph->n))
	{
		throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
	}

	if(wu_graph->A[edge.vertex_1] == nullptr)
	{
		throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
	}
	else
	{
		Node *last {wu_graph->A[edge.vertex_1]->head}, *previous_node {};

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
			wu_graph->A[edge.vertex_1]->head = last->next;

			delete last;

			if(wu_graph->A[edge.vertex_1]->head == nullptr)
			{
				delete wu_graph->A[edge.vertex_1];

				wu_graph->A[edge.vertex_1] = nullptr;
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

	if(edge.vertex_1 == edge.vertex_2)
	{
		return ;
	}

	if(wu_graph->A[edge.vertex_2] == nullptr)
	{
		throw string {"ERROR - Invalid operation, given edge is not present in the graph ....."};
	}
	else
	{
		Node *last {wu_graph->A[edge.vertex_2]->head}, *previous_node {};

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
			wu_graph->A[edge.vertex_2]->head = last->next;

			delete last;

			if(wu_graph->A[edge.vertex_2]->head == nullptr)
			{
				delete wu_graph->A[edge.vertex_2];

				wu_graph->A[edge.vertex_2] = nullptr;
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

void handle_remove_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge edge)
{
	try
	{
		remove_edge_weighed_undirected_graph(wu_graph, edge);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {new Linked_list*[10] {}, 10};

	wu_graph.A[0] = new Linked_list {new Node {9, 15, nullptr}};
	wu_graph.A[9] = new Linked_list {new Node {0, 15, nullptr}};

	wu_graph.A[1] = new Linked_list {new Node {3, 200, nullptr}};
	wu_graph.A[3] = new Linked_list {new Node {1, 200, nullptr}};

	wu_graph.A[0]->head->next = new Node {2, 35, nullptr};
	wu_graph.A[2] = new Linked_list {new Node {0, 35, nullptr}};

	wu_graph.A[3]->head->next = new Node {7, 45, nullptr};
	wu_graph.A[7] = new Linked_list {new Node {3, 45, nullptr}};

	wu_graph.A[1]->head->next = new Node {1, 65, nullptr};

	cout<<"wu_graph: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {3, 7, 0}); // It is not necessary to provide the weight of the edge.

	cout<<"wu_graph [after removing {3, 7}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {0, 9, 0});

	cout<<"wu_graph [after removing {0, 9}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {1, 1, 0});

	cout<<"wu_graph [after removing {1, 1}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {0, 9, 0});
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {-1, 4});
	cout<<"\n";

	return 0;
}