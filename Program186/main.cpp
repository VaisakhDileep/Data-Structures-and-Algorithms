/*
Created by  : Vaisakh Dileep
Date		: 1, June, 2021
Description : This program displays a queue.
*/

#include<iostream>

using namespace std;

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

void create_queue(Queue *Q, int *A, int size)
{
	if(size == 0)
	{
		return ;
	}

	Q->front = Q->rear = new Node {A[0], nullptr};

	for(int i {1}; i < size; i++)
	{
		Q->rear = Q->rear->next = new Node {A[i], nullptr};
	}
}

void display_queue(Queue *Q)
{
	if(Q == nullptr)
	{
		return ;
	}

	Node *last {Q->front};

	while(last != nullptr)
	{
		cout<<last->data<<" ";

		last = last->next;
	}
}

int main()
{
	Queue Q {};

	create_queue(&Q, new int[4] {1, 2, 3, 4}, 4);

	cout<<"Q: ";
	display_queue(&Q);
	cout<<"\n";

	return 0;
}