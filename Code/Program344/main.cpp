/*
Created by  : Vaisakh Dileep
Date		: 16, July, 2021
Description : This program implements can_construct(target, word_bank) using tabulation.
*/

// can_construct(target, word_bank) returns a boolean indicating whether or not the "target" can be constructed by concatenating elements of the "word_bank" array(elements can be used as many times as needed).

#include<iostream>

#include<vector>

using namespace std;

bool can_construct(string target, vector<string> *word_bank)
{
	vector<bool> table((target.size() + 1), false);

	table.at(0) = true;

	for(unsigned long long i {0}; i < table.size(); i++)
	{
		if(table.at(i) == true)
		{
			for(string word : *word_bank)
			{
				string suffix_word {target.substr(i, word.size())};

				if(word == suffix_word)
				{
					table.at(i + word.size()) = true; // No need to do bounds checking because "suffix_word" will do it for us.
				}
			}
		}
	}

	return table.at(target.size());
}

int main()
{
	cout<<"can_construct(\"abcdef\", [\"a\", \"bcd\", \"ee\", \"e\", \"f\"]): "<<can_construct("abcdef", new vector<string> {"a", "bcd", "ee", "e", "f"})<<"\n";

	cout<<"can_construct(\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\", [\"a\", \"aa\", \"aaa\", \"aaaa\", \"aaaaa\"]): "<<can_construct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", new vector<string> {"a", "aa", "aaa", "aaaa", "aaaaa"})<<"\n"; // Notice here we get the result without any delay.

	return 0;
}