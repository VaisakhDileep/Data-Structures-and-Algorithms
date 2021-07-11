/*
Created by  : Vaisakh Dileep
Date		: 9, July, 2021
Description : This program demonstrates breadth first search for a directed graph represented using adjacency list.
*/

#include<iostream>

#include<iomanip>

using namespace std;

namespace Queue_Using_Linked_list // Queue is designed using Linked List representation.
{
	struct Node
	{
		int data;

		Node *next;
	};

	struct Queue
	{
		Node *front {nullptr};

		Node *rear {nullptr};
	};

	bool is_full_queue(Queue *Q)
	{
		Node *temp = new Node {0, nullptr};

		if(temp == NULL)
		{
			return true;
		}
		else
		{
			delete temp;

			return false;
		}
	}

	bool is_empty_queue(Queue *Q)
	{
		if(Q == nullptr)
		{
			throw string {"ERROR - Invalid operation, queue is not valid ....."};
		}

		if(Q->front == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enqueue(Queue *Q, int value)
	{
		if(Q == nullptr)
		{
			throw string {"ERROR - Invalid operation, queue is not valid ....."};
		}

		if(is_full_queue(Q))
		{
			throw string {"ERROR - Invalid operation, queue is full ....."};
		}

		if(Q->front == nullptr)
		{
			Q->front = Q->rear = new Node {value, nullptr};
		}
		else
		{
			Q->rear = Q->rear->next = new Node {value, nullptr};
		}
	}

	void handle_enqueue(Queue *Q, int value)
	{
		try
		{
			enqueue(Q, value);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}

	int dequeue(Queue *Q)
	{
		if(Q == nullptr)
		{
			throw string {"ERROR - Invalid operation, queue is not valid ....."};
		}

		if(is_empty_queue(Q))
		{
			throw string {"ERROR - Invalid operation, queue is empty ....."};
		}
		else
		{
			int deleted_value {Q->front->data};

			Node *temp {Q->front};

			Q->front = Q->front->next;

			if(Q->front == nullptr)
			{
				Q->rear = nullptr;
			}

			delete temp;

			return deleted_value;
		}
	}

	int handle_dequeue(Queue *Q)
	{
		try
		{
			return dequeue(Q);
		}
		catch(string &ex)
		{
			cout<<ex;

			return -1;
		}
	}
}

namespace Directed_Graph_Using_Adjacency_List // Directed Graph is designed using Adjacency List representation.
{
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

	struct Directed_Graph
	{
		Linked_list **A;

		int n;
	};

	void display_directed_graph(Directed_Graph *d_graph)
	{
		if(d_graph == nullptr)
		{
			return ;
		}

		for(int i {0}; i < d_graph->n; i++)
		{
			if(d_graph->A[i] == nullptr)
			{
				continue;
			}
			else
			{
				cout<<setw(3)<<left<<i;

				Node *last {d_graph->A[i]->head};

				while(last != nullptr)
				{
					cout<<" -> "<<setw(3)<<last->vertex;

					last = last->next;
				}
				cout<<"\n";
			}
		}
	}

	void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
	{
		if(d_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
		{
			throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
		}

		if(edge.vertex_1 < d_graph->n)
		{
			if(d_graph->A[edge.vertex_1] == nullptr)
			{
				d_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
			}
			else
			{
				Node *last {d_graph->A[edge.vertex_1]->head}, *previous_node {};

				while(last != nullptr)
				{
					previous_node = last;

					if(last->vertex == edge.vertex_2)
					{
						throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
					}

					last = last->next;
				}

				previous_node->next = new Node {edge.vertex_2, nullptr};
			}
		}
		else
		{
			int new_n {edge.vertex_1 + 1};

			Directed_Graph temp {new Linked_list*[new_n] {}, new_n};

			for(int i {0}; i < d_graph->n; i++)
			{
				temp.A[i] = d_graph->A[i];
			}

			temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};

			d_graph->A = temp.A;

			temp.A = nullptr;

			d_graph->n = temp.n;
		}
	}

	void create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
	{
		if(d_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		for(int i {0}; i < num_edges; i++)
		{
			try
			{
				add_edge_directed_graph(d_graph, edges[i]);
			}
			catch(string &ex)
			{
				throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
			}
		}
	}

	void handle_create_directed_graph(Directed_Graph *d_graph, Edge *edges, int num_edges)
	{
		try
		{
			create_directed_graph(d_graph, edges, num_edges);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

using namespace Directed_Graph_Using_Adjacency_List;

using namespace Queue_Using_Linked_list;

void breadth_first_search(Directed_Graph *d_graph, int root)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if(root < 0)
	{
		throw string {"ERROR - Invalid root vertex, vertex cannot be negative ....."};
	}

	cout<<root<<" ";

	int max_node {root};

	for(int i {0}; i < d_graph->n; i++)
	{
		if(d_graph->A[i] == nullptr)
		{
			continue;
		}

		Directed_Graph_Using_Adjacency_List::Node *last {d_graph->A[i]->head};

		while(last != nullptr)
		{
			max_node = (last->vertex > max_node) ? last->vertex : max_node;

			last = last->next;
		}
	}

	int *visited = new int[max_node + 1] {0};

	visited[root] = 1;

	Queue Q {};

	handle_enqueue(&Q, root);

	while(!is_empty_queue(&Q))
	{
		int node {handle_dequeue(&Q)};

		if(d_graph->A[node] == nullptr)
		{
			continue;
		}

		Directed_Graph_Using_Adjacency_List::Node *last {d_graph->A[node]->head};

		while(last != nullptr)
		{
			if(visited[last->vertex] == 0)
			{
				cout<<last->vertex<<" ";

				visited[last->vertex] = 1;

				handle_enqueue(&Q, last->vertex);
			}

			last = last->next;
		}
	}
}

void handle_breadth_first_search(Directed_Graph *d_graph, int root = 0)
{
	try
	{
		breadth_first_search(d_graph, root);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Directed_Graph d_graph {};

	Edge edges[10] {Edge {0, 1}, Edge {1, 2}, Edge {1, 3}, Edge {3, 4}, Edge {4, 5}, Edge {4, 6}, Edge {4, 7}, Edge {5, 6}, Edge {7, 8}, Edge {8, 2}};

	handle_create_directed_graph(&d_graph, edges, 10);

	cout<<"d_graph: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	cout<<"BFS(d_graph): ";
	handle_breadth_first_search(&d_graph);
	cout<<"\n";

	handle_breadth_first_search(&d_graph, -1);
	cout<<"\n";

	return 0;
}