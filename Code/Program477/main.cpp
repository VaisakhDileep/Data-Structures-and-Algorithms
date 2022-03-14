/*
Created by  : Vaisakh Dileep
Date        : 16, October, 2021
Description : This program implements euclid division algorithm for finding GCD iteratively.
*/

// For proof refer "Data Strucuters and Algorithms Manual 1" pg no:2.

#include<iostream>

using namespace std;

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

long long handle_GCD(long long a, long long b)
{
    try
    {
        return GCD(a, b);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"GCD(0, 0): "<<handle_GCD(0, 0)<<"\n";

    cout<<"GCD(10, -1): "<<handle_GCD(10, -1)<<"\n";

    cout<<"GCD(7, 28): "<<handle_GCD(7, 28)<<"\n";

    cout<<"GCD(9, 100): "<<handle_GCD(9, 100)<<"\n";

    return 0;
}