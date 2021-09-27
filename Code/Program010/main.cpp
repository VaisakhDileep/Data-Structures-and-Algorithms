/*
Created by  : Vaisakh Dileep
Date        : 26, April, 2021
Description : This program helps to understand ascending phase and descending phase in recursive functions.
*/

#include<iostream>

using namespace std;

void ascending_phase_recursive_function(int n)
{
    if(n > 0)
    {
        cout<<n<<" "; // Ascending phase or Calling phase.

        ascending_phase_recursive_function(n - 1);
    }
}

void descending_phase_recursive_function(int n)
{
    if(n > 0)
    {
        descending_phase_recursive_function(n - 1);

        cout<<n<<" "; // Descending phase or Returning phase.
    }
}

int main()
{
    cout<<"ascending_phase_recursive_function(3): ";
    ascending_phase_recursive_function(3);
    cout<<"\n";

    cout<<"descending_phase_recursive_function(3): ";
    descending_phase_recursive_function(3);
    cout<<"\n";

    return 0;
}