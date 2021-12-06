/*
Created by  : Vaisakh Dileep
Date        : 7, October, 2021
Description : This program performs binary exponentiation on a number iteratively.
*/

#include<iostream>

using namespace std;

long long binary_exponentiation(long long num, long long exponent)
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
            result *= num;

            exponent--;
        }
        else
        {
            num *= num;

            exponent /= 2;
        }
    }

    return result;
}

long long handle_binary_exponentiation(long long num, long long exponent)
{
    try
    {
        return binary_exponentiation(num, exponent);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"binary_exponentiation(13, 10): "<<handle_binary_exponentiation(13, 10)<<"\n";
    cout<<"binary_exponentiation(13, 17): "<<handle_binary_exponentiation(13, 17)<<"\n";

    return 0;
}