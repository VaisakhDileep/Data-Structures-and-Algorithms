/*
Created by  : Vaisakh Dileep
Date		: 7, August, 2021
Description : This program demonstrates the auto complete feature using trie.
*/

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

struct Trie_Node
{
	char data {};

	Trie_Node *children[26] {};

	bool end_of_word {false};
};

struct Trie
{
	Trie_Node *root {};
};

void insert_word_trie(Trie *trie, string word)
{
	if(trie == nullptr)
	{
		throw string {"ERROR - Invalid operation, trie is not valid ....."};
	}

	if(trie->root == nullptr)
	{
		trie->root = new Trie_Node {};
	}

	if(word.size() == 0)
	{
		throw string {"ERROR - Invalid operation, given word is empty ....."};
	}

	transform(word.begin(), word.end(), word.begin(), ::tolower);

	Trie_Node *crawler {trie->root};

	for(int i {0}; i < word.size(); i++)
	{
		if(isalpha(word.at(i)))
		{
			int index {word.at(i) - 'a'};

			if(crawler->children[index] == nullptr)
			{
				crawler->children[index] = new Trie_Node {};

				crawler = crawler->children[index];

				crawler->data = word.at(i);
			}
			else
			{
				crawler = crawler->children[index];
			}
		}
		else
		{
			throw string {"ERROR - Invalid operation, given word contains non alphabet characters ....."};
		}
	}

	crawler->end_of_word = true;
}

void handle_insert_word_trie(Trie *trie, string word)
{
	try
	{
		insert_word_trie(trie, word);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

void suggestions_trie(Trie_Node *trie_node, vector<string> *suggestions, string prefix_word)
{
	if(trie_node == nullptr)
	{
		return ;
	}

	if(trie_node->end_of_word == true)
	{
		suggestions->push_back(prefix_word);
	}

	for(int i {0}; i < 26; i++)
	{
		if(trie_node->children[i] != nullptr)
		{
			prefix_word.push_back('a' + i);

			suggestions_trie(trie_node->children[i], suggestions, prefix_word);

			prefix_word.pop_back();
		}
	}
}

bool is_leaf_trie_node(Trie_Node *trie_node) // Checks if the "trie_node" is a leaf node or not.
{
	for(int i {0}; i < 26; i++)
	{
		if(trie_node->children[i] != nullptr)
		{
			return false;
		}
	}

	return true;
}

vector<string>* auto_complete_trie(Trie *trie, string query)
{
	if((trie == nullptr) or (trie->root == nullptr))
	{
		throw string {"ERROR - Invalid operation, trie is not valid ....."};
	}

	transform(query.begin(), query.end(), query.begin(), ::tolower);

	for(int i {0}; i < query.size(); i++)
	{
		if(!isalpha(query.at(i)))
		{
			throw string {"ERROR - Invalid operation, given word contains non alphabet characters ....."};
		}
	}

	vector<string> *suggestions {new vector<string> {}}; // List of all the suggestions 

	Trie_Node *crawler {trie->root};

	for(int i {0}; i < query.size(); i++)
	{
		int index {query.at(i) - 'a'};

		if(crawler->children[index] == nullptr) // If the "query" word is not present in the trie.
		{
			throw string {"ERROR - Invalid operation, given query leads to nowhere ....."};
		}
		else
		{
			crawler = crawler->children[index];
		}
	}

	if((crawler->end_of_word == true) and (is_leaf_trie_node(crawler) == true))
	{
		suggestions->push_back(query);

		return suggestions;
	}

	if(is_leaf_trie_node(crawler) == true) // In case if we remove the word by inverting the flag("end_of_word").
	{
		throw string {"ERROR - Invalid operation, given query leads to nowhere ....."};
	}
	else
	{
		suggestions_trie(crawler, suggestions, query);
	}

	return suggestions;
}

vector<string>* handle_auto_complete_trie(Trie *trie, string query)
{
	try
	{
		return auto_complete_trie(trie, query);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

void display_suggestions(vector<string> *suggestions)
{
	if(suggestions == nullptr)
	{
		return ;
	}

	for(int i {0}; i < suggestions->size(); i++)
	{
		cout<<suggestions->at(i)<<" ";
	}
}

int main()
{
	Trie dictionary_1 {};

	handle_insert_word_trie(&dictionary_1, "Michael");
	handle_insert_word_trie(&dictionary_1, "Micky");
	handle_insert_word_trie(&dictionary_1, "Franklin");
	handle_insert_word_trie(&dictionary_1, "Frank");
	handle_insert_word_trie(&dictionary_1, "Trevor");
	handle_insert_word_trie(&dictionary_1, "Trev");

	vector<string> *suggestions {handle_auto_complete_trie(&dictionary_1, "m")};

	cout<<"handle_auto_complete_trie(&dictionary_1, \"m\"): ";
	display_suggestions(suggestions);
	cout<<"\n";

	return 0;
}