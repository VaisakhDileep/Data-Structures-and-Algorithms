/*
Created by  : Vaisakh Dileep
Date		: 17, July, 2021
Description : This program implements all_construct(target, word_bank) using tabulation.
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

vector<vector<string>*>* copy_vector(vector<vector<string>*> *vec)
{
	if(vec == nullptr)
	{
		return nullptr;
	}

	vector<vector<string>*> *new_vec {new vector<vector<string>*> {}};

	for(unsigned long long i {0}; i < vec->size(); i++)
	{
		new_vec->push_back(new vector<string> {});

		for(unsigned long long j {0}; j < vec->at(i)->size(); j++)
		{
			new_vec->at(i)->push_back(vec->at(i)->at(j));
		}
	}

	return new_vec;
}

vector<vector<string>*>* all_construct(string target, vector<string> *word_bank)
{
	vector<vector<vector<string>*>*> table((target.size() + 1), nullptr);

	table.at(0) = new vector<vector<string>*> {new vector<string> {}};

	for(unsigned long long i {0}; i < table.size(); i++)
	{
		if(table.at(i) != nullptr)
		{
			for(string word : *word_bank)
			{
				string suffix_word {target.substr(i, word.size())};

				if(word == suffix_word)
				{
					if(table.at(i + word.size()) == nullptr)
					{
						table.at(i + word.size()) = new vector<vector<string>*> {};
					}

					for(vector<string> *vec : *copy_vector(table.at(i)))
					{
						vec->push_back(word);

						table.at(i + word.size())->push_back(vec); // No need to do bounds checking because "suffix_word" will do it for us.
					}
				}
			}
		}
	}

	return table.at(target.size());
}

int main()
{
	vector<vector<string>*> *result {};

	cout<<"all_construct(\"abcdeef\", [\"a\", \"bcd\", \"ee\", \"e\", \"f\"]): ";

	result = all_construct("abcdeef", new vector<string> {"a", "bcd", "ee", "e", "f"});

	display_vec(result);
	cout<<"\n";

	cout<<"all_construct(\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\", [\"a\", \"aa\", \"aaa\", \"aaaa\", \"aaaaa\"]): ";

	result = all_construct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", new vector<string> {"a", "aa", "aaa", "aaaa", "aaaaa"}); // Notice here too it will take forever, sometimes memoization is preferred.

	display_vec(result);
	cout<<"\n";

	return 0;
}