/*
Created by  : Vaisakh Dileep
Date        : 26, April, 2021
Description : This program helps to understand how static variables work in recursive functions.
*/

#include<iostream>

using namespace std;

namespace prototype_1
{
    int recursive_function_using_static_variable(int n)
    {
        static int static_x {0};

        if(n > 0)
        {
            static_x++;

            return recursive_function_using_static_variable(n - 1) + static_x; // Behaves like Descending phase.
        }

        return 0;
    }
}

namespace prototype_2
{
    int recursive_function_using_static_variable(int n)
    {
        static int static_x {0};

        if(n > 0)
        {
            static_x++;

            return static_x + recursive_function_using_static_variable(n - 1); // Behaves like Descending phase.
        }

        return 0;
    }
}

int main()
{
    cout<<"recursive_function_using_static_variable(5) [prototype 1]: "<<(prototype_1::recursive_function_using_static_variable(5))<<"\n";

    cout<<"recursive_function_using_static_variable(5) [prototype 2]: "<<(prototype_2::recursive_function_using_static_variable(5))<<"\n";

    return 0;
}