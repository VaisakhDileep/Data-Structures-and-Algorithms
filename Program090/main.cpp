/*
Created by  : Vaisakh Dileep
Date		: 6, May, 2021
Description : This program checks if a word is a palindrome.
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

void reverse_string(char S[]) // Make sure that "S" should be modifiable
{
	for(int i {0}, j {length_string(S) - 1}; i < j; i++, j--)
	{
		swap(S[i], S[j]);
	}
}

bool palindrome_word(char S[])
{
	char A[MAX_SIZE] {}, R[MAX_SIZE] {};

	copy_string(S, A);
	copy_string(S, R);

	reverse_string(R);

	uppercase_to_lowercase_string(A);
	uppercase_to_lowercase_string(R);

	for(int i {0}; i < length_string(A); i++)
	{
		if(A[i] != R[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	char S1[MAX_SIZE] {"Racecar"};

	cout<<"palindrome_word(\"Racecar\"): "<<palindrome_word(S1)<<"\n";

	char S2[MAX_SIZE] {"Vaisakh"};

	cout<<"palindrome_word(\"Vaisakh\"): "<<palindrome_word(S2)<<"\n";

	return 0;
}