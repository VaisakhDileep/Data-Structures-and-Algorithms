/*
Created by  : Vaisakh Dileep
Date        : 29, May, 2021
Description : This program finds the index of the first set bit of a number.
*/

// Indexing starts from the right hand side.

#include<iostream>

using namespace std;

int first_set_bit(int num)
{
    if(num == 0)
    {
        throw string {"ERROR - Invalid operation, number cannot be zero ....."};
    }

    int H {1};

    int count {0};

    while(num)
    {
        if(num & H)
        {
            return count;
        }
        else
        {
            num = num >> 1;

            count++;
        }
    }
}

int handle_first_set_bit(int num)
{
    try
    {
        return first_set_bit(num);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    cout<<"handle_first_set_bit(1): "<<handle_first_set_bit(1)<<"\n";
    cout<<"handle_first_set_bit(2): "<<handle_first_set_bit(2)<<"\n";
    cout<<"handle_first_set_bit(48): "<<handle_first_set_bit(48)<<"\n";

    cout<<"handle_first_set_bit(0): "<<handle_first_set_bit(0)<<"\n";

    return 0;
}