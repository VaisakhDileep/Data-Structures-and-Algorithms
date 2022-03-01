/*
Created by  : Vaisakh Dileep
Date        : 1, March, 2022
Description : This program finds the length of the longest common sub-string between two strings(using brute-force approach).
*/

#include<iostream>

using namespace std;

int longest_common_substring_length(string str_1, string str_2, int last_idx_1, int last_idx_2, bool previous_char_equal)
{
    if((last_idx_1 == -1) or (last_idx_2 == -1))
    {
        return 0;
    }

    if(previous_char_equal == true)
    {
        if(str_1[last_idx_1] == str_2[last_idx_2])
        {
            return 1 + longest_common_substring_length(str_1, str_2, last_idx_1 - 1, last_idx_2 - 1, true);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int length_possible_substring {0};

        if(str_1[last_idx_1] == str_2[last_idx_2])
        {
            length_possible_substring = 1 + longest_common_substring_length(str_1, str_2, last_idx_1 - 1, last_idx_2 - 1, true);
        }

        return max(length_possible_substring, max(longest_common_substring_length(str_1, str_2, last_idx_1 - 1, last_idx_2, false), longest_common_substring_length(str_1, str_2, last_idx_1, last_idx_2 - 1, false)));
    }
}

int handle_longest_common_substring_length(string str_1, string str_2)
{
    if((str_1.size() == 0) or (str_2.size() == 0))
    {
        cout<<"ERROR - Invalid operation, one of the input strings is empty .....";

        return 0;
    }

    return longest_common_substring_length(str_1, str_2, str_1.size() - 1, str_2.size() - 1, false);
}

int main()
{
    cout<<"longest_common_substring_length(\"temperature\", \"temper\"): "<<handle_longest_common_substring_length("temperature", "temper")<<'\n';

    return 0;
}