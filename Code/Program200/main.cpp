/*
Created by  : Vaisakh Dileep
Date		: 4, June, 2021
Description : This program inserts an element to a circular queue.
*/

#include<iostream>

using namespace std;

struct Circular_Queue
{
	int *A {nullptr};

	int front {0};

	int rear {0};

	int size {0};
};

bool is_empty_circular_queue(Circular_Queue *Q)
{
	if(Q == nullptr)
	{
		throw string {"ERROR - Invalid operation, circular queue is not valid ....."};
	}

	if((Q->A == nullptr) or (Q->front == Q->rear))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void display_circular_queue(Circular_Queue *Q)
{
	if((Q == nullptr) or (Q->A == nullptr))
	{
		return ;
	}
	else if(is_empty_circular_queue(Q))
	{
		return ;
	}
	else
	{
		int i {Q->front + 1};

		do
		{
			cout<<Q->A[i]<<" ";

			i = (i + 1) % Q->size;

		} while(i != (Q->rear + 1) % Q->size);
	}
}

bool is_full_circular_queue(Circular_Queue *Q)
{
	if(Q == nullptr)
	{
		throw string {"ERROR - Invalid operation, circular queue is not valid ....."};
	}

	if(Q->A == nullptr)
	{
		return false;
	}

	if(((Q->rear + 1) % Q->size) == Q->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void insert_circular_queue(Circular_Queue *Q, int value)
{
	if(Q == nullptr)
	{
		throw string {"ERROR - Invalid operation, circular queue is not valid ....."};
	}

	if(is_full_circular_queue(Q))
	{
		throw string {"ERROR - Invalid operation, circular queue is full ....."};
	}

	Q->rear = (Q->rear + 1) % Q->size;

	Q->A[Q->rear] = value;
}

void handle_insert_circular_queue(Circular_Queue *Q, int value)
{
	try
	{
		insert_circular_queue(Q, value);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Circular_Queue Q {new int[4] {}, 0, 0, 4};

	handle_insert_circular_queue(&Q, 1);
	handle_insert_circular_queue(&Q, 2);
	handle_insert_circular_queue(&Q, 3);

	cout<<"Q: ";
	display_circular_queue(&Q);
	cout<<"\n";

	handle_insert_circular_queue(&Q, 4);
	cout<<"\n";

	return 0;
}