/*
Created by  : Vaisakh Dileep
Date		: 14, July, 2021
Description : This program implements can_construct(target, word_bank) using recursion.
*/

// can_construct(target, word_bank) returns a boolean indicating whether or not the "target" can be constructed by concatenating elements of the "word_bank" array(elements can be used as many times as needed).

#include<iostream>

#include<vector>

using namespace std;

bool can_construct(string target, vector<string> *word_bank)
{
	if(target == "")
	{
		return true;
	}

	for(string word : *word_bank)
	{
		string suffix_word {target.substr(0, word.length())};

		if(suffix_word == word)
		{
			if(can_construct(target.substr(word.length(), target.length()), word_bank))
			{
				return true;
			}
		}
	}

	return false; // If the for loop fails(all the branches result in "false").
}

int main()
{
	cout<<"can_construct(\"abcdef\", [\"a\", \"bcd\", \"ee\", \"e\", \"f\"]): "<<can_construct("abcdef", new vector<string> {"a", "bcd", "ee", "e", "f"})<<"\n";

	cout<<"can_construct(\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\", [\"a\", \"aa\", \"aaa\", \"aaaa\", \"aaaaa\"]): "<<can_construct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", new vector<string> {"a", "aa", "aaa", "aaaa", "aaaaa"})<<"\n"; // This will take forever.

	return 0;
}