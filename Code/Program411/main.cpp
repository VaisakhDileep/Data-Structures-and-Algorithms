/*
Created by  : Vaisakh Dileep
Date        : 3, September, 2021
Description : This program finds the number of set bits in a number.
*/

// Indexing starts from the right hand side.

#include<iostream>

using namespace std;

int count_set_bits(int num)
{
    if(num < 0)
    {
        throw string {"ERROR - Invalid operation, number cannot be negative ....."};
    }

    int H {1};

    int count {0};

    while(num)
    {
        count = count + (num & H);

        num = num >> 1;
    }

    return count;
}

int handle_count_set_bits(int num)
{
    try
    {
        return count_set_bits(num);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    cout<<"count_set_bits(9): "<<handle_count_set_bits(9)<<"\n";

    return 0;
}