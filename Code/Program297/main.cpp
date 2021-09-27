/*
Created by  : Vaisakh Dileep
Date        : 5, July, 2021
Description : This program creates a binary max heap.
*/

#include<iostream>

using namespace std;

struct Binary_Max_Heap // binary max heap is a complete tree.
{
    int *A;

    int size {0};

    int alloted_size {0};
};

int main()
{
    Binary_Max_Heap heap {new int[8] {40, 30, 15, 20, 10, 12, 6, 5}, 8, 15};

    return 0;
}