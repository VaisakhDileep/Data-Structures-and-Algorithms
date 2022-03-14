/*
Created by  : Vaisakh Dileep
Date        : 1, February, 2022
Description : This program finds the binomial coefficient using memoization(Pascal's triangle).
*/

#include<iostream>

#include<vector>

using namespace std;

long long binomial_coefficient(long long n, long long r, vector<vector<int>> &memo)
{
    if(memo[n][r] != 0)
    {
        return memo[n][r];
    }

    if((r == 0) or (r == n)) // Base condition
    {
        memo[n][r] = 1;

        return memo[n][r];
    }

    memo[n][r] = binomial_coefficient(n - 1, r - 1, memo) + binomial_coefficient(n - 1, r, memo);

    return memo[n][r];
}

long long handle_binomial_coefficient(long long n, long long r)
{
    if((n < 0) or (r < 0))
    {
        cout<<"ERROR - Invalid operation, input values cannot be negative .....";

        return LLONG_MIN;
    }

    if(r > n)
    {
        cout<<"ERROR - Invalid operation, 'r' cannot exceed 'n' .....";

        return LLONG_MIN;
    }

    vector<vector<int>> memo(n + 1, vector<int>(r + 1, 0));

    return binomial_coefficient(n, r, memo);
}

int main()
{
    cout<<"binomial_coefficient(10, 2): "<<handle_binomial_coefficient(10, 2)<<"\n";

    cout<<"binomial_coefficient(2, 10): "<<handle_binomial_coefficient(2, 10)<<"\n";

    cout<<"binomial_coefficient(5, -2): "<<handle_binomial_coefficient(5, -2)<<"\n";

    cout<<"binomial_coefficient(-5, 2): "<<handle_binomial_coefficient(-5, 2)<<"\n";

    return 0;
}