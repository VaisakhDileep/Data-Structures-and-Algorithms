/*
Created by  : Vaisakh Dileep
Date        : 18, December, 2021
Description : This program finds the modded factorial of a number recursively.
*/

#include<iostream>

using namespace std;

long long factorial(long long num, long long mod)
{
    if(num >= mod) // This is a special case, if "num" is greater than or equal to "mod", then "mod" will be contained inside "num"(1*2*...*mod*...*num).
    {
        return 0;
    }

    if(num == 0)
    {
        return 1;
    }

    return ((num % mod) * factorial(num - 1, mod)) % mod; // "factorial(num - 1, mod)" will always be less than 'mod'.
}

long long handle_factorial(long long num, long long mod)
{
    if(num < 0)
    {
        cout<<"ERROR - Invalid operation, given number cannot be negative .....";

        return LLONG_MIN;
    }

    return factorial(num, mod);
}

int main()
{
    cout<<"factorial(9, 11): "<<handle_factorial(9, 11)<<"\n";

    return 0;
}