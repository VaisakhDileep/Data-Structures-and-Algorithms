/*
Created by  : Vaisakh Dileep
Date        : 21, May, 2021
Description : This program displays a polynomial.
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

int main()
{
    Polynomial P {4, new Term[5] {{4, 4}, {2, 1}, {3, 3}, {1, 0}}};

    cout<<"P: ";
    display_polynomial(&P);
    cout<<"\n";

    return 0;
}