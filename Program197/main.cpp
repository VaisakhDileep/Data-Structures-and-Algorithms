/*
Created by  : Vaisakh Dileep
Date		: 4, June, 2021
Description : This program checks if a circular queue is empty.
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
		throw string {"ERROR - Invalid operation, queue is not valid ....."};
	}
	
}

int main()
{
	return 0;
}