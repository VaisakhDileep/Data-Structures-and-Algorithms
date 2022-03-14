/*
Created by  : Vaisakh Dileep
Date        : 5, December, 2021
Description : This program performs modded binary exponentiation on a number recursively.
*/

#include<iostream>

using namespace std;

long long modded_binary_exponentiation(long long num, long long exponent, long long mod)
{
    if(exponent == 0)
    {
        return 1;
    }

    if(exponent == 1)
    {
        return num;
    }

    if(exponent % 2 == 0)
    {
        return modded_binary_exponentiation(((num % mod) * (num % mod)) % mod, exponent / 2, mod);
    }
    else
    {
        return ((num % mod) * (modded_binary_exponentiation(num, exponent - 1, mod) % mod)) % mod;
    }
}

long long handle_modded_binary_exponentiation(long long num, long long exponent, long long mod)
{
    if(exponent < 0)
    {
        cout<<"ERROR - Invalid operation, exponent cannot be negative .....";

        return LLONG_MIN;
    }

    if(mod < 0)
    {
        cout<<"ERROR - Invalid operation, 'mod' value cannot be negative .....";

        return LLONG_MIN;
    }

    return  modded_binary_exponentiation(num, exponent, mod);
}

int main()
{
    cout<<"modded_binary_exponentiation(12, 4, 7): "<<handle_modded_binary_exponentiation(12, 4, 7)<<"\n";

    cout<<"modded_binary_exponentiation(12, 9, 17): "<<handle_modded_binary_exponentiation(12, 9, 17)<<"\n";

    return 0;
}