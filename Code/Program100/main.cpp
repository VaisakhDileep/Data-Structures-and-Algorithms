/*
Created by  : Vaisakh Dileep
Date		: 12, May, 2021
Description : This program finds all the permutations of a string(using swap function).
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

void permutations_string(char S[], int l, int h)
{
	if(l == h)
	{
		cout<<S<<"\n";
	}
	else
	{
		for(int i {l}; i <= h; i++) // 'h' is not necessary but is is useful when we want to find the permutations for a subset of the string.
		{
			swap(S[i], S[l]); // Swapping here changes the string since we are passing the string by reference.

			permutations_string(S, l + 1, h);

			swap(S[i], S[l]); // Make sure to swap them back when returning to preserve the string.
		}
	}
}

void handle_permutations_string(char S[], int l = 0, int h = -1)
{
	if((h == -1) and (l >= 0) and (l <= (length_string(S) - 1)))
	{
		permutations_string(S, l, (length_string(S) - 1));
	}
	else if ((h >= 0) and (l >= 0) and (l <= h))
	{
		permutations_string(S, l, h);
	}
	else
	{
		cout<<"ERROR - Invalid operation, invalid parameters .....";
	}
}

int main()
{
	char S1[MAX_SIZE] {"ABC"};

	cout<<"Permutations possible for \"ABC\": \n";
	handle_permutations_string(S1);

	char S2[MAX_SIZE] {"1234"};

	cout<<"Permutations possible for \"1234\": \n";
	handle_permutations_string(S2);

	return 0;
}