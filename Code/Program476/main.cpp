/*
Created by  : Vaisakh Dileep
Date        : 16, October, 2021
Description : This program implements euclid division algorithm for finding HCF recursively.
*/

// For proof check "Program476/whiteboard_2.pdf"

// Note: Highest Common Factor(HCF) is also known as Greatest Common Divisor(GCD).

#include<iostream>

using namespace std;

int HCF(int a, int b) // Using Euclid Division algorithm.
{
    if(b == 0)
    {
        return a;
    }

    return HCF(b, a % b);
}

int handle_HCF(int a, int b)
{
    if((a == 0) and (b == 0))
    {
        cout<<"ERROR - Invalid operation, HCF(0, 0) is not defined .....";

        return INT_MIN;
    }

    if((a < 0) or (b < 0))
    {
        cout<<"ERROR - Invalid operation, arguments provided to HCF() should be non-negative .....";

        return INT_MIN;
    }

    return HCF(a, b);
}

int main()
{
    cout<<"HCF(0, 0): "<<handle_HCF(0, 0)<<"\n";

    cout<<"HCF(10, -1): "<<handle_HCF(10, -1)<<"\n";

    cout<<"HCF(7, 28): "<<handle_HCF(7, 28)<<"\n";

    cout<<"HCF(9, 100): "<<handle_HCF(9, 100)<<"\n";

    return 0;
}