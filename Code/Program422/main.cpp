/*
Created by  : Vaisakh Dileep
Date		: 13, September, 2021
Description : This program checks if the given pattern exists in a string using Knuth Morris Pratt algorithm.
*/

#include<iostream>

#include<vector>

using namespace std;

vector<int>* create_kmp_table(string pattern)
{
	vector<int> *kmp_table(new vector<int>(pattern.size(), 0));

	kmp_table->at(0) = 0; // This is a special case, if the all the beginning elements are same, then it could both be a prefix as well as suffix.

	int i {1}, length_common_prefix {0}; // When taking preifx and suffix, make sure they are proper prefix and proper suffix.

	while(i < pattern.size())
	{
		if(pattern[i] == pattern[length_common_prefix])
		{
			length_common_prefix++;

			kmp_table->at(i) = length_common_prefix;

			i++;
		}
		else
		{
			if(length_common_prefix == 0)
			{
				kmp_table->at(i) = 0;

				i++;
			}
			else
			{
				length_common_prefix = kmp_table->at(length_common_prefix - 1); // Search through the prefixes.
			}
		}
	}

	return kmp_table;
}

bool pattern_matching_kmp_algorithm(string text, string pattern)
{
	if((text.size() == 0) or (pattern.size() == 0))
	{
		throw string {"ERROR - Invalid operation, input strings cannot be empty ....."};
	}

	vector<int> *kmp_table(create_kmp_table(pattern));

	int i {0}, j {0};

	while(i < text.size())
	{
		if(j == pattern.size())
		{
			return true;
		}

		if(text[i] == pattern[j])
		{
			i++;
			j++;

			continue;
		}
		else
		{
			if(j == 0)
			{
				i++;
			}
			else
			{
				j = kmp_table->at(j - 1); // Search through the prefixes.
			}
		}
	}

	if(j == pattern.size())
	{
		return true;
	}

	return false;
}

bool handle_pattern_matching_kmp_algorithm(string text, string pattern)
{
	try
	{
		return pattern_matching_kmp_algorithm(text, pattern);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	cout<<"pattern_matching_kmp_algorithm(\"abba\", \"ba\"): "<<handle_pattern_matching_kmp_algorithm("aabbba", "bba")<<"\n";

	return 0;
}