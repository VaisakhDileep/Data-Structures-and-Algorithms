/*
Created by  : Vaisakh Dileep
Date		: 1, June, 2021
Description : This program checks if a queue is full.
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

bool is_full_queue(Queue *Q) // The only case when the queue is full is when we run out of stack memory.
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

int main()
{
	Queue Q {};

	Q.front = Q.rear = new Node {1, nullptr};

	cout<<"is_full_queue(Q): "<<is_full_queue(&Q)<<"\n";

/*
	while(!is_full_queue(&Q)) // This might take some time. Note: It might crash in some OS.
	{
		Q.rear = Q.rear->next = new Node {1, nullptr};
	}

	cout<<"is_full_queue(Q): "<<is_full_queue(&Q)<<"\n";
*/

	return 0;
}