/*
Created by  : Vaisakh Dileep
Date		: 31, May, 2021
Description : This program displays a queue.
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

void display_queue(Queue *Q)
{
	if(Q == nullptr)
	{
		throw string {"ERROR - Invalid operation, queue is not valid ....."};
	}

	for(int i {Q->front + 1}; i <= Q->rear; i++)
	{
		cout<<Q->A[i]<<" ";
	}
}

int main()
{
	Queue Q {new int[4] {0, 2, 3, 4}, 0, 3, 4};

	cout<<"Q: ";
	display_queue(&Q);
	cout<<"\n";

	return 0;
}