/*
Created by  : Vaisakh Dileep
Date		: 11, May, 2021
Description : This program extracts all the alphabets in their lower-case representation in a string.
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

void extract_alphabets_string(char original[], char modified_string[]) // Make sure "modified_string" should be modifiable. 
{
	char A[MAX_SIZE] {};

	copy_string(original, A);

	uppercase_to_lowercase_string(A);

	char *iterator {A};

	while(*iterator)
	{
		if((*iterator >= 'a') and (*iterator <= 'z'))
		{
			*modified_string = *iterator;

			++modified_string;
		}

		iterator++;
	}

	*modified_string = '\0';
}

int main()
{
	char S1[MAX_SIZE] {"11, May, 2021 : Vaisakh Dileep : 11.03 p.m"};

	extract_alphabets_string(S1, S1);

	cout<<"S1: "<<S1<<"\n";

	return 0;
}