/*
Created by  : Vaisakh Dileep
Date        : 1, March, 2022
Description : This program finds the length of the largest palindromic sub-sequence in a string(using memoization).
*/

#include<iostream>

#include<unordered_map>

#include<vector>

using namespace std;

int longest_palindromic_subsequence_length(string str, int left, int right, unordered_map<string, int> &memo)
{
    if(left > right) // Base condition
    {
        return 0;
    }

    if(left == right) // If there is only one character
    {
        return 1;
    }

    string key {to_string(left) + " " + to_string(right)};

    if(memo.find(key) != memo.end())
    {
        return memo[key];
    }

    if(str[left] == str[right])
    {
        memo[key] = 2 + longest_palindromic_subsequence_length(str, left + 1, right - 1, memo);
    }
    else
    {
        memo[key] = max(longest_palindromic_subsequence_length(str, left + 1, right , memo), longest_palindromic_subsequence_length(str, left, right - 1, memo));
    }

    return memo[key];
}

int handle_longest_palindromic_subsequence_length(string str)
{
    if(str.size() == 0)
    {
        cout<<"ERROR - Invalid operation, string is empty .....";

        return 0;
    }

    unordered_map<string, int> memo;

    return longest_palindromic_subsequence_length(str, 0, str.size() - 1, memo);
}

int main()
{
    cout<<"longest_palindromic_subsequence_length(\"abxcbaz\"): "<<handle_longest_palindromic_subsequence_length("abxcbaz")<<"\n";

    cout<<"longest_palindromic_subsequence_length(\"aa\"): "<<handle_longest_palindromic_subsequence_length("aa");

    return 0;
}