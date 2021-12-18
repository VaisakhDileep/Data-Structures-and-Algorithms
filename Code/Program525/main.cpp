/*
Created by  : Vaisakh Dileep
Date        : 18, December, 2021
Description : This program finds the factorial of a number iteratively.
*/

#include<iostream>

using namespace std;

long long factorial(long long num)
{
    if(num < 0)
    {
        throw string {"ERROR - Invalid operation, given number cannot be negative ....."};
    }

    int factorial {1};

    for(int i {2}; i <= num; i++)
    {
        factorial *= i;
    }

    return factorial;
}

long long handle_factorial(long long num)
{
    try
    {
        return factorial(num);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN;
    }
}

int main()
{
    cout<<"factorial(10): "<<handle_factorial(10)<<"\n";

    return 0;
}