/*
Created by  : Vaisakh Dileep
Date        : 21, May, 2021
Description : This program makes the polynomial ascending.
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

void handle_make_polynomial_ascending(Polynomial *P)
{
    try
    {
        make_polynomial_ascending(P);
    }
    catch(string &ex)
    {
        cout<<ex;
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

    handle_make_polynomial_ascending(&P);

    cout<<"P[ascending order]: ";
    display_polynomial(&P);
    cout<<"\n";

    return 0;
}