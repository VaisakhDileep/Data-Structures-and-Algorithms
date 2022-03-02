/*
Created by  : Vaisakh Dileep
Date        : 28, February, 2022
Description : This program finds the length of the largest palindromic sub-sequence in a string(using tabulation).
*/

#include<iostream>

#include<vector>

using namespace std;

int longest_palindromic_subsequence_length(string str)
{
    if(str.size() == 0)
    {
        throw string {"ERROR - Invalid operation, string is empty ....."};
    }

    vector<vector<int>> LPSSeq_length_table(str.size(), vector<int>(str.size(), 0)); // "LPSS" stands for "Longest Palindrome Sub-Sequence"

    for(int i {0}; i < str.size(); i++)
    {
        LPSSeq_length_table[i][i] = 1;
    }

    for(int i {2}; i <= str.size(); i++) // Length of the substring.
    {
        for(int left {0}; left <= str.size() - i; left++)
        {
            int right {left + i - 1};

            if(str[left] == str[right])
            {
                if(i == 2)
                {
                    LPSSeq_length_table[left][right] = 2;
                }
                else
                {
                    LPSSeq_length_table[left][right] = 2 + LPSSeq_length_table[left + 1][right - 1];
                }
            }
            else
            {
                LPSSeq_length_table[left][right] = max(LPSSeq_length_table[left + 1][right], LPSSeq_length_table[left][right - 1]);
            }
        }
    }

    return LPSSeq_length_table[0][str.size() - 1];
}

int handle_longest_palindromic_subsequence_length(string str)
{
    try
    {
        return longest_palindromic_subsequence_length(str);
    }
    catch(string &ex)
    {
        cout<<ex;

        return 0;
    }
}

int main()
{
    cout<<"longest_palindromic_subsequence_length(\"abxcbaz\"): "<<handle_longest_palindromic_subsequence_length("abxcbaz")<<"\n";

    return 0;
}