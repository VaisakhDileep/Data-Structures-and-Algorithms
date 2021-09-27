/*
Created by  : Vaisakh Dileep
Date        : 6, May, 2021
Description : This program reverses a string(using swap function).
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

void swap(char &x, char &y)
{
    char temp {y};

    y = x;
    x = temp;
}

int length_string(char S[])
{
    int i {0};

    while(S[i] != '\0')
    {
        i++;
    }

    return i;
}

void reverse_string(char S[]) // Make sure that "S" should be modifiable.
{
    for(int i {0}, j {length_string(S) - 1}; i < j; i++, j--)
    {
        swap(S[i], S[j]);
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