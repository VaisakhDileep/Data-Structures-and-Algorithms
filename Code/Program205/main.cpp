/*
Created by  : Vaisakh Dileep
Date        : 6, June, 2021
Description : This program displays a binary tree.
*/

#include<iostream>

using namespace std;

struct Binary_Tree
{
    int *A;

    int size {0};

    int alloted_size {0};
};

void display_binary_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        return ;
    }

    for(int i {0}; i < T->size; i++)
    {
        if(T->A[i] == INT_MIN)
        {
            cout<<"- ";
        }
        else
        {
            cout<<T->A[i]<<" ";
        }
    }
}

int main()
{
    Binary_Tree T {new int[7] {1, 2, 3, INT_MIN, INT_MIN, 4, INT_MIN}, 7, 7};

    cout<<"T: ";
    display_binary_tree(&T);
    cout<<"\n";

    return 0;
}