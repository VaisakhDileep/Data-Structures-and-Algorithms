/*
Created by  : Vaisakh Dileep
Date        : 27, April, 2021
Description : This program finds the power(m, n).
*/

#include<iostream>

using namespace std;

namespace recursion
{
    int power(int m, int n)
    {
        if(n == 0)
        {
            return 1;
        }
        else
        {
            return power(m, n - 1) * m;
        }
    }
}

namespace iteration
{
    int power(int m, int n)
    {
        int pow {1};

        for(int i {1}; i <= n; i++)
        {
            pow *= m;
        }

        return pow;
    }
}

int main()
{
    cout<<"power(2, 9) [recursion]: "<<recursion::power(2, 9)<<"\n";

    cout<<"power(2, 9) [iteration]: "<<iteration::power(2, 9)<<"\n";

    return 0;
}