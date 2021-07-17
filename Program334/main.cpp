/*
Created by  : Vaisakh Dileep
Date		: 14, July, 2021
Description : This program implements can_construct(target, word_bank) using memoization.
*/

// can_construct(target, word_bank) returns a boolean indicating whether or not the "target" can be constructed by concatenating elements of the "word_bank" array(elements can be used as many times as needed).

#include<iostream>

#include<vector>

#include<unordered_map>

using namespace std;

bool can_construct(string target, vector<string> *word_bank, unordered_map<string, bool> &memo)
{
	if(memo.find(target) != memo.end())
	{
		return memo[target];
	}

	if(target == "")
	{
		return true;
	}

	for(string word : *word_bank)
	{
		string suffix_word {target.substr(0, word.length())};

		if(suffix_word == word)
		{
			if(can_construct(target.substr(word.length(), target.length()), word_bank, memo))
			{
				memo[target] = true;

				return true;
			}
		}
	}

	memo[target] = false; // If the for loop fails(all the branches result in "false").

	return false;
}

bool handle_can_construct(string target, vector<string> *word_bank)
{
	unordered_map<string, bool> memo {};

	return can_construct(target, word_bank, memo);
}

int main()
{
	cout<<"can_construct(\"abcdef\", [\"a\", \"bcd\", \"ee\", \"e\", \"f\"]): "<<handle_can_construct("abcdef", new vector<string> {"a", "bcd", "ee", "e", "f"})<<"\n";

	cout<<"can_construct(\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\", [\"a\", \"aa\", \"aaa\", \"aaaa\", \"aaaaa\"]): "<<handle_can_construct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", new vector<string> {"a", "aa", "aaa", "aaaa", "aaaaa"})<<"\n"; // Notice here we get the result without any delay.

	return 0;
}