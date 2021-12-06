/*
Created by  : Vaisakh Dileep
Date        : 5, December, 2021
Description : This program finds the modulo multiplicative inverse(Fermat's little theorem).
*/

#include<iostream>

#include<math.h>

using namespace std;

bool is_prime(long long num)
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
        return false;
    }

    for(long long i {2}; i*i <= num; i++)
    {
        if((num % i) == 0)
        {
            return false;
        }
    }

    return true;
}

long long GCD(long long a, long long b) // Using Euclid Division algorithm.
{
    if((a == 0) and (b == 0))
    {
        throw string {"ERROR - Invalid operation, GCD(0, 0) is not defined ....."};
    }

    if((a < 0) or (b < 0))
    {
        throw string {"ERROR - Invalid operation, arguments provided to GCD() should be non-negative ....."};
    }

    while(b != 0)
    {
        long long temp {b};

        b = a % b;

        a = temp;
    }

    return a;
}

long long modded_binary_exponentiation(long long num, long long exponent, long long mod)
{
    if(exponent < 0)
    {
        throw string {"ERROR - Invalid operation, exponent cannot be negative ....."};
    }

    long long result {1};

    while(exponent)
    {
        if((exponent % 2) == 1)
        {
            result = ((result % mod) * (num % mod)) % mod;

            exponent--;
        }
        else
        {
            num = ((num % mod) * (num % mod)) % mod;

            exponent /= 2;
        }
    }

    return result;
}

// Inorder to understand Fermat's little theorem refer "Data Structures and Algorithms Manual 1" pg no:11.

long long modulo_multiplicative_inverse(long long a, long long p)
{
    if((a == 0) or (p == 0))
    {
        throw string {"ERROR - Invalid operation, 'a' and 'p' cannot be zero ....."};
    }

    if((a < 0) or (p < 0))
    {
        throw string {"ERROR - Invalid operation, 'a' and 'p' cannot be negative ....."};
    }

// This method will only work if 'p' is a prime number and 'p' does not divide 'a'.

    if(!is_prime(p))
    {
        throw string {"ERROR - Invalid operation, Fermat's little theoram will only work if 'p' is a prime number ....."};
    }

    if(GCD(a, p) != 1)
    {
        throw string {"ERROR - Invalid opeartion, Fermat's little theoram will only work if 'a' and 'p' are relative primes ....."};
    }

    return modded_binary_exponentiation(a, p - 2, p);
}

long long handle_modulo_multiplicative_inverse(long long a, long long p)
{
    try
    {
        return modulo_multiplicative_inverse(a, p);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"modulo_multiplicative_inverse(10, 3): "<<handle_modulo_multiplicative_inverse(10, 3)<<"\n";
    cout<<"modulo_multiplicative_inverse(12, 7): "<<handle_modulo_multiplicative_inverse(12, 7)<<"\n";

    return 0;
}