/*
Created by  : Vaisakh Dileep
Date        : 6, October, 2021
Description : This program checks if the given number is prime(O(n) solution).
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

    for(long long i {2}; i < num; i++) // Do not include "num" in the loop.
    {
        if((num % i) == 0)
        {
            return false;
        }
    }

    return true;
}

bool handle_is_prime(long long num)
{
    try
    {
        return is_prime(num);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    cout<<"is_prime(1): "<<is_prime(1)<<"\n";

    cout<<"is_prime(2): "<<is_prime(2)<<"\n";

    cout<<"is_prime(3): "<<is_prime(3)<<"\n";

    cout<<"is_prime(10): "<<is_prime(10)<<"\n";

    cout<<"is_prime(113): "<<is_prime(113)<<"\n";

    cout<<"is_prime(1000000000000000001): "<<is_prime(1000000000000000001)<<"\n";

    return 0;
}