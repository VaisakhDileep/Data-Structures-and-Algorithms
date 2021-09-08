/*
Created by  : Vaisakh Dileep
Date		: 21, May, 2021
Description : This program evaluates a polynomial.
*/

#include<iostream>

#include<math.h>

using namespace std;

struct Term
{
	int coefficient;

	int exponent;
};

struct Polynomial
{
	int num_terms;

	Term *terms;
};

double evaluate_polynomial(Polynomial *P, double x)
{
	if(P == nullptr)
	{
		throw string {"ERROR - Invalid operation, polynomial is empty ....."};
	}

	double result {0.0};

	for(int i {0}; i < P->num_terms; i++)
	{
		result += P->terms[i].coefficient * (pow(x, P->terms[i].exponent));
	}

	return result;
}

double handle_evaluate_polynomial(Polynomial *P, double x)
{
	try
	{
		return evaluate_polynomial(P, x);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

void display_polynomial(Polynomial *P)
{
	if((P == nullptr) or (P->num_terms == 0))
	{
		return ;
	}

	int i {0};

	for(; i < (P->num_terms - 1); i++)
	{
		cout<<P->terms[i].coefficient<<"x^"<<P->terms[i].exponent<<" + ";
	}

	cout<<P->terms[i].coefficient<<"x^"<<P->terms[i].exponent;
}

int main()
{
	Polynomial P {4, new Term[5] {{4, 4}, {2, 1}, {3, 3}, {1, 0}}};

	cout<<"P: ";
	display_polynomial(&P);
	cout<<"\n";

	double result {handle_evaluate_polynomial(&P, 2)};

	cout<<"P(2): "<<result<<"\n";

	result = handle_evaluate_polynomial(&P, 2.1);

	cout<<"P(2.1): "<<result<<"\n";

	return 0;
}