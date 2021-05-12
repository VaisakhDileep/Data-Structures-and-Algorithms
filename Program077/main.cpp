/*
Created by  : Vaisakh Dileep
Date		: 4, May, 2021
Description : This program copies a string.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

void copy_string(char original[], char duplicate[]) // Make sure that "duplicate" should be modifiable.
{
	while(*original)
	{
		*duplicate = *(original++);

		duplicate++; // We can't use post-increment notation as l-value, because post-increment does not return reference(however pre-increment can be used as l-value as they return reference).
	}

	*duplicate = '\0';
}

int main()
{
	char S1[MAX_SIZE] {"Vaisakh Dileep"};

	char S1_copy[MAX_SIZE] {};

	copy_string(S1, S1_copy);

	cout<<"S1: "<<S1<<"\n";

	cout<<"S1_copy: "<<S1_copy<<"\n";

	return 0;
}