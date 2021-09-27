/*
Created by  : Vaisakh Dileep
Date        : 7, May, 2021
Description : This program identifies duplicate characters in a string.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

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

void identify_duplicate_characters_string(char S[])
{
    char A[MAX_SIZE] {};

    copy_string(S, A);

    uppercase_to_lowercase_string(A);

    int H {0}; // There are '26' characters(a - z), therefore we need 26 bits, since "int" has 32 bits, we use "int".

    cout<<"char -> index\n";

    for(int i {0}; A[i] != '\0'; i++)
    {
        if(not((A[i] >= 'a') and (A[i] <= 'z')))
        {
            continue;
        }

        int x {1};

        x = x << (A[i] - 'a');

        if(H & x) // Masking
        {
            cout<<A[i]<<"    -> "<<i<<"\n";
        }
        else
        {
            H = H | x; // Merging
        }
    }
}

int main()
{
    char S1[MAX_SIZE] {"Vaisakh Dileep"};

    cout<<S1<<": \n";

    identify_duplicate_characters_string(S1);

    return 0;
}