/*
Created by  : Vaisakh Dileep
Date		: 11, May, 2021
Description : This program finds all the permutations of a string(using brute-force).
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

void permutations_string(char S[], int k = 0) // 'k' is the level.
{
	static int A[MAX_SIZE] {}; // "A" is the availability array. It will check if the element at the level 'k' is selected or not. '0' means it is not selected.

	static char R[MAX_SIZE] {}; // "R" is the result array. It stores the result to be printed later.

	if(S[k] == '\0')
	{
		R[k] = '\0';

		cout<<R<<"\n";
	}
	else
	{
		for(int i {0}; S[i] != '\0'; i++)
		{
			if(A[i] == 0)
			{
				R[k] = S[i];

				A[i] = 1;

				permutations_string(S, k + 1);

				A[i] = 0;
			}
		}
	}
}

int main()
{
	char S1[MAX_SIZE] {"ABC"};

	cout<<"Permutations possible for \"ABC\": \n";
	permutations_string(S1);

	char S2[MAX_SIZE] {"1234"};

	cout<<"Permutations possible for \"1234\": \n";
	permutations_string(S2);

	return 0;
}