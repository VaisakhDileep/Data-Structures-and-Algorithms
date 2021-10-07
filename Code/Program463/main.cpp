/*
Created by  : Vaisakh Dileep
Date        : 6, October, 2021
Description : This program performs prime factorization on a number(O(n) solution).
*/

#include<iostream>

#include<unordered_map>

using namespace std;

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

    for(long long i {2}; i <= num; i++) // Worst case happens when "num" is prime(O(n)).
    {
        if((num % i) == 0)
        {
            (*prime_factorization)[i] = 0;

            while((num % i) == 0)
            {
                (*prime_factorization)[i]++;

                num /= i;
            }
        }
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

    prime_factorization = handle_prime_factorization(1234);

    cout<<"1234: ";
    display_prime_factorization(prime_factorization);
    cout<<"\n";

    return 0;
}