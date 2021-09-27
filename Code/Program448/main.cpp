/*
Created by  : Vaisakh Dileep
Date        : 26, September, 2021
Description : This program finds the longest palindromic sub-string in a string(using brute-force approach).
*/

#include<iostream>

using namespace std;

string longest_palindromic_substring(string str)
{
    if(str == "")
    {
        throw string {"ERROR - Invalid operation, string is empty ....."};
    }

    int current_length {1}, string_start_index {0};

    for(int i {0}; i < str.size(); i++)
    {
        for(int j {i + 1}; j < str.size(); j++)
        {
            bool flag {true};

            for(int k {0}; k < (j - i + 1) / 2; k++) // Checks if the generated sub-string is a palindrome or not.
            {
                if(str[i + k] != str[j - k])
                {
                    flag = false;
                }
            }

            if((flag == true) and ((j - i + 1) > current_length))
            {
                string_start_index = i;

                current_length = j - i + 1;
            }
        }
    }

    string result {str.substr(string_start_index, current_length)};

    return result;
}

string handle_longest_palindromic_substring(string str)
{
    try
    {
        return longest_palindromic_substring(str);
    }
    catch(string &ex)
    {
        cout<<ex;

        return "";
    }
}

int main()
{
    cout<<"handle_longest_palindromic_substring(\"aaabbbba\"): "<<handle_longest_palindromic_substring("aaabbbba")<<"\n";

    return 0;
}