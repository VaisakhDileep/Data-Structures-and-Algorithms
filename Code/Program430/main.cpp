/*
Created by  : Vaisakh Dileep
Date        : 22, September, 2021
Description : This program swaps two numbers without using a temporary variable(using +, - operator).
*/

#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
    if((a == nullptr) or (b == nullptr))
    {
        throw string {"ERROR - Invalid operation, one of the input numbers is not valid ....."};
    }

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void handle_swap(int *a, int *b)
{
    try
    {
        swap(a, b);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    int a {10}, b {20};

    cout<<"a: "<<a<<"    "<<"b: "<<b<<"    [Before swap]\n";

    swap(&a, &b);

    cout<<"a: "<<a<<"    "<<"b: "<<b<<"    [After swap]\n";

    return 0;
}
