/*
Created by  : Vaisakh Dileep
Date        : 4, May, 2021
Description : This program finds the length of a string.
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

int main()
{
    char S1[MAX_SIZE] {"Vaisakh Dileep"};

    cout<<"length_string("<<S1<<"): "<<length_string(S1)<<"\n";

    char *S2 {"Prison Mike"};

    cout<<"length_string("<<S2<<"): "<<length_string(S2)<<"\n";

    return 0;
}