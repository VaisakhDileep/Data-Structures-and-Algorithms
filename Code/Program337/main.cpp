/*
Created by  : Vaisakh Dileep
Date		: 14, July, 2021
Description : This program implements all_construct(target, word_bank) using recursion.
*/

// all_construct(target, word_bank) returns a list of all ways that "target" can be constructed by concatenating elements of the "word_bank" array(elements can be used as many times as needed).

#include<iostream>

#include<vector>

using namespace std;

void display_vec(vector<vector<string>*> *vec)
{
	if(vec == nullptr)
	{
		cout<<"[ [ ] ]";

		return ;
	}

	cout<<"[ ";
	for(unsigned long long i {0}; i < vec->size(); i++)
	{
		cout<<"[ ";
		for(unsigned long long j {0}; j < vec->at(i)->size(); j++)
		{
			cout<<vec->at(i)->at(j)<<" ";
		}
		cout<<"]"<<((i == (vec->size() - 1)) ? " " : ", ");
	}
	cout<<"]";
}

vector<vector<string>*>* all_construct(string target, vector<string> *word_bank)
{
	if(target == "")
	{
		return new vector<vector<string>*> {new vector<string> {}};
	}

	vector<vector<string>*> *result {nullptr};

	for(string word : *word_bank)
	{
		string suffix_word {target.substr(0, word.length())};

		if(suffix_word == word)
		{
			vector<vector<string>*> *temp {all_construct(target.substr(word.length(), target.length()), word_bank)};

			if(temp != nullptr)
			{
				if(result == nullptr)
				{
					result = new vector<vector<string>*> {};
				}

				for(vector<string> *vec : *temp)
				{
					vec->push_back(word);

					result->push_back(vec);
				}
			}
		}
	}

	return result; // If the for loop fails(all branches result in "nullptr"). "result" wouldn't be updated, it will default to "nullptr".
}

int main()
{
	vector<vector<string>*> *result {};

	cout<<"all_construct(\"abcdeef\", [\"a\", \"bcd\", \"ee\", \"e\", \"f\"]): ";

	result = all_construct("abcdeef", new vector<string> {"a", "bcd", "ee", "e", "f"});

	display_vec(result);
	cout<<"\n";

	cout<<"all_construct(\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\", [\"a\", \"aa\", \"aaa\", \"aaaa\", \"aaaaa\"]): ";

	result = all_construct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", new vector<string> {"a", "aa", "aaa", "aaaa", "aaaaa"}); // This will take forever.

	display_vec(result);
	cout<<"\n";

	return 0;
}