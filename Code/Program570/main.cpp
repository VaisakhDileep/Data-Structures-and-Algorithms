/*
Created by  : Vaisakh Dileep
Date        : 13, March, 2022
Description : This program finds the binomial coefficient(formulae).
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

// C(n, r) = n! / (r! * (n - r)!)

long long binomial_coefficient(long long n, long long r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

long long handle_binomial_coefficient(long long n, long long r)
{
    if((n < 0) or (r < 0))
    {
        cout<<"ERROR - Invalid operation, input values cannot be negative .....";

        return LLONG_MIN;
    }

    if(r > n)
    {
        cout<<"ERROR - Invalid operation, 'r' cannot exceed 'n' .....";

        return LLONG_MIN;
    }

    return binomial_coefficient(n, r);
}

int main()
{
    cout<<"binomial_coefficient(10, 2): "<<handle_binomial_coefficient(10, 2)<<"\n";

    cout<<"binomial_coefficient(2, 10): "<<handle_binomial_coefficient(2, 10)<<"\n";

    cout<<"binomial_coefficient(5, -2): "<<handle_binomial_coefficient(5, -2)<<"\n";

    cout<<"binomial_coefficient(-5, 2): "<<handle_binomial_coefficient(-5, 2)<<"\n";

    return 0;
}