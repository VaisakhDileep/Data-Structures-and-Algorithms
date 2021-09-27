/*
Created by  : Vaisakh Dileep
Date        : 27, April, 2021
Description : This program helps to understand indirect recursion.
*/

#include<iostream>

using namespace std;

void function_B(int); // Forward declaration

void function_A(int n) // Here function_A calls function_B.
{
    if(n > 0)
    {
        cout<<n<<" ";

        function_B(n - 1);
    }
}

void function_B(int n) // Here function_B calls function_A.
{
    if(n > 1)
    {
        cout<<n<<" ";

        function_A(n / 2);
    }
}


int main()
{
    cout<<"function_A(20): ";
    function_A(20);
    cout<<"\n";

    return 0;
}