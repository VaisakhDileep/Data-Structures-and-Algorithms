/*
Created by  : Vaisakh Dileep
Date        : 27, April, 2021
Description : This program helps to understand tail recursion.
*/

#include<iostream>

using namespace std;

namespace recursion
{
    void tail_recursive_function(int n) // Recursive call happens at the end of the function.
    {
        if(n > 0)
        {
            cout<<n<<" ";

            tail_recursive_function(n - 1);
        }
    }
}

namespace iteration
{
    void tail_recursive_function(int n) // Equivalent iterative version.
    {
        while(n > 0)
        {
            cout<<n<<" ";

            n--;
        }
    }
}

int main()
{
    cout<<"tail_recursive_function(3) [recursion]: ";
    recursion::tail_recursive_function(3);
    cout<<"\n";

    cout<<"tail_recursive_function(3) [iteration]: ";
    iteration::tail_recursive_function(3);
    cout<<"\n";

    return 0;
}