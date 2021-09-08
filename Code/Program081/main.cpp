/*
Created by  : Vaisakh Dileep
Date		: 5, May, 2021
Description : This program counts the number of vowels in a string.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

int count_vowels_string(char S[])
{
	int count {0};

	while(*S)
	{
		if((*S == 'a') or (*S == 'e') or (*S == 'i') or (*S == 'o') or (*S == 'u') or (*S == 'A') or (*S == 'E') or (*S == 'I') or (*S == 'O') or (*S == 'U'))
		{
			count++;
		}

		S++;
	}

	return count;
}

int main()
{
	char S1[MAX_SIZE] {"Vaisakh Dileep"};

	cout<<"count_vowels_string(\"Vaisakh Dileep\"): "<<count_vowels_string(S1)<<"\n";

	return 0;
}