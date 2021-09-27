/*
Created by  : Vaisakh Dileep
Date        : 6, May, 2021
Description : This program validates a string with only alphabets and numbers.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

bool validate_string(char S[])
{
    while(*S)
    {
        if((not((*S >= '0') and (*S <= '9'))) and (not(((*S >= 'A') and (*S <= 'Z')) or ((*S >= 'a') and (*S <= 'z')))))
        {
            return false;
        }

        S++;
    }

    return true;
}

int main()
{
    char S1[MAX_SIZE] {"123abcd"};

    cout<<"validate_string(\"123abcd\"): "<<validate_string(S1)<<"\n";

    char S2[MAX_SIZE] {"!@#$%^&*9K"};

    cout<<"validate_string(\"!@#$%^&*9K\"): "<<validate_string(S2)<<"\n";

    return 0;
}