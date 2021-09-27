/*
Created by  : Vaisakh Dileep
Date        : 6, May, 2021
Description : This program reverses a string.
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

void reverse_string(char S[]) // Make sure that "S" should be modifiable.
{
    char temp[MAX_SIZE] {};

    copy_string(S, temp);

    for(int i {length_string(S) - 1}, j {0}; i >= 0; i--, j++)
    {
        S[j] = temp[i];
    }
}

int main()
{
    char S1[MAX_SIZE] {"Vaisakh"};

    cout<<"S1: "<<S1<<"\n";

    reverse_string(S1);

    cout<<"S1: "<<S1<<"\n";

    return 0;
}