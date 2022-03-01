/*
Created by  : Vaisakh Dileep
Date        : 1, March, 2022
Description : This program finds the length of the longest common sub-string between two strings(using dynamic programming).
*/

#include<iostream>

#include<vector>

using namespace std;

int longest_common_substring_length(string str_1, string str_2)
{
    if((str_1.size() == 0) or (str_2.size() == 0))
    {
        throw string {"ERROR - Invalid operation, one of the input strings is empty ....."};
    }

    int LCSS_length {0}; // "LCSS" stands for "Longest Common Sub-String"

    vector<vector<int>> LCSS_DP_table(str_1.size(), vector<int>(str_2.size(), 0));

    for(int i {0}; i < str_1.size(); i++)
    {
        for(int j {0}; j < str_2.size(); j++)
        {
            if(str_1[i] == str_2[j])
            {
                if((i == 0) or (j == 0))
                {
                    LCSS_DP_table[i][j] = 1;
                }
                else
                {
                    LCSS_DP_table[i][j] = LCSS_DP_table[i - 1][j - 1] + 1;
                }

                LCSS_length = max(LCSS_length, LCSS_DP_table[i][j]);
            }
        }
    }

    return LCSS_length;
}

int handle_longest_common_substring_length(string str_1, string str_2)
{
    try
    {
        return longest_common_substring_length(str_1, str_2);
    }
    catch(string &ex)
    {
        cout<<ex;

        return 0;
    }
}

int main()
{
    cout<<"longest_common_substring_length(\"temperature\", \"temper\"): "<<handle_longest_common_substring_length("temperature", "temper")<<"\n";

    cout<<"longest_common_substring_length(\"red\", \"black\"): "<<handle_longest_common_substring_length("red", "black");

    return 0;
}