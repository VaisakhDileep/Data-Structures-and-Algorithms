/*
Created by  : Vaisakh Dileep
Date		: 22, June, 2021
Description : This program displays a weighed undirected graph.
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

namespace prototype_1 // Here we print every vertex.
{
	void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
	{
		if(wu_graph == nullptr)
		{
			return ;
		}

		for(int i {0}; i < wu_graph->n; i++)
		{
			cout<<setw(3)<<left<<i;

			if(wu_graph->A[i] == nullptr)
			{
				cout<<" -> "<<"X\n";
			}
			else
			{
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
}

namespace prototype_2 // Here we print the vertices that have at least one edge.
{
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

	cout<<"wu_graph [prototype 1]: \n";
	prototype_1::display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	cout<<"wu_graph [prototype 2]: \n";
	prototype_2::display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	return 0;
}