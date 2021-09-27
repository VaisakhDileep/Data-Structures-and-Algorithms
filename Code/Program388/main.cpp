/*
Created by  : Vaisakh Dileep
Date        : 12, August, 2021
Description : This program creates a prefix sum matrix for range sum query(2-D array).
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

int main()
{
    vector<vector<int>*> *input_matrix {new vector<vector<int>*> {new vector<int> {2, 0, -3, 4}, new vector<int> {6, 3, 2, -1}, new vector<int> {5, 4, 7, 3}, new vector<int> {2, -6, 8, 1}}};

    vector<vector<int>*> *prefix_sum {handle_create_prefix_sum_matrix(input_matrix)};

    return 0;
}