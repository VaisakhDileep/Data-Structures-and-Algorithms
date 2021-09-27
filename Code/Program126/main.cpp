/*
Created by  : Vaisakh Dileep
Date        : 22, May, 2021
Description : This program counts the number of nodes in a linked list.
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
    int count_nodes_linked_list(Linked_list *L)
    {
        if(L == nullptr)
        {
            return 0;
        }

        int count {0};

        Node *last {L->head};

        while(last != nullptr)
        {
            count++;

            last = last->next;
        }

        return count;
    }
}

namespace recursion
{
    int count_nodes_linked_list(Node *node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        else
        {
            return count_nodes_linked_list(node->next) + 1;
        }
    }

    int handle_count_nodes_linked_list(Linked_list *L)
    {
        if(L == nullptr)
        {
            return 0;
        }

        return count_nodes_linked_list(L->head);
    }
}

int main()
{
    Linked_list L1 {};

    create_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    cout<<"count_nodes_linked_list(L1) [iteration]: "<<iteration::count_nodes_linked_list(&L1)<<"\n";

    cout<<"handle_count_nodes_linked_list(L1) [recursion]: "<<recursion::handle_count_nodes_linked_list(&L1)<<"\n";

    return 0;
}