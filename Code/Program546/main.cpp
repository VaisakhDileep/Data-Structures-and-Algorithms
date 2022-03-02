/*
Created by  : Vaisakh Dileep
Date        : 2, March, 2022
Description : This program finds the length of the longest common sub-sequence between two strings(using tabulation).
*/

#include<iostream>

#include<vector>

using namespace std;

int longest_common_subsequence_length(string str_1, string str_2)
{
    if((str_1.size() == 0) or (str_2.size() == 0))
    {
        throw string {"ERROR - Invalid operation, one of the strings is empty ....."};
    }

    vector<vector<int>> LCSSeq_DP_table(str_1.size(), vector<int>(str_2.size(), 0));

    for(int i {0}; i < str_1.size(); i++)
    {
        for(int j {0}; j < str_2.size(); j++)
        {
            if(str_1[i] == str_2[j])
            {
                if((i == 0) or (j == 0))
                {
                    LCSSeq_DP_table[i][j] = 1;
                }
                else
                {
                    LCSSeq_DP_table[i][j] = 1 + LCSSeq_DP_table[i - 1][j - 1];
                }
            }
            else
            {
                LCSSeq_DP_table[i][j] = max(((i == 0) ? 0 : LCSSeq_DP_table[i - 1][j]), ((j == 0) ? 0 : LCSSeq_DP_table[i][j - 1]));
            }
        }
    }

    return LCSSeq_DP_table[str_1.size() - 1][str_2.size() - 1];
}

int handle_longest_common_subsequence_length(string str_1, string str_2)
{
    try
    {
        return longest_common_subsequence_length(str_1, str_2);
    }
    catch(string &ex)
    {
        cout<<ex;

        return 0;
    }
}

int main()
{
    cout<<"longest_common_subsequence_length(\"adbac\", \"abc\"): "<<handle_longest_common_subsequence_length("adbac", "abc")<<"\n";

    cout<<"longest_common_subsequence_length(\"red\", \"black\"): "<<handle_longest_common_subsequence_length("red", "black");

    return 0;
}