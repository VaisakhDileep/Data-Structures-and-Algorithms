/*
Created by  : Vaisakh Dileep
Date		: 6, May, 2021
Description : This program compares two strings lexicographically.
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

int compare_strings(char S1[], char S2[])
{
	char A[MAX_SIZE] {}, B[MAX_SIZE] {};

	int i {0};

	copy_string(S1, A);
	copy_string(S2, B);

	uppercase_to_lowercase_string(A);
	uppercase_to_lowercase_string(B);

	for(; (A[i] != '\0') and (B[i] != '\0'); i++)
	{
		if(A[i] != B[i])
		{
			break;
		}
	}

	if(A[i] == B[i])
	{
		return 0; // '0' means S1 and S2 are equal lexicographically.
	}
	else if(A[i] < B[i])
	{
		return -1; // '-1' means S1 is lesser than S2 lexicographically.
	}
	else
	{
		return 1; // '1' means S1 is greater than S2 lexicographically.
	}
}

int main()
{
	char S1[MAX_SIZE] {"abcd"}, S2[MAX_SIZE] {"bcde"}, S3[MAX_SIZE] {"ab"}, S4[MAX_SIZE] {"ABCD"};

	cout<<"compare_strings(S1, S2): "<<compare_strings(S1, S2)<<"\n";

	cout<<"compare_strings(S2, S1): "<<compare_strings(S2, S1)<<"\n";

	cout<<"compare_strings(S1, S3): "<<compare_strings(S1, S3)<<"\n";

	cout<<"compare_strings(S1, S4): "<<compare_strings(S1, S4)<<"\n";

	return 0;
}