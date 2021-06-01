/*
Created by  : Vaisakh Dileep
Date		: 1, June, 2021
Description : This program checks if a queue is empty.
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

bool handle_is_empty_queue(Queue *Q)
{
	try
	{
		return is_empty_queue(Q);
	}
	catch(string &ex)
	{
		cout<<ex;

		return false;
	}
}

int main()
{
	Queue Q {};

	cout<<"handle_is_empty_queue(Q): "<<handle_is_empty_queue(&Q)<<"\n";

	Q.front = Q.rear = new Node {1, nullptr};

	cout<<"handle_is_empty_queue(Q): "<<handle_is_empty_queue(&Q)<<"\n";

	return 0;
}