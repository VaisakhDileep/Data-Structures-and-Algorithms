/*
Created by  : Vaisakh Dileep
Date        : 26, April, 2021
Description : This program helps to understand pass-by-value in parameter passing.
*/

#include<iostream>

using namespace std;

void swap(int x, int y)
{
    int temp {0};

    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a {10}, b {20};

    cout<<"a: "<<a<<"\t"<<"b: "<<b<<"\n";

    swap(a, b);

    cout<<"a: "<<a<<"\t"<<"b: "<<b<<"\n";

    return 0;
}