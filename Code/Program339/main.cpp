/*
Created by  : Vaisakh Dileep
Date        : 15, July, 2021
Description : This program implements fibonacci(n) using tabulation.
*/

// fibonacci(n) finds the n'th element in the fibonacci series. The 1st and 2nd element of the sequence are 0 and 1.

// Indexing of the fibonacci series starts from '0'.

#include<iostream>

#include<vector>

using namespace std;

long long fibonacci(long long num)
{
    if(num <= 1)
    {
        return num;
    }

    vector<long long> table(num + 1, 0);

    table.at(0) = 0;
    table.at(1) = 1;

    for(unsigned long long i {2}; i < table.size(); i++)
    {
        table.at(i) = table.at(i - 1) + table.at(i - 2);
    }

    return table.at(num);
}

int main()
{
    cout<<"fibonacci(10): "<<fibonacci(10)<<"\n";

    cout<<"fibonacci(50): "<<fibonacci(50)<<"\n";

    cout<<"fibonacci(100): "<<fibonacci(100)<<"\n"; // Notice here we get the result without any delay.

    cout<<"fibonacci(1000): "<<fibonacci(1000)<<"\n";

    return 0;
}