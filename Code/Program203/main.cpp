/*
Created by  : Vaisakh Dileep
Date        : 6, June, 2021
Description : This program finds the height of a binary tree.
*/

#include<iostream>

#include<math.h>

using namespace std;

struct Binary_Tree
{
    int *A;

    int size {0};

    int alloted_size {0};
};

int height_binary_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
    }

    if(T->size == 0)
    {
        return 0;
    }

    int height {0};

    int total_nodes {0};

    while(total_nodes < T->size)
    {
        total_nodes += pow(2, height);

        height++;
    }

    return height - 1; // We are only counting the edges for height.
}

int handle_height_binary_tree(Binary_Tree *T)
{
    try
    {
        return height_binary_tree(T);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Binary_Tree T {new int[7] {1, 2, 3, INT_MIN, INT_MIN, 4, 5}, 7, 7};

    cout<<"handle_height_binary_tree(T): "<<handle_height_binary_tree(&T)<<"\n";

    return 0;
}