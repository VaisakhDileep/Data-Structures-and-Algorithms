/*
Created by  : Vaisakh Dileep
Date        : 9, June, 2021
Description : This program displays a binary tree using in-order traversal using stack.
*/

#include<iostream>

using namespace std;

struct Node;

namespace stack
{
    struct Node
    {
        ::Node *data;

        Node *next;
    };

    struct Stack
    {
        Node *top;
    };

    bool is_full_stack(Stack *stk)
    {
        Node *temp {new Node {nullptr, nullptr}};

        if(temp == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_empty_stack(Stack *stk)
    {
        if(stk == nullptr)
        {
            throw string {"ERROR - Invalid operation, stack is not valid ....."};
        }

        if(stk->top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push_stack(Stack *stk, ::Node *value)
    {
        if(stk == nullptr)
        {
            throw string {"ERROR - Invalid operation, stack is not valid ....."};
        }

        if(is_full_stack(stk))
        {
            throw string {"ERROR - Invalid operation, stack if full ....."};
        }

        if(stk->top == nullptr)
        {
            stk->top = new Node {value, nullptr};
        }
        else
        {
            Node *temp {new Node {value, nullptr}};

            temp->next = stk->top;

            stk->top = temp;
        }
    }

    ::Node* pop_stack(Stack *stk)
    {
        if(stk == nullptr)
        {
            throw string {"ERROR - Invalid operation, stack is not valid ....."};
        }

        if(stk->top == nullptr)
        {
            throw string {"ERROR - Invalid operation, stack is empty ....."};
        }

        ::Node* deleted_value {stk->top->data};

        Node *temp {stk->top};

        stk->top = stk->top->next;

        delete temp;

        return deleted_value;
    }
}

struct Node
{
    Node *left_child;

    int data;

    Node *right_child;
};

struct Binary_Tree
{
    Node *root;
};

void create_binary_tree(Node **node, int i, int *A, int size)
{
    if((i < size) and (A[i] != INT_MIN))
    {
        *node = new Node {nullptr, A[i], nullptr};

        create_binary_tree(&((*node)->left_child), (2 * (i + 1)) - 1, A, size);

        create_binary_tree(&((*node)->right_child), 2 * (i + 1), A, size);
    }
}

void handle_create_binary_tree(Binary_Tree *T, int *A, int size)
{
    create_binary_tree(&(T->root), 0, A, size);
}

void display_binary_tree(Binary_Tree *T) // in-order traversal
{
    if(T == nullptr)
    {
        return ;
    }

    stack::Stack stk {};

    Node *node {T->root};

    while((node != nullptr) or (!stack::is_empty_stack(&stk)))
    {
        if(node != nullptr)
        {
            stack::push_stack(&stk, node);

            node = node->left_child;
        }
        else
        {
            node = stack::pop_stack(&stk);

            cout<<node->data<<" ";

            node = node->right_child;
        }
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[6] {1, 2, 3, INT_MIN, 4, 5}, 6);

    cout<<"T[in-order]: ";
    display_binary_tree(&T);
    cout<<"\n";

    return 0;
}