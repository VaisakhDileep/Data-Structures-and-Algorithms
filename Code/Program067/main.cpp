/*
Created by  : Vaisakh Dileep
Date		: 3, May, 2021
Description : This program counts the number of duplicate elements in an array.
*/

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

void count_duplicate_elements_array(Array *A)
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	int count {0};

	int flag {0};

	for(int i {0}; i < A->length; i++)
	{
		if(A->A[i] == 0)
		{
			count++;
		}
	}

	if(count > 1)
	{
		flag = 1;

		cout<<"0 appeared "<<count<<" times.\n";
	}

	for(int i {0}; i < (A->length - 1); i++)
	{
		count = 1;

		if(A->A[i] != 0)
		{
			for(int j {i + 1}; j < A->length; j++)
			{
				if(A->A[i] == A->A[j])
				{
					count++;

					A->A[j] = 0;
				}
			}

			if(count > 1)
			{
				flag = 1;

				cout<<A->A[i]<<" appeared "<<count<<" times.\n";
			}
		}
	}

	if(flag == 0)
	{
		throw string {"ERROR - Invalid operation, no duplicate elements in array ....."};
	}
}

void handle_count_duplicate_elements_array(Array *A)
{
	try
	{
		count_duplicate_elements_array(A);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {nullptr, 0, 0};

	Array B {new int[5] {1, 3, 2, 5, 4}, 5, 5};

	Array C {new int[10] {0, 1, 3, 1, 0, 4, 6, 5, 4, 4}, 10, 10};

	cout<<"count_duplicate_elements_array(A):\n";
	handle_count_duplicate_elements_array(&A);
	cout<<"\n\n";

	cout<<"count_duplicate_elements_array(B):\n";
	handle_count_duplicate_elements_array(&B);
	cout<<"\n\n";

	cout<<"count_duplicate_elements_array(C):\n";
	handle_count_duplicate_elements_array(&C);
	cout<<"\n";

	return 0;
}