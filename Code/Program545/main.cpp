/*
Created by  : Vaisakh Dileep
Date        : 2, March, 2022
Description : This program finds the length of the longest common sub-sequence between two strings(using memoization).
*/

#include<iostream>

#include<vector>

using namespace std;

int longest_common_subsequence_length(string str_1, string str_2, vector<vector<int>> &memo, int start_idx_1 = 0, int start_idx_2 = 0)
{
    if((start_idx_1 == str_1.size()) or (start_idx_2 == str_2.size()))
    {
        return 0;
    }

    if(memo[start_idx_1][start_idx_2] != 0)
    {
        return memo[start_idx_1][start_idx_2];
    }

    if(str_1[start_idx_1] == str_2[start_idx_2])
    {
        memo[start_idx_1][start_idx_2] = 1 + longest_common_subsequence_length(str_1, str_2, memo, start_idx_1 + 1, start_idx_2 + 1);
    }
    else
    {
        memo[start_idx_1][start_idx_2] = max(longest_common_subsequence_length(str_1, str_2, memo, start_idx_1 + 1, start_idx_2), longest_common_subsequence_length(str_1, str_2, memo, start_idx_1, start_idx_2 + 1));
    }

    return memo[start_idx_1][start_idx_2];
}

int handle_longest_common_subsequence_length(string str_1, string str_2)
{
    if((str_1.size() == 0) or (str_2.size() == 0))
    {
        cout<<"ERROR - Invalid operation, one of the strings is empty .....";

        return 0;
    }

    vector<vector<int>> memo(str_1.size(), vector<int>(str_2.size(), 0));

    return longest_common_subsequence_length(str_1, str_2, memo);
}

int main()
{
    cout<<"longest_common_subsequence_length(\"adbac\", \"abc\"): "<<handle_longest_common_subsequence_length("adbac", "abc")<<"\n";

    cout<<"longest_common_subsequence_length(\"red\", \"black\"): "<<handle_longest_common_subsequence_length("red", "black");

    return 0;
}