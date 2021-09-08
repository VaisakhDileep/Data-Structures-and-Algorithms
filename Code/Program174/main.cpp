/*
Created by  : Vaisakh Dileep
Date		: 31, May, 2021
Description : This program checks if a queue is empty.
*/

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
	Queue Q {new int[4] {0, 0, 0, 0}, 1, 1, 4};

	cout<<"handle_is_empty_queue(Q): "<<handle_is_empty_queue(&Q)<<"\n";

	cout<<"handle_is_empty_queue(nullptr): "<<handle_is_empty_queue(nullptr)<<"\n";

	return 0;
}