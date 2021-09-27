/*
Created by  : Vaisakh Dileep
Date        : 22, May, 2021
Description : This program finds the sum of all the elements in a linked list.
*/

#include<iostream>

using namespace std;

struct Node
{
    int data;

    Node *next;
};

struct Linked_list
{
    Node *head;
};

void create_linked_list(Linked_list *L, int *A, int size)
{
    if(size == 0)
    {
        return ;
    }

    L->head = new Node {A[0], nullptr};

    Node *last {L->head};

    for(int i {1}; i < size; i++)
    {
        last->next = new Node {A[i], nullptr};

        last = last->next;
    }
}

namespace iteration
{
    int sum_linked_list(Linked_list *L)
    {
        if(L == nullptr)
        {
            return 0;
        }

        int sum {0};

        Node *last {L->head};

        while(last != nullptr)
        {
            sum += last->data;

            last = last->next;
        }

        return sum;
    }
}

namespace recursion
{
    int sum_linked_list(Node *node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        else
        {
            return sum_linked_list(node->next) + node->data;
        }
    }

    int handle_sum_linked_list(Linked_list *L)
    {
        if(L == nullptr)
        {
            return 0;
        }

        return sum_linked_list(L->head);
    }
}

int main()
{
    Linked_list L1 {};

    create_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    cout<<"sum_linked_list(L1) [iteration]: "<<iteration::sum_linked_list(&L1)<<"\n";

    cout<<"handle_sum_linked_list(L1) [recursion]: "<<recursion::handle_sum_linked_list(&L1)<<"\n";

    return 0;
}