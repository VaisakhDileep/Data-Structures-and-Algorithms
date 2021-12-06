/*
Created by  : Vaisakh Dileep
Date        : 5, December, 2021
Description : This program performs binary exponentiation on a number recursively.
*/

#include<iostream>

using namespace std;

long long binary_exponentiation(long long num, long long exponent)
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
        return binary_exponentiation(num * num, exponent / 2);
    }
    else
    {
        return num * binary_exponentiation(num, exponent - 1);
    }
}

long long handle_binary_exponentiation(long long num, long long exponent)
{
    if(exponent < 0)
    {
        cout<<"ERROR - Invalid operation, exponent cannot be negative .....";

        return LLONG_MIN;
    }

    return binary_exponentiation(num, exponent);
}

int main()
{
    cout<<"binary_exponentiation(12, 4): "<<handle_binary_exponentiation(12, 4)<<"\n";
    cout<<"binary_exponentiation(12, 9): "<<handle_binary_exponentiation(12, 9)<<"\n";

    return 0;
}