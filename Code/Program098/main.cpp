/*
Created by  : Vaisakh Dileep
Date        : 11, May, 2021
Description : This program checks if two strings are anagrams.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

int length_string(char S[])
{
    int i {0};

    while(S[i] != '\0')
    {
        i++;
    }

    return i;
}

void copy_string(char original[], char duplicate[]) // Make sure that "duplicate" should be modifiable.
{
    while(*original)
    {
        *duplicate = *(original++);

        duplicate++;
    }

    *duplicate = '\0';
}

void uppercase_to_lowercase_string(char S[]) // Make sure that "S" should be modifiable.
{
    while(*S)
    {
        if((*S >= 'A') and (*S <= 'Z'))
        {
            *S = *S + ('a' - 'A');
        }

        S++;
    }
}

void extract_alphabets_string(char original[], char modified_string[]) // Make sure "modified_string" should be modifiable. 
{
    char A[MAX_SIZE] {};

    copy_string(original, A);

    uppercase_to_lowercase_string(A);

    char *iterator {A};

    while(*iterator)
    {
        if((*iterator >= 'a') and (*iterator <= 'z'))
        {
            *modified_string = *iterator;

            ++modified_string;
        }

        iterator++;
    }

    *modified_string = '\0';
}

bool anagram_string(char S1[], char S2[])
{
    char A[MAX_SIZE] {};
    char B[MAX_SIZE] {};

    extract_alphabets_string(S1, A);
    extract_alphabets_string(S2, B);

    int H[26] {}; // Hash Table is initialized to '0'.

    if(length_string(A) != length_string(B))
    {
        return false;
    }

    for(int i {0}; A[i] != '\0'; i++)
    {
        H[A[i] - 'a']++;
    }

    for(int i {0}; B[i] != '\0'; i++)
    {
        H[B[i] - 'a']--;

        if(H[B[i] - 'a'] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cout<<"anagram_string(\"Debit card\", \"Bad credit\"): "<<anagram_string("Debit card", "Bad credit")<<"\n";

    cout<<"anagram_string(\"credit\", \"reddit\"): "<<anagram_string("credit", "reddit")<<"\n";

    return 0;
}