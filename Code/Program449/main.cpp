/*
Created by  : Vaisakh Dileep
Date		: 26, September, 2021
Description : This program finds the longest palindromic sub-string in a string(using dynamic programming).
*/

#include<iostream>

#include<vector>

using namespace std;

string longest_palindromic_substring(string str)
{
	if(str == "")
	{
		throw string {"ERROR - Invalid operation, string is empty ....."};
	}

	vector<vector<bool>> palindrome_table (str.size(), vector<bool>(str.size(), false));

// Initialization part start.
	for(int i {0}; i < str.size(); i++) // Fill the diagonal elements with "true".
	{
		palindrome_table[i][i] = true;
	}

	int current_length {1}, string_start_index {0};

	for(int i {0}; i < str.size() - 1; i++) // Fill the diagonal elements above the diagonal.
	{
		if(str[i] == str[i + 1])
		{
			palindrome_table[i][i + 1] = true;

			string_start_index = i;

			current_length = 2;
		}
	}
// Initialization part end.

	for(int i {3}; i <= str.size(); i++) // Where 'i' is the size of the sub-string.
	{
		for(int j {0}; j <= str.size() - i; j++)
		{
			int k {j + i - 1};

			if((str[j] == str[k]) and (palindrome_table[j + 1][k - 1] == true))
			{
				palindrome_table[j][k] = true;

				if(i > current_length)
				{
					string_start_index = j;

					current_length = i;
				}
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