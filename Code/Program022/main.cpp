/*
Created by  : Vaisakh Dileep
Date        : 27, April, 2021
Description : This program finds the value of power(e, x) using taylor series.
*/

#include<iostream>

#include<iomanip> // For std::setprecision()

using namespace std;

namespace recursion
{
    double e_x_taylor_series(int x, int n = 25) // Increasing the value of 'n' improves accuracy.
    {
        static double pow {1}, fact {1};

        double sum {0};

        if(n == 0)
        {
            return 1;
        }
        else
        {
            sum = e_x_taylor_series(x, n - 1);

            pow *= x;
            fact *= n;

            return sum + (pow / fact);
        }
    }
}

namespace iteration
{
    double factorial(int n)
    {
        double fact {1};

        for(int i {1}; i <= n; i++)
        {
            fact *= i;
        }

        return fact;
    }

    double power(int m, int n)
    {
        double pow {1};

        for(int i {1}; i <= n; i++)
        {
            pow *= m;
        }

        return pow;
    }

    double e_x_taylor_series(int x, int n = 25) // Increasing the value of 'n' improves accuracy.
    {
        double sum {1}; // For n = 0

        for(int i {1}; i <= n; i++)
        {
            sum += power(x, i) / factorial(i);
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