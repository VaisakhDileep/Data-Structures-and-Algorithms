/*
Created by  : Vaisakh Dileep
Date        : 24, August, 2021
Description : This program demonstrates bin(bucket) sort.
*/

#include<iostream>

#include<vector>

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

void display_array(vector<int> *vec)
{
    if(vec == nullptr)
    {
        cout<<"[ ]";

        return ;
    }

    cout<<"[ ";
    for(int i {0}; i < vec->size(); i++)
    {
        cout<<vec->at(i)<<" ";
    }
    cout<<"]";
}

void bin_sort(vector<int> *vec) // Also called bucket sort.
{
    if(vec == nullptr)
    {
        throw string {"ERROR - Invalid operation, input array is not valid ....."};
    }

    if(vec->size() == 0)
    {
        throw string {"ERROR - Invalid operation, input array is empty ....."};
    }

    int max_element {vec->at(0)};

    for(int i {0}; i < vec->size(); i++)
    {
        if(vec->at(i) < 0)
        {
            throw string {"ERROR - Invalid operation, bin sort fails for input arrays with negative elements ....."};
        }

        max_element = max(max_element, vec->at(i));
    }

    vector<Node *> bin(max_element + 1, nullptr);

    for(int i {0}; i < vec->size(); i++)
    {
        if(bin[vec->at(i)] == nullptr)
        {
            bin[vec->at(i)] = new Node {vec->at(i), nullptr};

            continue;
        }

        Node *last {bin[vec->at(i)]};

        while(last->next != nullptr)
        {
            last = last->next;
        }

        last->next = new Node {vec->at(i), nullptr};
    }

    int j {0};

    for(int i {0}; i < bin.size();)
    {
        if(bin[i] == nullptr)
        {
            i++;
        }
        else
        {
            Node *last {bin[i]};

            while(last != nullptr)
            {
                vec->at(j++) = last->data;

                last = last->next;
            }

            i++;
        }
    }
}

void handle_bin_sort(vector<int> *vec)
{
    try
    {
        bin_sort(vec);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    vector<int> vec {2, 2, 1, 3, 4, 4, 5, 8, 19, 0, 0};

    cout<<"vec: ";
    display_array(&vec);
    cout<<"\n";

    handle_bin_sort(&vec);

    cout<<"vec: ";
    display_array(&vec);
    cout<<"\n";

    return 0;
}