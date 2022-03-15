/*
Created by  : Vaisakh Dileep
Date        : 15, March, 2022
Description : This program demonstrates the Euler's Totient function(O(sqrt(n) approach)).
*/

#include<iostream>

using namespace std;

// Inorder to understand Euler's Totient function refer "Data Structures and Algorithms Manual 1" pg no:17.

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

    long long count {n};

    for(long long i {2}; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            count *= (i - 1);

            count /= i;

            while(n % i == 0)
            {
                n /= i;
            }
        }
    }

    if(n > 1)
    {
        count *= (n - 1);

        count /= n;
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