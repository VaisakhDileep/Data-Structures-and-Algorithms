/*
Created by  : Vaisakh Dileep
Date		: 16, July, 2021
Description : This program implements how_sum(target_sum, array) using tabulation.
*/

// how_sum(target_sum, array) returns an array containing any combination of numbers in the array(numbers in the array can be used as many times as needed) that add up to exactly the "target_sum". If there are multiple combinations possible, only one such combination will be returned.

// All the input numbers are non-negative.

#include<iostream>

#include<vector>

using namespace std;

void display_vector(vector<long long> *vec)
{
	if(vec == nullptr)
	{
		cout<<"[ ]";

		return ;
	}

	cout<<"[ ";
	for(unsigned long long i {0}; i < vec->size(); i++)
	{
		cout<<vec->at(i)<<" ";
	}
	cout<<"]";
}

vector<long long>* copy_vector(vector<long long> *vec)
{
	if(vec == nullptr)
	{
		return nullptr;
	}

	vector<long long> *new_vec {new vector<long long> {}};

	for(unsigned long long i {0}; i < vec->size(); i++)
	{
		new_vec->push_back(vec->at(i));
	}

	return new_vec;
}

vector<long long>* how_sum(long long target_sum, long long *A, long long size)
{
	vector<vector<long long>*> table(target_sum + 1, nullptr);

	table.at(0) = new vector<long long> {};

	for(unsigned long long i {0}; i < table.size(); i++)
	{
		if(table.at(i) != nullptr)
		{
			for(long long j {0}; j < size; j++)
			{
				unsigned long long propogate_index {i + A[j]};

				if(propogate_index < table.size())
				{
					table.at(propogate_index) = copy_vector(table.at(i));

					table.at(propogate_index)->push_back(A[j]);
				}
			}
		}
	}

	return table.at(target_sum);
}

int main()
{
	vector<long long> *result {};

	cout<<"how_sum(30, new long long[4] {8, 4, 2, 1}, 4): ";

	result = how_sum(30, new long long[4] {8, 4, 2, 1}, 4);

	display_vector(result);
	cout<<"\n";

	cout<<"how_sum(1000, new long long[2] {7, 14}, 2): ";

	result = how_sum(1000, new long long[2] {7, 14}, 2); // Notice here we get the result without any delay.

	display_vector(result);
	cout<<"\n";

	return 0;
}