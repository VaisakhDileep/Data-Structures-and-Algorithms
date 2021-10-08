/*
Created by  : Vaisakh Dileep
Date        : 8, October, 2021
Description : This program performs prime factorization on a number(O(log(n)) solution).
*/

// Creating the sieve table(for a very large value) before "prime_factorization()" will make the time complexity O(log(n)). In my implementation I create the sieve table on each call to "prime_factorization()" which could have been avoided.

#include<iostream>

#include<vector>

#include<unordered_map>

using namespace std;

vector<long long>* sieve_of_eratosthenes(long long num) // This is a custom version of "sieve_of_eratosthenes()" for the purpose of prime factorization.
{
    if(num < 0)
    {
        throw string {"ERROR - Invalid operation, input number cannot be negative ....."};
    }

    vector<long long> *table {new vector<long long>(num + 1, -1)}; // "table[i]" contains the smallest prime divisor of 'i'.

    for(long long i {2}; i * i <= num; i++)
    {
        if(table->at(i) == -1)
        {
            for(long long j {i * i}; j <= num; j += i)
            {
                if(table->at(j) == -1)
                {
                    table->at(j) = i;
                }
            }
        }
    }

    for(int i {2}; i < table->size(); i++)
    {
        if(table->at(i) == -1)
        {
            table->at(i) = i;
        }
    }

    return table;
}

unordered_map<long long, long long>* prime_factorization(long long num)
{
    if(num < 0)
    {
        throw string {"ERROR - Invalid operation, given number cannot be negative ....."};
    }

    if(num == 0)
    {
        throw string {"ERROR - Invalid operation, given number cannot be zero ....."};
    }

    if(num == 1)
    {
        throw string {"ERROR - Invalid operation, prime factorization cannot be performed for 1 ....."};
    }

    unordered_map<long long, long long> *prime_factorization {new unordered_map<long long, long long> {}};

    vector<long long> *sieve_table {sieve_of_eratosthenes(num)};

    while(num != 1)
    {
        if(prime_factorization->find(sieve_table->at(num)) != prime_factorization->end())
        {
            (*prime_factorization)[sieve_table->at(num)]++;
        }
        else
        {
            (*prime_factorization)[sieve_table->at(num)] = 1;
        }

        num /= sieve_table->at(num);
    }

    return prime_factorization;
}

unordered_map<long long, long long>* handle_prime_factorization(long long num)
{
    try
    {
        return prime_factorization(num);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

void display_prime_factorization(unordered_map<long long, long long> *prime_factorization)
{
    if(prime_factorization == nullptr)
    {
        return ;
    }

    auto itr {prime_factorization->begin()};

    if(itr != prime_factorization->end())
    {
        cout<<itr->first<<"^"<<itr->second;

        itr++;
    }

    for(; itr != prime_factorization->end(); itr++)
    {
        cout<<(" * ")<<itr->first<<"^"<<itr->second;
    }
}

int main()
{
    unordered_map<long long, long long> *prime_factorization {};

    prime_factorization = handle_prime_factorization(123);

    cout<<"1234: ";
    display_prime_factorization(prime_factorization);
    cout<<"\n"; 

    return 0;
}