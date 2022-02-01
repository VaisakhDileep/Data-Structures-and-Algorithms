/*
Created by  : Vaisakh Dileep
Date        : 1, February, 2022
Description : This program finds the binomial coefficient using tabulation(Pascal's triangle).
*/

#include<iostream>

#include<vector>

using namespace std;

long long binomial_coefficient(long long n, long long r) // Note this approach uses "O(n * r)" space.
{
    vector<vector<int>> table(n + 1, vector<int>(r + 1, 0));

    for(long long i {0}; i <= n; i++)
    {
        for(long long j {0}; j <= min(i, r); j++)
        {
            if((i == j) or (j == 0))
            {
                table[i][j] = 1;
            }
            else
            {
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
            }
        }
    }

    return table[n][r];
}

long long handle_binomial_coefficient(long long n, long long r)
{
    if((n < 0) or (r < 0))
    {
        cout<<"ERROR - Invalid operation, input values cannot be negative .....";

        return INT_MIN;
    }

    if(r > n) 
    {
        cout<<"ERROR - Invalid operation, 'r' cannot exceed 'n' .....";

        return INT_MIN;
    }

    return binomial_coefficient(n, r);
}

int main()
{
    cout<<"binomial_coefficient(10, 2): "<<handle_binomial_coefficient(10, 2)<<"\n";

    cout<<"binomial_coefficient(2, 10): "<<handle_binomial_coefficient(2, 10)<<"\n";

    cout<<"binomial_coefficient(5, -2): "<<handle_binomial_coefficient(5, -2)<<"\n";

    cout<<"binomial_coefficient(-5, 2): "<<handle_binomial_coefficient(-5, 2)<<"\n";

    return 0;
}