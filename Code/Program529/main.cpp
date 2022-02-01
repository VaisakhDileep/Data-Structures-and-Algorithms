/*
Created by  : Vaisakh Dileep
Date        : 1, February, 2022
Description : This program finds the binomial coefficient recursively using Pascal's triangle.
*/

#include<iostream>

using namespace std;

long long binomial_coefficient(long long n, long long r)
{
    if((r == 0) or (r == n)) // Base condition
    {
        return 1;
    }

    return binomial_coefficient(n - 1, r - 1) + binomial_coefficient(n - 1, r);
}

long long handle_binomial_coefficient(long long n, long long r)
{
    if((n < 0) or (r < 0))
    {
        cout<<"ERROR - Invalid operation, input values cannot be negative .....";

        return INT_MIN;
    }

    if(r > n)
    {
        cout<<"ERROR - Invalid operation, 'r' cannot exceed 'n' .....";

        return INT_MIN;
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