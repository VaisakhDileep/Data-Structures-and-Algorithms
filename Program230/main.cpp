/*
Created by  : Vaisakh Dileep
Date		: 12, June, 2021
Description : This program makes bubble sort adaptive.
*/

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

void display_array(const Array *A)
{
	if(A->A == nullptr)
	{
		cout<<"[ ]";

		return ;
	}

	cout<<"[ ";
	for(int i {0}; i < A->length; i++)
	{
		cout<<A->A[i]<<" ";
	}
	cout<<"]";
}

void bubble_sort(Array *A)
{
	bool flag {};

	for(int i {0}; i < A->size - 1; i++)
	{
		flag = false;

		for(int j {0}; j < A->size - 1 - i; j++)
		{
			if(A->A[j] > A->A[j + 1])
			{
				swap(A->A[j], A->A[j + 1]);

				flag = true;
			}
		}

		if(flag == false)
		{
			break;
		}
	}
}

void handle_bubble_sort(Array *A)
{
	try
	{
		bubble_sort(A);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {new int[6] {9, 2, 4, 10, 7, 5}, 6, 6};

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	handle_bubble_sort(&A);

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	return 0;
}