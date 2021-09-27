/*
Created by  : Vaisakh Dileep
Date        : 5, May, 2021
Description : This program converts all the upper-case characters to lower-case in a string.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

void uppercase_to_lowercase_string(char S[]) // Make sure that "S" should be modifiable.
{
    while(*S)
    {
        if((*S >= 'A') and (*S <= 'Z'))
        {
            *S = *S + ('a' - 'A'); // 'a' comes after 'A' in the ascii table.
        }

        S++;
    }
}

int main()
{
    char S1[MAX_SIZE] {"VAISakh DILEep"};

    cout<<"S1: "<<S1<<"\n";

    uppercase_to_lowercase_string(S1);

    cout<<"S1: "<<S1<<"\n";

    return 0;
}