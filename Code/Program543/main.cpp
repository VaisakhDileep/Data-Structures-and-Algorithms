/*
Created by  : Vaisakh Dileep
Date        : 1, March, 2022
Description : This program finds the longest common sub-string between two strings(using dynamic programming).
*/

#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

string longest_common_substring(string str_1, string str_2)
{
    if((str_1.size() == 0) or (str_2.size() == 0))
    {
        throw string {"ERROR - Invalid operation, one of the strings is empty ....."};
    }

    string LCSS {};

    int LCSS_length {0}, row {0}, column {0};

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

                if(LCSS_DP_table[i][j] > LCSS_length)
                {
                    LCSS_length = LCSS_DP_table[i][j];

                    row = i;

                    column = j;
                }
            }
        }
    }

    while((row >= 0) and (column >= 0) and (LCSS_DP_table[row][column] != 0))
    {
        LCSS += str_1[row];

        row--;

        column--;
    }

    reverse(LCSS.begin(), LCSS.end());

    return LCSS;
}

string handle_longest_common_substring(string str_1, string str_2)
{
    try
    {
        return longest_common_substring(str_1, str_2);
    }
    catch(string &ex)
    {
        cout<<ex;

        return "";
    }
}

int main()
{
    cout<<"longest_common_substring(\"temperature\", \"temper\"): "<<handle_longest_common_substring("temperature", "temper")<<"\n";

    cout<<"longest_common_substring(\"red\", \"black\"): "<<handle_longest_common_substring("red", "black");

    return 0;
}