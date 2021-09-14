/*
Created by  : Vaisakh Dileep
Date		: 13, September, 2021
Description : This program finds all the matching pattern in a string using Knuth Morris Pratt algorithm.
*/

#include<iostream>

#include<vector>

using namespace std;

vector<int>* create_kmp_table(string pattern)
{
	vector<int> *kmp_table {new vector<int>(pattern.size(), 0)};

	kmp_table->at(0) = 0; // This is a special case.

	int i {1}, length_common_prefix {0}; // When taking prefix and suffix, make sure they are proper prefix and proper suffix.

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

vector<pair<int, int>>* pattern_matching_kmp_algorithm(string text, string pattern)
{
	if((text.size() == 0) or (pattern.size() == 0))
	{
		throw string {"ERROR - Invalid operation, input strings cannot be empty ....."};
	}

	vector<pair<int, int>> *pattern_in_string {new vector<pair<int, int>> {}};

	vector<int> *kmp_table {create_kmp_table(pattern)};

	int i {0}, j {0};

	while(i < text.size())
	{
		if(j == pattern.size())
		{
			pattern_in_string->push_back(pair<int, int> {i - pattern.size(), i - 1});

			j = kmp_table->at(j - 1);
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
		pattern_in_string->push_back(pair<int, int> {i - pattern.size(), i - 1});
	}

	return pattern_in_string;
}

vector<pair<int, int>>* handle_pattern_matching_kmp_algorithm(string text, string pattern)
{
	try
	{
		return pattern_matching_kmp_algorithm(text, pattern);
	}
	catch(string &ex)
	{
		cout<<ex;

		return nullptr;
	}
}

void display_matched_patterns(vector<pair<int, int>>* pattern_in_string)
{
	if(pattern_in_string == nullptr)
	{
		return ;
	}

	for(int i {0}; i < pattern_in_string->size(); i++)
	{
		cout<<"{"<<pattern_in_string->at(i).first<<", "<<pattern_in_string->at(i).second<<"} ";
	}
}

int main()
{
	vector<pair<int, int>>* pattern_in_string {handle_pattern_matching_kmp_algorithm("abba", "ba")};

	cout<<"pattern_matching_kmp_algorithm(\"abba\", \"ba\"): ";

	display_matched_patterns(pattern_in_string);

	return 0;
}