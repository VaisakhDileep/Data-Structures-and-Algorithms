/*
Created by  : Vaisakh Dileep
Date		: 5, August, 2021
Description : This program creates a trie.
*/

#include<iostream>

using namespace std;

struct Trie_Node
{
	char data {}; // "data" could be anything.

	Trie_Node *children[26] {}; // At most it will have 26 child nodes, since there are 26 english alphabets. All are initialized to "nullptr".

	bool end_of_word {false}; // This flag checks if we have reached the end of the word. It is initialized to "false".
};

struct Trie
{
	Trie_Node *root {}; // The "root" node doesn't hold any value.
};

int main()
{
	Trie dictionary_1 {new Trie_Node {}};

	return 0;
}