/*
Created by  : Vaisakh Dileep
Date        : 27, April, 2021
Description : This program finds the value of power(e, x) using taylor series(horner's rule).
*/

#include<iostream>

#include<iomanip>

using namespace std;

namespace recursion
{
    double e_x_taylor_series(int x, int n = 25)
    {
        static double sum {1};

        if(n == 0)
        {
            return sum;
        }
        else
        {
            sum = 1 + ((static_cast<double>(x) / n) * sum);

            return e_x_taylor_series(x, n - 1);
        }
    }
}

namespace iteration
{
    double e_x_taylor_series(int x, int n = 25)
    {
        double sum {1};

        for(; n >= 1; n--)
        {
            sum = 1 + ((static_cast<double>(x) / n) * sum);
        }

        return sum;
    }
}

int main()
{
    cout<<fixed<<setprecision(20);

    cout<<"e_x_taylor_series(1) [recursion]: "<<recursion::e_x_taylor_series(1)<<"\n"; // Value of 'e'

    cout<<"e_x_taylor_series(1) [iteration]: "<<iteration::e_x_taylor_series(1)<<"\n"; // Value of 'e'

    return 0;
}