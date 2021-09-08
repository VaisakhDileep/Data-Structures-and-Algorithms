/*
Created by  : Vaisakh Dileep
Date		: 2, May, 2021
Description : This program counts the number of duplicate elements in a sorted array.
*/

// sorted here means ascending order.

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

void count_duplicate_elements_sorted_array(Array *A)
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	int flag {0};

	for(int i {0}; i < (A->length - 1); i++)
	{
		if(A->A[i] == A->A[i + 1])
		{
			flag = 1;

			int j {i + 1};

			while(A->A[j] == A->A[i])
			{
				j++;
			}

			cout<<A->A[i]<<" appeared "<<(j - i)<<" times.\n";

			i = j - 1;
		}
	}

	if(flag == 0)
	{
		throw string {"ERROR - Invalid operation, no duplicate elements in array ....."};
	}
}

void handle_count_duplicate_elements_sorted_array(Array *A)
{
	try
	{
		count_duplicate_elements_sorted_array(A);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {nullptr, 0, 0};

	Array B {new int[5] {1, 2, 3, 4, 5}, 5, 5};

	Array C {new int[10] {1, 2, 2, 3, 3, 3, 3, 4, 5, 6}, 10, 10};

	cout<<"count_duplicate_elements_sorted_array(A):\n";
	handle_count_duplicate_elements_sorted_array(&A);
	cout<<"\n\n";

	cout<<"count_duplicate_elements_sorted_array(B):\n";
	handle_count_duplicate_elements_sorted_array(&B);
	cout<<"\n\n";

	cout<<"count_duplicate_elements_sorted_array(C):\n";
	handle_count_duplicate_elements_sorted_array(&C);
	cout<<"\n";

	return 0;
}