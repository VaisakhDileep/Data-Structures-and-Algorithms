/*
Created by  : Vaisakh Dileep
Date        : 27, April, 2021
Description : This program helps to understand tree recursion.
*/

#include<iostream>

using namespace std;

void tree_recursive_function(int n) // Recursive call happens more than once in the function.
{
    if(n > 0)
    {
        cout<<n<<" ";

        tree_recursive_function(n - 1);
        tree_recursive_function(n - 1);
    }
}

int main()
{
    cout<<"tree_recursive_function(3): ";
    tree_recursive_function(3);
    cout<<"\n";
    
    return 0;
}