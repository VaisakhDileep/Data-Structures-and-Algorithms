/*
Created by  : Vaisakh Dileep
Date        : 6, May, 2021
Description : This program validates a string with only numbers.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

bool validate_string(char S[])
{
    while(*S)
    {
        if(not((*S >= '0') and (*S <= '9')))
        {
            return false;
        }
        S++;
    }

    return true;
}

int main()
{
    char S1[MAX_SIZE] {"1234567"};

    cout<<"validate_string(\"1234567\"): "<<validate_string(S1)<<"\n";

    char S2[MAX_SIZE] {"!@#$%^&*(K"};

    cout<<"validate_string(\"!@#$%^&*(K\"): "<<validate_string(S2)<<"\n";

    return 0;
}