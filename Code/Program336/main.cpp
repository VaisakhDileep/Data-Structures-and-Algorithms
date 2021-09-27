/*
Created by  : Vaisakh Dileep
Date        : 14, July, 2021
Description : This program implements count_construct(target, word_bank) using memoization.
*/

#include<iostream>

#include<vector>

#include<unordered_map>

using namespace std;

long long count_construct(string target, vector<string> *word_bank, unordered_map<string, long long> &memo)
{
    if(memo.find(target) != memo.end())
    {
        return memo[target];
    }

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
            count += count_construct(target.substr(word.length(), target.length()), word_bank, memo);
        }
    }

    memo[target] = count; // If the for loop fails(all the branches result in '0'), "count" wouldn't be updated, it will default to '0'.

    return count;
}

long long handle_count_construct(string target, vector<string> *word_bank)
{
    unordered_map<string, long long> memo {};

    return count_construct(target, word_bank, memo);
}

int main()
{
    cout<<"count_construct(\"abcdeef\", [\"a\", \"bcd\", \"ee\", \"e\", \"f\"]): "<<handle_count_construct("abcdeef", new vector<string> {"a", "bcd", "ee", "e", "f"})<<"\n";

    cout<<"count_construct(\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\", [\"a\", \"aa\", \"aaa\", \"aaaa\", \"aaaaa\"]): "<<handle_count_construct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", new vector<string> {"a", "aa", "aaa", "aaaa", "aaaaa"})<<"\n"; // Notice here we get the result without any delay.

    return 0;
}