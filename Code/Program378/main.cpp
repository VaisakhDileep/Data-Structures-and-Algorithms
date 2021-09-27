/*
Created by  : Vaisakh Dileep
Date        : 9, August, 2021
Description : This program performs huffman encoding for the given message.
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

string encoding_huffman(Huffman_Table *huffman_table, string message)
{
    if(message.size() <= 1)
    {
        throw string {"ERROR - Invalid operation, huffman encoding cannot be performed for strings with length lesser than or equal to 1 ....."};
    }

    string encoded_message {};

    for(int i {0}; i < message.size(); i++)
    {
        if(huffman_table->table.find(message.at(i)) != huffman_table->table.end())
        {
            encoded_message += huffman_table->table[message.at(i)];
        }
        else
        {
            throw string {"ERROR - Invalid operation, character key not present in the huffman table ....."};
        }
    }

    return encoded_message;
}

string handle_encoding_huffman(Huffman_Table *huffman_table, string message)
{
    try
    {
        return encoding_huffman(huffman_table, message);
    }
    catch(string &ex)
    {
        cout<<ex;

        return "";
    }
}

int main()
{
    string message {"Vaisakh Dileep"}, encoded_message {};

    Huffman_Table *huffman_table {handle_create_huffman_table(message)};

    encoded_message = handle_encoding_huffman(huffman_table, message);

    cout<<message<<" --after encoding--> "<<encoded_message<<"\n";

    return 0;
}