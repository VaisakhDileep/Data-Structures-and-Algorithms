/*
Created by  : Vaisakh Dileep
Date        : 7, August, 2021
Description : This program counts the number of strings with given prefix using trie.
*/

#include<iostream>

#include<algorithm>

using namespace std;

struct Trie_Node
{
    int prefix_count {0}; // Keeps track of the prefix count of the word.

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

                (crawler->prefix_count)++;
            }
            else
            {
                crawler = crawler->children[index];

                (crawler->prefix_count)++;
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

int prefix_count_trie(Trie *trie, string word)
{
    if((trie == nullptr) or (trie->root == nullptr))
    {
        throw string {"ERROR - Invalid operation, trie is not valid ....."};
    }

    transform(word.begin(), word.end(), word.begin(), ::tolower);

    Trie_Node *crawler {trie->root};

    for(int i {0}; i < word.size(); i++)
    {
        if(isalpha(word.at(i)))
        {
            int index {word.at(i) - 'a'};

            if((crawler->children[index] == nullptr) or (crawler->children[index]->prefix_count == 0))
            {
                throw string {"ERROR - Invalid operation, given word not present in trie ....."};
            }

            crawler = crawler->children[index];
        }
        else
        {
            throw string {"ERROR - Invalid operation, given word contains non negative characters ....."};
        }
    }

    return crawler->prefix_count;
}

int handle_prefix_count_trie(Trie *trie, string word)
{
    try
    {
        return prefix_count_trie(trie, word);
    }
    catch(string &ex)
    {
        cout<<ex;
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

    cout<<"handle_prefix_count_trie(&dictionary_1, \"m\"): "<<handle_prefix_count_trie(&dictionary_1, "m")<<"\n";

    return 0;
}