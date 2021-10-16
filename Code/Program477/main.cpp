/*
Created by  : Vaisakh Dileep
Date        : 16, October, 2021
Description : This program implements euclid division algorithm for finding HCF iteratively.
*/

// For proof check "Program476/whiteboard_2.pdf"

#include<iostream>

using namespace std;

int HCF(int a, int b) // Using Euclid Division algorithm.
{
    if((a == 0) and (b == 0))
    {
        throw string {"ERROR - Invalid operation, HCF(0, 0) is not defined ....."};
    }

    if((a < 0) or (b < 0))
    {
        throw string {"ERROR - Invalid operation, arguments provided to HCF() should be non-negative ....."};
    }

    while(b != 0)
    {
        int temp {b};

        b = a % b;

        a = temp;
    }

    return a;
}

int handle_HCF(int a, int b)
{
    try
    {
        return HCF(a, b);
    }
    catch(string &ex)
    {
        cout<<ex;

        return INT_MIN;
    }
}

int main()
{
    cout<<"HCF(0, 0): "<<handle_HCF(0, 0)<<"\n";

    cout<<"HCF(10, -1): "<<handle_HCF(10, -1)<<"\n";

    cout<<"HCF(7, 28): "<<handle_HCF(7, 28)<<"\n";

    cout<<"HCF(9, 100): "<<handle_HCF(9, 100)<<"\n";

    return 0;
}