/*
Created by  : Vaisakh Dileep
Date        : 28, February, 2022
Description : This program finds the length of the longest palindromic sub-sequence in a string(using brute-force approach).
*/

#include<iostream>

using namespace std;

int longest_palindromic_subsequence_length(string str, int left, int right)
{
    if(left > right) // Base condition
    {
        return 0;
    }

    if(left == right) // If there is only one character
    {
        return 1;
    }

    if(str[left] == str[right])
    {
        return 2 + longest_palindromic_subsequence_length(str, left + 1, right - 1);
    }
    else
    {
        return max(longest_palindromic_subsequence_length(str, left + 1, right), longest_palindromic_subsequence_length(str, left, right - 1));
    }
}

int handle_longest_palindromic_subsequence_length(string str)
{
    if(str.size() == 0)
    {
        cout<<"ERROR - Invalid operation, string is empty .....";

        return 0;
    }

    return longest_palindromic_subsequence_length(str, 0, str.size() - 1);
}

int main()
{
    cout<<"longest_palindromic_subsequence_length(\"abxcbaz\"): "<<handle_longest_palindromic_subsequence_length("abxcbaz")<<"\n";

    cout<<"longest_palindromic_subsequence_length(\"aa\"): "<<handle_longest_palindromic_subsequence_length("aa");

    return 0;
}