/*
Created by  : Vaisakh Dileep
Date        : 17, December, 2021
Description : This program counts the number of divisors of a number using prime factorization.
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

// Building principle: If 'n' is a composite number, then there is at least one prime divisor of 'n' that is <= sqrt('n').

    for(long long i {2}; i * i <= num; i++) // Worst case happens when "num" is prime(O(sqrt(n))).
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

    if(num > 1) // If it's a prime number.
    {
        (*prime_factorization)[num] = 1;
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

long long count_number_of_divisors(long long num)
{
    if(num < 0)
    {
        throw string {"ERROR - Invalid operation, input number should not be negative ....."};
    }

    if(num == 0)
    {
        throw string {"ERROR - Invalid operation, input number cannot be zero ....."};
    }

    if(num == 1)
    {
        return 1;
    }

    unordered_map<long long, long long> *prime_factorization {handle_prime_factorization(num)};

    long long divisor_count {1};

    for(auto itr {prime_factorization->begin()}; itr != prime_factorization->end(); itr++)
    {
        divisor_count *= (itr->second + 1);
    } // Inorder to understand how to count the number of divisors from prime factorization refer: "Data Structures and Algorithms Manual 1" pg no:12.

    return divisor_count;
}

long long handle_count_number_of_divisors(long long num)
{
    try
    {
        return count_number_of_divisors(num);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"number of divisors of 1000: "<<handle_count_number_of_divisors(1000)<<"\n";

    return 0;
}