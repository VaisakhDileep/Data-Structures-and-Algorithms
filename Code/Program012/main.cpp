/*
Created by  : Vaisakh Dileep
Date        : 26, April, 2021
Description : This program helps to understand how global variables work in recursive functions.
*/

#include<iostream>

using namespace std;

int global_x {0};

int recursive_function_using_global_variable(int n)
{
    if(n > 0)
    {
        global_x++;

        return recursive_function_using_global_variable(n - 1) + global_x;
    }

    return 0;
}

int main()
{
    cout<<"recursive_function_using_global_variable(5): "<<recursive_function_using_global_variable(5)<<"\n";

    return 0;
}