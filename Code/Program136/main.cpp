/*
Created by  : Vaisakh Dileep
Date        : 25, May, 2021
Description : This program checks if a linked list is sorted.
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

bool is_sorted_linked_list(Linked_list *L, int flag = 0) // flag = 0, for ascending order. flag = 1, for descending order.
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is not valid ....."};
    }
    
    if(L->head == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is empty ....."};
    }

    Node *last {L->head->next};

    int x {L->head->data};

    if(flag == 0)
    {
        while(last != nullptr)
        {
            if(last->data < x)
            {
                return false;
            }

            x = last->data;

            last = last->next;
        }
    }
    else if(flag == 1)
    {
        while(last != nullptr)
        {
            if(last->data > x)
            {
                return false;
            }

            x = last->data;

            last = last->next;
        }
    }
    else
    {
        throw string {"ERROR - Invalid flag, flag should be either 0 or 1 ....."};
    }

    return true;
}

bool handle_is_sorted_linked_list(Linked_list *L, int flag = 0)
{
    try
    {
        return is_sorted_linked_list(L, flag);
    }
    catch(string &ex)
    {
        cout<<ex;

        return false;
    }
}

int main()
{
    Linked_list L1 {};
    Linked_list L2 {};
    Linked_list L3 {};
    Linked_list L4 {};

    create_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);
    create_linked_list(&L2, new int[6] {6, 5, 4, 3, 2, 1}, 6);
    create_linked_list(&L3, new int[6] {2, 2, 1, 6, 5, 4}, 6);

    cout<<"is_sorted_linked_list(L1): "<<handle_is_sorted_linked_list(&L1)<<"\n";
    cout<<"is_sorted_linked_list(L2): "<<handle_is_sorted_linked_list(&L2)<<"\n";
    cout<<"is_sorted_linked_list(L3): "<<handle_is_sorted_linked_list(&L3)<<"\n\n";

    cout<<"is_sorted_linked_list(L1, 1): "<<handle_is_sorted_linked_list(&L1, 1)<<"\n";
    cout<<"is_sorted_linked_list(L2, 1): "<<handle_is_sorted_linked_list(&L2, 1)<<"\n";
    cout<<"is_sorted_linked_list(L3, 1): "<<handle_is_sorted_linked_list(&L3, 1)<<"\n\n";

    cout<<"is_sorted_linked_list(L1, 3): "<<handle_is_sorted_linked_list(&L1, 2)<<"\n\n";

    cout<<"is_sorted_linked_list(nullptr): "<<handle_is_sorted_linked_list(nullptr)<<"\n\n";

    cout<<"is_sorted_linked_list(L4): "<<handle_is_sorted_linked_list(&L4)<<"\n";

    return 0;
}