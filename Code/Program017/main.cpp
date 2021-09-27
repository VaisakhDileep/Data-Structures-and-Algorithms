/*
Created by  : Vaisakh Dileep
Date        : 27, April, 2021
Description : This program helps to understand nested recursion.
*/

#include<iostream>

using namespace std;

int nested_recursive_function(int n)
{
    if(n > 100)
    {
        return n - 10;
    }
    else
    {
        return nested_recursive_function(nested_recursive_function(n + 11)); // Recursive function is taking a Recursive function as parameter.
    }
}

int main()
{
    cout<<"nested_recursive_function(95): "<<nested_recursive_function(95)<<"\n";
    cout<<"nested_recursive_function(1): "<<nested_recursive_function(1)<<"\n";
    cout<<"nested_recursive_function(-1): "<<nested_recursive_function(-1)<<"\n";
    cout<<"nested_recursive_function(100): "<<nested_recursive_function(100)<<"\n"; // For values lesser than or equal to 100 the result is 91.

    cout<<"nested_recursive_function(150): "<<nested_recursive_function(150)<<"\n";
    cout<<"nested_recursive_function(200): "<<nested_recursive_function(200)<<"\n"; // For values greater than 100 the result is the number after subtracting 10 from it.
}