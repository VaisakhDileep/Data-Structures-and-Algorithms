/*
Created by  : Vaisakh Dileep
Date		: 31, May, 2021
Description : This program resets a queue.
*/

// Note: Reseting only happens when the queue is empty.

#include<iostream>

using namespace std;

struct Queue
{
	int *A {nullptr};

	int front {-1};

	int rear {-1};

	int size {0};
};

bool is_empty_queue(Queue *Q)
{
	if(Q == nullptr)
	{
		throw string {"ERROR - Invalid operation, queue is not valid ....."};
	}

	if(Q->front == Q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void reset_queue(Queue *Q)
{
	if(Q == nullptr)
	{
		throw string {"ERROR - Invalid operation, queue is not valid ....."};
	}

	if(!is_empty_queue(Q))
	{
		throw string {"ERROR - Invalid operation, queue is not empty ....."};
	}

	Q->front = Q->rear = -1;
}

void handle_reset_queue(Queue *Q)
{
	try
	{
		reset_queue(Q);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Queue Q {new int[4] {1, 2, 3, 4}, 2, 2, 4};

	handle_reset_queue(&Q);

	return 0;
}