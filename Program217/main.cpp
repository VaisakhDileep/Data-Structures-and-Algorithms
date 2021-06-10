/*
Created by  : Vaisakh Dileep
Date		: 9, June, 2021
Description : This program displays a binary tree using level-order traversal using queue.
*/

#include<iostream>

using namespace std;

struct Node;

namespace queue
{
	struct Node
	{
		::Node *data;

		Node *next;
	};

	struct Queue
	{
		Node *front {nullptr};

		Node *rear {nullptr};
	};

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

	bool is_full_queue(Queue *Q)
	{
		Node *temp = new Node {nullptr, nullptr};

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

	void enqueue(Queue *Q, ::Node *value)
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

	::Node* dequeue(Queue *Q)
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
			::Node* deleted_value {Q->front->data};

			Node *temp {Q->front}; // To delete the dynamically allocated memory.

			Q->front = Q->front->next;

			if(Q->front == nullptr)
			{
				Q->rear = nullptr;
			}

			delete temp;

			return deleted_value;
		}
	}
}

struct Node
{
	Node *left_child;

	int data;

	Node *right_child;
};

struct Binary_Tree
{
	Node *root;
};

void create_binary_tree(Node **node, int i, int *A, int size)
{
	if((i < size) and (A[i] != INT_MIN))
	{
		*node = new Node {nullptr, A[i], nullptr};

		create_binary_tree(&((*node)->left_child), (2 * (i + 1)) - 1, A, size);

		create_binary_tree(&((*node)->right_child), 2 * (i + 1), A, size);
	}
}

void handle_create_binary_tree(Binary_Tree *T, int *A, int size)
{
	create_binary_tree(&(T->root), 0, A, size);
}

void display_binary_tree(Binary_Tree *T) // level-order traversal
{
	if((T == nullptr) or (T->root == nullptr))
	{
		return ;
	}

	queue::Queue Q {};

	Node *node {T->root};

	cout<<node->data<<" ";

	queue::enqueue(&Q, node);

	while(!queue::is_empty_queue(&Q))
	{
		node = queue::dequeue(&Q);

		if(node->left_child != nullptr)
		{
			cout<<node->left_child->data<<" ";

			queue::enqueue(&Q, node->left_child);
		}

		if(node->right_child != nullptr)
		{
			cout<<node->right_child->data<<" ";

			queue::enqueue(&Q, node->right_child);
		}
	}
}

int main()
{
	Binary_Tree T {};

	handle_create_binary_tree(&T, new int[6] {1, 2, 3, INT_MIN, 4, 5}, 6);

	cout<<"T[level-order]: ";
	display_binary_tree(&T);
	cout<<"\n";

	return 0;
}