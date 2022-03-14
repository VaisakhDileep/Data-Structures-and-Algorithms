/*
Created by  : Vaisakh Dileep
Date        : 14, March, 2022
Description : This program demonstrates the Euler's Totient function(brute force approach).
*/

#include<iostream>

using namespace std;

// Inorder to underestand Euler's Totient function refer "Data Structures and Algorithms Manual 1" pg no:17.

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

long long euler_s_totient_function(long long n)
{
    if(n < 0)
    {
        throw string {"ERROR - Invalid operation, 'n' cannot be a negative number ....."};
    }

    if(n == 0)
    {
        throw string {"ERROR - Invalid operation, 'n' cannot be zero ....."};
    }

    long long count {};

    for(int i {1}; i < n; i++)
    {
        if(GCD(n, i) == 1)
        {
            count++;
        }
    }

    return count;
}

long long handle_euler_s_totient_function(long long n)
{
    try
    {
        return euler_s_totient_function(n);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"euler_s_totient_function(5): "<<handle_euler_s_totient_function(5)<<"\n";

    cout<<"euler_s_totient_function(100): "<<handle_euler_s_totient_function(100)<<"\n";

    cout<<"euler_s_totient_function(-10): "<<handle_euler_s_totient_function(-10)<<"\n";

    cout<<"euler_s_totient_function(0): "<<handle_euler_s_totient_function(0)<<"\n";

    return 0;
}