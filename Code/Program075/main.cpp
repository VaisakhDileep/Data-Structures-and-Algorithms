/*
Created by  : Vaisakh Dileep
Date		: 4, May, 2021
Description : This program helps to understand how to create a string.
*/

#include<iostream>

#define MAX_SIZE 10'000

using namespace std;

int main()
{
	char S1[MAX_SIZE] {"abcd"}; // "abcd\0"

	S1[0] = 'A';

	cout<<"S1: "<<S1<<"\n";

	char *S2 {"abcd"}; // "abcd/0"

	// S2[0] = 'A'; // This will give an exception and stops the program because when using "char *S2" we allocate the string on heap which is read only.

	cout<<"S2: "<<S2<<"\n";

	const char *S3 {"abcd"}; // Preferred for read only strings. Don't use "char *S3 {"abcd"}" as it may be confusing since it is also read only.

	// S3[0] = 'A'; // This will give an error rather than an exception.

	cout<<"S3: "<<S3<<"\n";

	char S4[MAX_SIZE] {'a', 'b', 'c', 'd', '\0'};

	cout<<"S4: "<<S4<<"\n";

	char S5[MAX_SIZE] {97, 98, 99 ,100, 0};

	cout<<"S5: "<<S5<<"\n";

	char S6[] {"abcd"}; // Automatically compute size of the string.

	cout<<"S6: "<<S6<<"\n";

	return 0;
}