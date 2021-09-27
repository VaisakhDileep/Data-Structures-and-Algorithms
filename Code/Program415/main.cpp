/*
Created by  : Vaisakh Dileep
Date        : 6, September, 2021
Description : This program demonstrates Sieve of Eratosthenes algorithm.
*/

// Sieve of Eratosthenes algorithm is used to find all the prime numbers smaller than or equal to 'n'.

#include<iostream>

#include<vector>

using namespace std;

vector<int>* sieve_of_eratosthenes_algorithm(int num)
{
    if(num < 0)
    {
        throw string {"ERROR - Invalid operation, input number cannot be negative ....."};
    }

    vector<int>* result {new vector<int> {}};

    vector<bool> table(num + 1, true);

    table[0] = false;
    table[1] = false;

    for(int i {2}; i * i <= num; i++)
    {
        if(table[i] == true)
        {
            for(int j {i * i}; j <= num; j += i)
            {
                table[j] = false;
            }
        }
    }

    for(int i {0}; i <= num; i++)
    {
        if(table[i] == true)
        {
            result->push_back(i);
        }
    }

    return result;
}

vector<int>* handle_sieve_of_eratosthenes_algorithm(int num)
{
    try
    {
        return sieve_of_eratosthenes_algorithm(num);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

int main()
{
    vector<int> *result {handle_sieve_of_eratosthenes_algorithm(10)};

    cout<<"handle_sieve_of_eratosthenes_algorithm(10): ";
    for(int i {0}; i < result->size(); i++)
    {
        cout<<result->at(i)<<" ";
    }
    cout<<"\n";

    return 0;
}