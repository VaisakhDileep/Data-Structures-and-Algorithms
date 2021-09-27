/*
Created by  : Vaisakh Dileep
Date        : 6, May, 2021
Description : This program counts the number of words in a string.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

int count_words_string(char S[])
{
    if(*S == '\0')
    {
        return 0;
    }

    int count {1};

    while(*S)
    {
        if((*S == ' ') and (*(S - 1) != ' '))
        {
            count++;
        }

        S++;
    }

    return count;
}

int main()
{
    char S1[MAX_SIZE] {"Vaisakh  Dileep"};

    cout<<"count_words_string(\"Vaisakh  Dileep\"): "<<count_words_string(S1)<<"\n";

    return 0;
}