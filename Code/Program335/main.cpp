/*
Created by  : Vaisakh Dileep
Date        : 14, July, 2021
Description : This program implements count_construct(target, word_bank) using recursion.
*/

// count_construct(target, word_bank) return the number of ways that the "target" can constructed by concatenating the elements from the "word_bank" array(elements can be used as many times as needed).

#include<iostream>

#include<vector>

using namespace std;

long long count_construct(string target, vector<string> *word_bank)
{
    if(target == "")
    {
        return 1;
    }

    long long count {0};

    for(string word : *word_bank)
    {
        string suffix_word {target.substr(0, word.length())};

        if(suffix_word == word)
        {
            count += count_construct(target.substr(word.length(), target.length()), word_bank);
        }
    }

    return count; // If the for loop fails(all the branches result in '0'), "count" wouldn't be updated, it will default to '0'.
}

int main()
{
    cout<<"count_construct(\"abcdeef\", [\"a\", \"bcd\", \"ee\", \"e\", \"f\"]): "<<count_construct("abcdeef", new vector<string> {"a", "bcd", "ee", "e", "f"})<<"\n";

    cout<<"count_construct(\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\", [\"a\", \"aa\", \"aaa\", \"aaaa\", \"aaaaa\"]): "<<count_construct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", new vector<string> {"a", "aa", "aaa", "aaaa", "aaaaa"})<<"\n"; // This will take forever.

    return 0;
}