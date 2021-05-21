/*
Created by  : Vaisakh Dileep
Date		: 21, May, 2021
Description : This program represents a polynomial using arrays.
*/

#include<iostream>

using namespace std;

struct Term
{
	int coefficient;

	int exponent;
};

struct Polynomial
{
	int num_terms; // number of terms in the polynomial.

	Term *terms; // dynamically created array of "Term".
};

int main()
{
	Polynomial P {4, new Term[5] {{4, 4}, {2, 1}, {3, 3}, {1, 0}}};

	return 0;
}