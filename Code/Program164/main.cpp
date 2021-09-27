/*
Created by  : Vaisakh Dileep
Date        : 29, May, 2021
Description : This program finds the index of the first different bit of two numbers.
*/

// Indexing starts from the right hand side.

#include<iostream>

using namespace std;

int first_different_bit(int num_1, int num_2)
{
    if(num_1 == num_2)
    {
        throw string {"ERROR - Invalid operation, numbers are equal ....."};
    }

    int H {1};

    int count {0};

    while((num_1 & H) == (num_2 & H))
    {
        H = H << 1;

        count++;
    }

    return count;
}

int handle_first_different_bit(int num1, int num2)
{
    try
    {
        return first_different_bit(num1, num2);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    cout<<"handle_first_different_bit(1, 2): "<<handle_first_different_bit(1, 2)<<"\n";
    cout<<"handle_first_different_bit(16, 20): "<<handle_first_different_bit(16, 20)<<"\n";

    cout<<"handle_first_different_bit(10, 10): "<<handle_first_different_bit(10, 10)<<"\n";

    return 0;
}