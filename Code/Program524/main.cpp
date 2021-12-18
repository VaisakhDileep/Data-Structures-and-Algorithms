/*
Created by  : Vaisakh Dileep
Date        : 18, December, 2021
Description : This program finds the factorial of a number recursively.
*/

#include<iostream>

using namespace std;

long long factorial(long long num)
{
    if(num == 0)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

long long handle_factorial(long long num)
{
    if(num < 0)
    {
        cout<<"ERROR - Invalid operation, given number cannot be negative .....";

        return LLONG_MIN;
    }

    return factorial(num);
}

int main()
{
    cout<<"factorial(10): "<<handle_factorial(10)<<"\n";

    return 0;
}