/*
Created by  : Vaisakh Dileep
Date		: 5, August, 2021
Description : This program extracts all the words in a trie.
*/

#include<iostream>

#include<algorithm>

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

void insert_trie(Trie *trie, string word)
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

				crawler->data = word.at(i);

				crawler = crawler->children[index];
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

int main()
{
	return 0;
}