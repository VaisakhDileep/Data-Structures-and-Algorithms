/*
Created by  : Vaisakh Dileep
Date        : 5, May, 2021
Description : This program toggles the characters(upper-case->lower-case and lower-case->upper-case) in a string.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

void toggle_case_string(char S[]) // Make sure that "S" should be modifiable.
{
    while(*S)
    {
        if((*S >= 'A') and (*S <= 'Z'))
        {
            *S = *S + ('a' - 'A'); // 'a' comes after 'A' in the ascii table.
        }
        else if((*S >= 'a') and (*S <= 'z'))
        {
            *S = *S - ('a' - 'A');
        }

        S++;
    }
}

int main()
{
    char S1[MAX_SIZE] {"VAISakh DILEep"};

    cout<<"S1: "<<S1<<"\n";

    toggle_case_string(S1);

    cout<<"S1: "<<S1<<"\n";

    return 0;
}