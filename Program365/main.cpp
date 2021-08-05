/*
Created by  : Vaisakh Dileep
Date		: 4, August, 2021
Description : This program implements Kadane's largest sum contiguous subarray algorithm.
*/

#include<iostream>

using namespace std;

int largest_sum_contiguous_subarray(int *A, int size) // Kadane's algorithm.
{
	if(A == nullptr)
	{
		throw string {"ERROR - Invalid operation, given array is not valid ....."};
	}

	int sum_so_far {INT_MIN}, current_sum {0};

	for(int i {0}; i < size; i++)
	{
		current_sum += A[i];

		if(current_sum < A[i])
		{
			current_sum = A[i];
		}

		if(sum_so_far < current_sum)
		{
			sum_so_far = current_sum;
		}
	}

	return sum_so_far;
}

int handle_largest_sum_contiguous_subarray(int *A, int size)
{
	try
	{
		return largest_sum_contiguous_subarray(A, size);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	cout<<"handle_largest_sum_contiguous_subarray(new int[6] {-1, 2, -5, -4, 2, 3}, 6): "<<handle_largest_sum_contiguous_subarray(new int[6] {-1, 2, -5, -4, 2, 3}, 6)<<"\n";

	return 0;
}