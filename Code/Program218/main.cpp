/*
Created by  : Vaisakh Dileep
Date        : 9, June, 2021
Description : This program creates a binary tree from user using queue.
*/

#include<iostream>

#include<queue>

using namespace std;

struct Node;

// namespace queue
// {
//     struct Node
//     {
//         ::Node *data;

//         Node *next;
//     };

//     struct Queue
//     {
//         Node *front {nullptr};

//         Node *rear {nullptr};
//     };

//     bool is_empty_queue(Queue *Q)
//     {
//         if(Q == nullptr)
//         {
//             throw string {"ERROR - Invalid operation, queue is not valid ....."};
//         }

//         if(Q->front == nullptr)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

//     bool is_full_queue(Queue *Q)
//     {
//         Node *temp = new Node {nullptr, nullptr};

//         if(temp == NULL)
//         {
//             return true;
//         }
//         else
//         {
//             delete temp;

//             return false;
//         }
//     }

//     void enqueue(Queue *Q, ::Node *value)
//     {
//         if(Q == nullptr)
//         {
//             throw string {"ERROR - Invalid operation, queue is not valid ....."};
//         }

//         if(is_full_queue(Q))
//         {
//             throw string {"ERROR - Invalid operation, queue is full ....."};
//         }

//         if(Q->front == nullptr)
//         {
//             Q->front = Q->rear = new Node {value, nullptr};
//         }
//         else
//         {
//             Q->rear = Q->rear->next = new Node {value, nullptr};
//         }
//     }

//     ::Node* dequeue(Queue *Q)
//     {
//         if(Q == nullptr)
//         {
//             throw string {"ERROR - Invalid operation, queue is not valid ....."};
//         }

//         if(is_empty_queue(Q))
//         {
//             throw string {"ERROR - Invalid operation, queue is empty ....."};
//         }
//         else
//         {
//             ::Node* deleted_value {Q->front->data};

//             Node *temp {Q->front}; // To delete the dynamically allocated memory.

//             Q->front = Q->front->next;

//             if(Q->front == nullptr)
//             {
//                 Q->rear = nullptr;
//             }

//             delete temp;

//             return deleted_value;
//         }
//     }
// }

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

void create_binary_tree(Binary_Tree *T)
{
    int value {};

    queue<Node *> Q {};

    cout<<"Enter root value: ";

    cin>>value;

    T->root = new Node {nullptr, value, nullptr};

    Q.push(T->root);

    Node *popped_node {};

    while(!Q.empty())
    {
        popped_node = Q.front();

        Q.pop();

        cout<<"Enter left child for "<<popped_node->data<<": ";

        cin>>value;

// Enter "-2147483648" for empty node.

        if(value != -2147483648)
        {
            Node *temp {new Node {nullptr, value, nullptr}};

            popped_node->left_child = temp;

            Q.push(temp);
        }

        cout<<"Enter right child for "<<popped_node->data<<": ";

        cin>>value;

        if(value != -2147483648)
        {
            Node *temp {new Node {nullptr, value, nullptr}};

            popped_node->right_child = temp;

            Q.push(temp);
        }
    }
}

int main()
{
    Binary_Tree T {};

    create_binary_tree(&T);

    return 0;
}