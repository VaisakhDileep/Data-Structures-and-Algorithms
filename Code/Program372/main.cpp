/*
Created by  : Vaisakh Dileep
Date		: 6, August, 2021
Description : This program displays all the words in a trie.
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

void display_all_words_trie(Trie_Node *trie_node, string word, int level)
{
	if(trie_node->end_of_word == true)
	{
		// word += trie_node->data; // For our trie data structure we store the present character in "data", this is one way of retrieving the word.

		cout<<word<<" ";
	}

	for(int i {0}; i < 26; i++)
	{
		if(trie_node->children[i] != nullptr)
		{
			if(word.size() == level)
			{
				word += i + 'a';

				// word += trie_node->data; // For our trie data structure we store the present character in "data", this is one way of retrieving the word.
			}
			else
			{
				word[level] = i + 'a';

				// word[level] = trie_node->data; // For our trie data structure we store the present character in "data", this is one way of retrieving the word.
			}

			display_all_words_trie(trie_node->children[i], word, level + 1);
		}
	}
}

void handle_display_all_words_trie(Trie *trie)
{
	if((trie == nullptr) or (trie->root == nullptr))
	{
		cout<<"ERROR - Invalid operation, trie is not valid .....";
	}

	display_all_words_trie(trie->root, "", 0);
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

	cout<<"dictionary 1: ";
	handle_display_all_words_trie(&dictionary_1);

	return 0;
}