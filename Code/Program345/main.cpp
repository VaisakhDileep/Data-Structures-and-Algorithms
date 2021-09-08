/*
Created by  : Vaisakh Dileep
Date		: 16, July, 2021
Description : This program implements count_construct(target, word_bank) using tabulation.
*/

// count_construct(target, word_bank) return the number of ways that the "target" can constructed by concatenating the elements from the "word_bank" array(elements can be used as many times as needed).

#include<iostream>

#include<vector>

using namespace std;

long long count_construct(string target, vector<string> *word_bank)
{
	vector<long long> table((target.size() + 1), 0);

	table.at(1) = 1;

	for(unsigned long long i {0}; i < table.size(); i++)
	{
		if(table.at(i) != 0)
		{
			for(string word : *word_bank)
			{
				string suffix_word {target.substr(i, word.size())};

				if(word == suffix_word)
				{
					table.at(i + word.size()) += table.at(i); // No need to do bounds checking because "suffix_word" will do it for us.
				}
			}
		}
	}

	return table.at(target.size());
}

int main()
{
	cout<<"count_construct(\"abcdeef\", [\"a\", \"bcd\", \"ee\", \"e\", \"f\"]): "<<count_construct("abcdeef", new vector<string> {"a", "bcd", "ee", "e", "f"})<<"\n";

	cout<<"count_construct(\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\", [\"a\", \"aa\", \"aaa\", \"aaaa\", \"aaaaa\"]): "<<count_construct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", new vector<string> {"a", "aa", "aaa", "aaaa", "aaaaa"})<<"\n"; // Notice here we get the result without any delay.

	return 0;
}