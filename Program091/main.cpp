/*
Created by  : Vaisakh Dileep
Date		: 6, May, 2021
Description : This program checks if a sentence is a palindrome.
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

void reverse_string(char S[]) // Make sure that "S" should be modifiable.
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

bool palindrome_sentence(char S[])
{
	char M1[MAX_SIZE] {};

	copy_string(S, M1);

	uppercase_to_lowercase_string(M1);

	char M2[MAX_SIZE] {};

	int j {0};

	for(int i {0}; i < length_string(M1); i++)
	{
		if((M1[i] >= 'a') and (M1[i] <= 'z'))
		{
			M2[j++] = M1[i];
		}
	}

	M2[j] = '\0';

	if(palindrome_word(M2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char S1[MAX_SIZE] {"Dammit, I'm Mad!"};

	cout<<"palindrome_sentence(\"Dammit, I'm Mad!\"): "<<palindrome_sentence(S1)<<"\n";

	char S2[MAX_SIZE] {"Vaisakh Dileep"};

	cout<<"palindrome_sentence(\"Vaisakh Dileep\"): "<<palindrome_sentence(S2)<<"\n";

	return 0;
}