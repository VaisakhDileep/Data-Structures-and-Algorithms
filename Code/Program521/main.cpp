/*
Created by  : Vaisakh Dileep
Date        : 12, December, 2021
Description : This program finds all the divisors of a number(O(n) solution).
*/

#include<iostream>

#include<vector>

using namespace std;

vector<int>* extract_divisors(long long num)
{
    if(num < 0)
    {
        throw string {"ERROR - Invalid operation, input number should not be negative ....."};
    }

    if(num == 0)
    {
        throw string {"ERROR - Invalid operation, input number cannot be zero ....."};
    }

    vector<int> *divisors {new vector<int> {}};

    for(int i {1}; i <= num; i++)
    {
        if(num % i == 0)
        {
            divisors->push_back(i);
        }
    }

    return divisors;
}

vector<int>* handle_extract_divisors(long long num)
{
    try
    {
        return extract_divisors(num);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

void display_divisors(vector<int> *divisors)
{
    if(divisors == nullptr)
    {
        return ;
    }

    for(int i {0}; i < divisors->size(); i++)
    {
        cout<<divisors->at(i)<<" ";
    }
}

int main()
{
    vector<int> *divisors {handle_extract_divisors(1000)};

    cout<<"divisors of 1000: ";
    display_divisors(divisors);
    cout<<"\n";

    return 0;
}