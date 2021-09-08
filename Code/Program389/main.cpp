/*
Created by  : Vaisakh Dileep
Date		: 13, August, 2021
Description : This program performs the range sum query operation on a prefix sum matrix(2-D array).
*/

// This will only work for static matrices(matrix data cannot be changed).

#include<iostream>

#include<vector>

using namespace std;

vector<vector<int>*>* create_prefix_sum_matrix(vector<vector<int>*> *input_matrix)
{
	if(input_matrix == nullptr)
	{
		throw string {"ERROR - Invalid operation, input matrix is not valid ....."};
	}

	if((input_matrix->at(0) == nullptr) or (input_matrix->at(0)->size() == 0))
	{
		throw string {"ERROR - Invalid operation, input matrix is empty ....."};
	}

	vector<vector<int>*> *prefix_sum {new vector<vector<int>*>(input_matrix->size() + 1, nullptr)};

	for(int i {0}; i < prefix_sum->size(); i++)
	{
		prefix_sum->at(i) = new vector<int>(input_matrix->at(0)->size() + 1, 0);
	}

	for(int i {1}; i < prefix_sum->size(); i++)
	{
		for(int j {1}; j < prefix_sum->at(0)->size(); j++)
		{
			prefix_sum->at(i)->at(j) = prefix_sum->at(i - 1)->at(j) + prefix_sum->at(i)->at(j - 1) + input_matrix->at(i - 1)->at(j - 1) - prefix_sum->at(i - 1)->at(j - 1);
		}
	}

	return prefix_sum;
}

vector<vector<int>*>* handle_create_prefix_sum_matrix(vector<vector<int>*> *input_matrix)
{
	try
	{
		return create_prefix_sum_matrix(input_matrix);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int range_sum_query_prefix_sum_matrix(pair<int, int> query_start, pair<int, int> query_end, vector<vector<int>*> *prefix_sum) // Both "query_start" and "query_end" are inclusive.
{
	if(prefix_sum == nullptr)
	{
		throw string {"ERROR - Invalid operation, prefix sum matrix is not valid ....."};
	}

	if((prefix_sum->at(0) == nullptr) or (prefix_sum->at(0)->size() == 0))
	{
		throw string {"ERROR - Invalid operation, prefix sum matrix is empty ....."};
	}

	if((query_start.first < 0) or (query_start.second < 0) or (query_end.first < 0) or (query_end.second < 0))
	{
		throw string {"ERROR - Invalid operation, indices cannot be negative ....."};
	}

	if((query_start.first >= prefix_sum->size()) or (query_start.second >= prefix_sum->at(0)->size()) or (query_end.first >= prefix_sum->size()) or (query_end.second >= prefix_sum->at(0)->size()))
	{
		throw string {"ERROR - Invalid operation, index exceeds the size of the prefix sum matrix ....."};
	}

	if((query_start.first > query_end.second) or (query_start.second > query_end.second))
	{
		throw string {"ERROR - Invalid operation, start index cannot exceed the end index ....."};
	}

	return prefix_sum->at(query_end.first + 1)->at(query_end.second + 1) - prefix_sum->at(query_start.first)->at(query_end.second + 1) - prefix_sum->at(query_end.first + 1)->at(query_start.second) + prefix_sum->at(query_start.first)->at(query_start.second);
}

int handle_range_sum_query_prefix_sum_matrix(pair<int, int> query_start, pair<int, int> query_end, vector<vector<int>*> *prefix_sum)
{
	try
	{
		return range_sum_query_prefix_sum_matrix(query_start, query_end, prefix_sum);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	vector<vector<int>*> *input_matrix {new vector<vector<int>*> {new vector<int> {2, 0, -3, 4}, new vector<int> {6, 3, 2, -1}, new vector<int> {5, 4, 7, 3}, new vector<int> {2, -6, 8, 1}}};

	vector<vector<int>*> *prefix_sum {handle_create_prefix_sum_matrix(input_matrix)};

	cout<<"handle_range_sum_query_perfix_sum_matrix({0, 0}, {0, 0}, prefix_sum): "<<handle_range_sum_query_prefix_sum_matrix({1, 1}, {2, 3}, prefix_sum)<<"\n";

	return 0;
}