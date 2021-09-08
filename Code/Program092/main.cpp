/*
Created by  : Vaisakh Dileep
Date		: 6, May, 2021
Description : This program counts the number of duplicate characters in a string.
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

void count_duplicate_characters_string(char S[])
{
	char A[MAX_SIZE] {};

	copy_string(S, A);

	uppercase_to_lowercase_string(A);

	int count {0};

	for(int i {0}; A[i] != '\0'; i++)
	{
		count = 1;

		if((A[i] >= 'a') and (A[i] <= 'z'))
		{
			for(int j {i + 1}; A[j] != '\0'; j++)
			{
				if(A[i] == A[j])
				{
					count++;
				}
			}

			if(count > 1)
			{
				cout<<A[i]<<" appeared "<<count<<" times.\n";
			}
		}
	}
}

int main()
{
	char S1[MAX_SIZE] {"Vaisakh Dileep"};

	cout<<S1<<": \n";

	count_duplicate_characters_string(S1);

	return 0;
}