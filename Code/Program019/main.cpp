/*
Created by  : Vaisakh Dileep
Date        : 27, April, 2021
Description : This program finds the factorial of a number.
*/

#include<iostream>

using namespace std;

namespace recursion
{
    int factorial(int n)
    {
        if(n == 0)
        {
            return 1;
        }
        else
        {
            return factorial(n - 1) * n;
        }
    }
}

namespace iteration
{
    int factorial(int n)
    {
        int fact {1};

        for(int i {1}; i <= n; i++)
        {
            fact *= i;
        }

        return fact;
    }
}

int main()
{
    cout<<"factorial(5) [recursion]: "<<recursion::factorial(5)<<"\n";

    cout<<"factorial(5) [iteration]: "<<iteration::factorial(5)<<"\n";

    return 0;
}