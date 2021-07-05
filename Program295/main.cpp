/*
Created by  : Vaisakh Dileep
Date		: 1, July, 2021
Description : This program demonstrates breadth first search for an undirected graph represented using adjacency list.
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

namespace Undirected_Graph_Using_Adjacency_List // Undirected Graph is designed using Adjacency List representation.
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
			if(u_graph->A[edge.vertex_1] == nullptr)
			{
				u_graph->A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
			}
			else
			{
				Node *last {u_graph->A[edge.vertex_1]->head}, *previous_node {};

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

			if(u_graph->A[edge.vertex_2] == nullptr)
			{
				u_graph->A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, nullptr}};
			}
			else
			{
				Node *last {u_graph->A[edge.vertex_2]->head}, *previous_node {};

				while(last != nullptr)
				{
					previous_node = last;

					if(last->vertex == edge.vertex_1)
					{
						throw string {"ERROR - Invalid operation, edge is already present in the graph ....."};
					}

					last = last->next;
				}

				previous_node->next = new Node {edge.vertex_1, nullptr};
			}
		}
		else
		{
			int new_n {edge.vertex_1 > edge.vertex_2 ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

			Undirected_Graph temp {new Linked_list*[new_n] {}, new_n};

			for(int i {0}; i < u_graph->n; i++)
			{
				temp.A[i] = u_graph->A[i];
			}

			if(temp.A[edge.vertex_1] == nullptr)
			{
				temp.A[edge.vertex_1] = new Linked_list {new Node {edge.vertex_2, nullptr}};
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

				previous_node->next = new Node {edge.vertex_2, nullptr};
			}

			if(temp.A[edge.vertex_2] == nullptr)
			{
				temp.A[edge.vertex_2] = new Linked_list {new Node {edge.vertex_1, nullptr}};
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

				previous_node->next = new Node {edge.vertex_1, nullptr};
			}

			u_graph->A = temp.A;

			temp.A = nullptr;

			u_graph->n = temp.n;
		}
	}

	void create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
	{
		if(u_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		for(int i {0}; i < num_edges; i++)
		{
			try
			{
				add_edge_undirected_graph(u_graph, edges[i]);
			}
			catch(string &ex)
			{
				throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
			}
		}
	}

	void handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
	{
		try
		{
			create_undirected_graph(u_graph, edges, num_edges);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

using namespace Undirected_Graph_Using_Adjacency_List;

using namespace Queue_Using_Linked_list;

void breadth_first_search(Undirected_Graph *u_graph, int root)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if(root < 0)
	{
		throw string {"ERROR - Invalid root vertex, vertex cannot be negative ....."};
	}

	cout<<root<<" ";

	int *visited = new int[u_graph->n] {0};

	visited[root] = 1;

	Queue Q {};

	handle_enqueue(&Q, root);

	while(!is_empty_queue(&Q))
	{
		int node {handle_dequeue(&Q)};

		Undirected_Graph_Using_Adjacency_List::Node *last {u_graph->A[node]->head};

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

void handle_breadth_first_search(Undirected_Graph *u_graph, int root = 0)
{
	try
	{
		breadth_first_search(u_graph, root);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {};

	Edge edges[9] {Edge {0, 1}, Edge {0, 2}, Edge {0, 3}, Edge {1, 2}, Edge {3, 4}, Edge {2, 4}, Edge {4, 5}, Edge {4, 6}, Edge {3, 2}};

	handle_create_undirected_graph(&u_graph, edges, 9);

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	cout<<"BFS(u_graph): ";
	handle_breadth_first_search(&u_graph);
	cout<<"\n";

	handle_breadth_first_search(&u_graph, -1);
	cout<<"\n";

	return 0;
}