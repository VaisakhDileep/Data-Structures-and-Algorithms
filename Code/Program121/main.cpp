/*
Created by  : Vaisakh Dileep
Date		: 21, May, 2021
Description : This program adds two polynomials.
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
	int num_terms;

	Term *terms;
};

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

void swap_terms(Polynomial *P, int i, int j)
{
	Term temp {P->terms[i]};

	P->terms[i] = P->terms[j];
	P->terms[j] = temp;
}

void make_polynomial_ascending(Polynomial *P)
{
	if(P == nullptr)
	{
		throw string {"ERROR - Invalid operation, polynomial is empty ....."};
	}

	for(int i {0}; i < (P->num_terms - 1); i++)
	{
		for(int j {i + 1}; j < P->num_terms; j++)
		{
			if(P->terms[j].exponent < P->terms[i].exponent)
			{
				swap_terms(P, i, j);
			}
		}
	}
}

Polynomial add_polynomials(Polynomial P1, Polynomial P2) // Note here we are passing a copy.
{
	Polynomial S {0, new Term[P1.num_terms + P2.num_terms]};

	int i {0}, j {0}, k {0};

	make_polynomial_ascending(&P1);
	make_polynomial_ascending(&P2);

	while((i < P1.num_terms) and (j < P2.num_terms))
	{
		if(P1.terms[i].exponent < P2.terms[j].exponent)
		{
			S.terms[k++] = P1.terms[i++];
		}
		else if(P1.terms[i].exponent > P2.terms[j].exponent)
		{
			S.terms[k++] = P2.terms[j++];
		}
		else
		{
			S.terms[k].exponent = P1.terms[i].exponent;

			S.terms[k++].coefficient = P1.terms[i++].coefficient + P2.terms[j++].coefficient;
		}
	}
	for(; i < P1.num_terms; i++)
	{
		S.terms[k++] = P1.terms[i];
	}
	for(; j < P2.num_terms; j++)
	{
		S.terms[k++] = P2.terms[j];
	}

	S.num_terms = k;

	return S;
}

int main()
{
	Polynomial P1 {4, new Term[5] {{4, 4}, {2, 1}, {3, 3}, {1, 0}}};
	Polynomial P2 {4, new Term[5] {{4, 4}, {2, 7}, {3, 9}, {7, 0}}};

	cout<<"P1: ";
	display_polynomial(&P1);
	cout<<"\n";

	cout<<"P2: ";
	display_polynomial(&P2);
	cout<<"\n\n";

	Polynomial S {add_polynomials(P1, P2)};

	cout<<"S = P1 + P2\n\n";

	cout<<"S: ";
	display_polynomial(&S);
	cout<<"\n";

	return 0;
}