/*
Created by  : Vaisakh Dileep
Date        : 6, December, 2021
Description : This program performs modded binary exponentiation on a number iteratively.
*/

#include<iostream>

using namespace std;

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

long long handle_modded_binary_exponentiation(long long num, long long exponent, long long mod)
{
    try
    {
        return modded_binary_exponentiation(num, exponent, mod);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"modded_binary_exponentiation(13, 10, 7): "<<handle_modded_binary_exponentiation(13, 10, 7)<<"\n";
    cout<<"modded_binary_exponentiation(13, 10, 17): "<<handle_modded_binary_exponentiation(13, 10, 17)<<"\n";

    return 0;
}