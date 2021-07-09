/*
Created by  : Vaisakh Dileep
Date		: 9, July, 2021
Description : This program demonstrates breadth first search for a weighed undirected graph represented using adjacency matrix.
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

namespace Weighed_Undirected_Graph_Using_Adjacency_Matrix // Weighed Undirected Graph is designed using Adjacency Matrix representation.
{
	struct Weighed_Undirected_Graph
	{
		int **A;

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
			cout<<"[\n]";

			return ;
		}

		cout<<"[\n     ";
		for(int i {0}; i < wu_graph->n; i++)
		{
			cout<<setw(3)<<i<<" ";
		}
		cout<<"\n";

		for(int i {0}; i < wu_graph->n; i++)
		{
			cout<<setw(3)<<left<<i<<right<<"[ ";
			for(int j {0}; j < wu_graph->n; j++)
			{
				cout<<setw(3)<<wu_graph->A[i][j]<<" ";
			}
			cout<<"]\n";
		}
		cout<<"]";
	}

	void delete_weighed_undirected_graph(Weighed_Undirected_Graph *u_graph)
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

	void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
	{
		if(wu_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
		{
			throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
		}

		if((w_edge.vertex_1 < wu_graph->n) and (w_edge.vertex_2 < wu_graph->n))
		{
			wu_graph->A[w_edge.vertex_1][w_edge.vertex_2] = wu_graph->A[w_edge.vertex_2][w_edge.vertex_1] = w_edge.weight;
		}
		else
		{
			int new_n {(w_edge.vertex_1 > w_edge.vertex_2) ? w_edge.vertex_1 + 1 : w_edge.vertex_2 + 1};

			Weighed_Undirected_Graph temp {new int*[new_n] {}, new_n};

			for(int i {0}; i < new_n; i++)
			{
				temp.A[i] = new int[new_n] {};
			}

			for(int i {0}; i < wu_graph->n; i++)
			{
				for(int j {0}; j < wu_graph->n; j++)
				{
					temp.A[i][j] = wu_graph->A[i][j];
				}
			}

			temp.A[w_edge.vertex_1][w_edge.vertex_2] = temp.A[w_edge.vertex_2][w_edge.vertex_1] = w_edge.weight;

			delete_weighed_undirected_graph(wu_graph);

			wu_graph->A = temp.A;

			wu_graph->n = temp.n;
		}
	}

	void create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
	{
		if(wu_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		for(int i {0}; i < num_edges; i++)
		{
			try
			{
				add_edge_weighed_undirected_graph(wu_graph, w_edges[i]);
			}
			catch(string &ex)
			{
				throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
			}
		}
	}

	void handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
	{
		try
		{
			create_weighed_undirected_graph(wu_graph, w_edges, num_edges);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

using namespace Weighed_Undirected_Graph_Using_Adjacency_Matrix;

using namespace Queue_Using_Linked_list;

void breadth_first_search(Weighed_Undirected_Graph *wu_graph, int root)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if(root < 0)
	{
		throw string {"ERROR - Invalid root vertex, vertex cannot be negative ....."};
	}

	cout<<root<<" ";

	int *visited = new int[wu_graph->n] {0};

	visited[root] = 1;

	Queue Q {};

	handle_enqueue(&Q, root);

	while(!is_empty_queue(&Q))
	{
		int node {handle_dequeue(&Q)};

		for(int i {0}; i < wu_graph->n; i++)
		{
			if((wu_graph->A[node][i] != 0) and (visited[i] == 0))
			{
				cout<<i<<" ";

				visited[i] = 1;

				handle_enqueue(&Q, i);
			}
		}
	}
}

void handle_breadth_first_search(Weighed_Undirected_Graph *wu_graph, int root = 0)
{
	try
	{
		breadth_first_search(wu_graph, root);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {};

	Weighed_Edge w_edges[9] {Weighed_Edge {0, 1, 10}, Weighed_Edge {0, 2, 20}, Weighed_Edge {0, 3, 30}, Weighed_Edge {1, 2, 40}, Weighed_Edge {3, 4, 50}, Weighed_Edge {2, 4, 60}, Weighed_Edge {4, 5, 70}, Weighed_Edge {4, 6, 80}, Weighed_Edge {3, 2, 90}};

	handle_create_weighed_undirected_graph(&wu_graph, w_edges, 9);

	cout<<"wu_graph: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	cout<<"BFS(wu_graph): ";
	handle_breadth_first_search(&wu_graph);
	cout<<"\n";

	handle_breadth_first_search(&wu_graph, -1);
	cout<<"\n";

	return 0;
}