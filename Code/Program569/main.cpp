/*
Created by  : Vaisakh Dileep
Date        : 13, March, 2022
Description : This program finds the binomial coefficient using space-optimized tabulation(Pascal's triangle).
*/

#include<iostream>

#include<vector>

using namespace std;

long long binomial_coefficient(long long n, long long r) // Note this approach uses only "O(r)" space.
{
    vector<int> table(r + 1, 0);

    table[0] = 1;

    for(long long i {1}; i <= n; i++)
    {
        for(int j {min(i, r)}; j >= 1; j--)
        {
            table[j] = table[j - 1] + table[j];
        }
    }

    return table[r];
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