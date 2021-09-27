/*
Created by  : Vaisakh Dileep
Date        : 8, August, 2021
Description : This program creates the huffman table for the given message.
*/

#include<iostream>

#include<unordered_map>

#include<queue>

#include<vector>

using namespace std;

struct Node
{
    char character;

    int frequency;

    Node *left;

    Node *right;
};

struct Huffman_Table
{
    unordered_map<char, string> table {};
};

void extract_huffman_code(Node *node, Huffman_Table *huffman_table, string code = "")
{
    if(node == nullptr)
    {
        return ;
    }

    if(node->character != '~')
    {
        huffman_table->table[node->character] = code;
    }

    extract_huffman_code(node->left, huffman_table, code + "0");

    extract_huffman_code(node->right, huffman_table, code + "1");
}

class Custom_Compare // Custom compare function for "priority_queue".
{
public:
    bool operator() (Node *node_1, Node *node_2)
    {
        return (node_1->frequency > node_2->frequency); // Priority is higher for nodes with lesser "frequency".
    }
};

Huffman_Table* create_huffman_table(string message) // "message" is case-sensitive.
{
    if(message.size() <= 1)
    {
        throw string {"ERROR - Invalid operation, huffman table cannot be constructed for strings with length lesser than or equal to 1 ....."};
    }

    Huffman_Table *huffman_table {new Huffman_Table {}};

    unordered_map<char, int> character_frequency {};

    for(int i {0}; i < message.size(); i++)
    {
        if(character_frequency.find(message.at(i)) != character_frequency.end())
        {
            character_frequency[message.at(i)]++;
        }
        else
        {
            character_frequency[message.at(i)] = 1;
        }
    }

    priority_queue<Node*, vector<Node*>, Custom_Compare> min_heap {};

    for(auto itr {character_frequency.begin()}; itr != character_frequency.end(); itr++)
    {
        min_heap.push(new Node {itr->first, itr->second, nullptr, nullptr});
    }

    while(min_heap.size() != 1) // The last element will be the root of the tree.
    {
        Node *left_node {min_heap.top()};

        min_heap.pop();

        Node *right_node {min_heap.top()};

        min_heap.pop();

        Node *new_node {new Node {'~', left_node->frequency + right_node->frequency, left_node, right_node}};

        min_heap.push(new_node);
    }

    extract_huffman_code(min_heap.top(), huffman_table);

    return huffman_table;
}

Huffman_Table* handle_create_huffman_table(string message)
{
    try
    {
        return create_huffman_table(message);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void display_huffman_table(Huffman_Table *huffman_table)
{
    if(huffman_table == nullptr)
    {
        return ;
    }

    for(auto itr {huffman_table->table.begin()}; itr != huffman_table->table.end(); itr++)
    {
        cout<<itr->first<<" : "<<itr->second<<"\n";
    }
}

int main()
{
    Huffman_Table *huffman_table {handle_create_huffman_table("Vaisakh")};

    display_huffman_table(huffman_table);

    return 0;
}