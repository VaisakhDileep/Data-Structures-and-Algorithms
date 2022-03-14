/*
Created by  : Vaisakh Dileep
Date        : 13, March, 2022
Description : This program finds the modded binomial coefficient following Fermat's little theorem(formulae).
*/

#include<iostream>

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

long long modded_factorial(long long num, long long mod)
{
    if(num < 0)
    {
        throw string {"ERROR - Invalid operation, given number cannot be negative ....."};
    }

    if(mod < 0)
    {
        throw string {"ERROR - Invalid operation, 'mod' value cannot be negative ....."};
    }

    if(num >= mod) // This is a special case, if "num" is greater than or equal to "mod", then "mod" will be contained inside "num"(1*2*...*mod*...*num).
    {
        return 0;
    }

    long long factorial {1};

    for(long long i {2}; i <= num; i++)
    {
        factorial = (factorial * i) % mod; // "factorial" and "i" are lesser than "mod".
    }

    return factorial;
}

long long modded_binary_exponentiation(long long num, long long exponent, long long mod)
{
    if(exponent < 0)
    {
        throw string {"ERROR - Invalid operation, exponent cannot be negative ....."};
    }

    if(mod < 0)
    {
        throw string {"ERROR - Invalid operation, 'mod' value cannot be negative ....."};
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

// Inorder to get the formulae refer "Data Structures and Algorithms Manual 1" pg no:13.

long long modded_binomial_coefficient(long long n, long long r, long long mod)
{
    if((n < 0) or (r < 0))
    {
        throw string {"ERROR - Invalid operation, input values cannot be negative ....."};
    }

    if(r > n)
    {
        throw string {"ERROR - Invalid operation, 'r' cannot exceed 'n' ....."};
    }

    if(mod < 0)
    {
        throw string {"ERROR - Invalid operation, 'mod' value cannot be negative ....."};
    }

    if(is_prime(mod) == false)
    {
        throw string {"ERROR - Invalid operation, Fermat's little theoram will only work if 'mod' is a prime number ....."};
    }

    if((modded_factorial(r, mod) * modded_factorial(n - r, mod)) % mod == 0)
    {
        throw string {"ERROR - Invalid operation, Fermat's little theoram will only work if 'mod' and 'r! * (n - r)!' are relative primes ....."};
    }

    long long first_term {modded_factorial(n, mod)};

    long long second_term {modded_binary_exponentiation(modded_factorial(r, mod), mod - 2, mod)};

    long long third_term {modded_binary_exponentiation(modded_factorial(n - r, mod), mod - 2, mod)};

    return (((first_term * second_term) % mod) * third_term) % mod;
}

long long handle_modded_binomial_coefficient(long long n, long long r, long long mod)
{
    try
    {
        return modded_binomial_coefficient(n, r, mod);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"modded_binomial_coefficient(10, 2, 11): "<<handle_modded_binomial_coefficient(10, 2, 11)<<"\n";

    cout<<"modded_binomial_coefficient(10, 2, -11): "<<handle_modded_binomial_coefficient(10, 2, -11)<<"\n";

    cout<<"modded_binomial_coefficient(2, 10, 11): "<<handle_modded_binomial_coefficient(2, 10, 11)<<"\n";

    cout<<"modded_binomial_coefficient(5, -2, 11): "<<handle_modded_binomial_coefficient(-2, 5, 11)<<"\n";

    cout<<"modded_binomial_coefficient(-5, 2, 11): "<<handle_modded_binomial_coefficient(-5, 2, 11)<<"\n";

    return 0;
}