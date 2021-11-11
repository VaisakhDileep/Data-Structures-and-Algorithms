/*
Created by  : Vaisakh Dileep
Date        : 16, October, 2021
Description : This program implements euclid division algorithm for finding GCD recursively.
*/

// For proof refer "Data Structures and Algorithms Manual 1" pg no:2.

// Note: Highest Common Factor(HCF) is also known as Greatest Common Divisor(GCD).

#include<iostream>

using namespace std;

int GCD(int a, int b) // Using Euclid Division algorithm.
{
    if(b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int handle_GCD(int a, int b)
{
    if((a == 0) and (b == 0))
    {
        cout<<"ERROR - Invalid operation, GCD(0, 0) is not defined .....";

        return INT_MIN;
    }

    if((a < 0) or (b < 0))
    {
        cout<<"ERROR - Invalid operation, arguments provided to GCD() should be non-negative .....";

        return INT_MIN;
    }

    return GCD(a, b);
}

int main()
{
    cout<<"GCD(0, 0): "<<handle_GCD(0, 0)<<"\n";

    cout<<"GCD(10, -1): "<<handle_GCD(10, -1)<<"\n";

    cout<<"GCD(7, 28): "<<handle_GCD(7, 28)<<"\n";

    cout<<"GCD(9, 100): "<<handle_GCD(9, 100)<<"\n";

    return 0;
}