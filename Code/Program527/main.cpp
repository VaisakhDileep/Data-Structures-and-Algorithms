/*
Created by  : Vaisakh Dileep
Date        : 18, December, 2021
Description : This program finds the modded factorial of a number iteratively.
*/

#include<iostream>

using namespace std;

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

long long handle_modded_factorial(long long num, long long mod)
{
    try
    {
        return modded_factorial(num, mod);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"modded_factorial(9, 11): "<<handle_modded_factorial(9, 11)<<"\n";

    return 0;
}