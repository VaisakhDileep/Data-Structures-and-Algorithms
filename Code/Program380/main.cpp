/*
Created by  : Vaisakh Dileep
Date		: 9, August, 2021
Description : This program performs huffman decoding for the given message.
*/

#include<iostream>

#include<unordered_map>

#include<queue>

using namespace std;

struct Node
{
	char character;

	int frequency;

	Node *left;

	Node *right;
};

struct Huffman_Tree
{
	Node *root;
};

class Custom_Compare // Custom compare function for "priority_queue".
{
public:
	bool operator() (Node *node_1, Node *node_2)
	{
		return (node_1->frequency > node_2->frequency); // Priority is higher for nodes with lesser "frequency".
	}
};

Huffman_Tree* create_huffman_tree(string message)
{
	if(message.size() <= 1)
	{
		throw string {"ERROR - Invalid operation, huffman tree cannot be constructed for strings with length lesser than or equal to 1 ....."};
	}

	Huffman_Tree *huffman_tree(new Huffman_Tree {});

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

	huffman_tree->root = min_heap.top();

	return huffman_tree;
}

Huffman_Tree* handle_create_huffman_tree(string message)
{
	try
	{
		return create_huffman_tree(message);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

string decoding_huffman(Huffman_Tree *huffman_tree, string encoded_message)
{
	string message {};

	if((huffman_tree == nullptr) or (huffman_tree->root == nullptr))
	{
		throw string {"ERROR - Invalid operation, huffman tree is not valid ....."};
	}

	Node *crawler {huffman_tree->root};

	for(int i {0}; i < encoded_message.size(); i++)
	{
		if(encoded_message.at(i) == '0')
		{
			crawler = crawler->left;
		}
		else if(encoded_message.at(i) == '1')
		{
			crawler = crawler->right;
		}
		else
		{
			throw string {"ERROR - Invalid operation, encoded message is not valid ....."}; // If the character is neither '0' nor '1'.
		}

		if((crawler->left == nullptr) and (crawler->right == nullptr)) // Leaf node.
		{
			message += crawler->character;

			crawler = huffman_tree->root; // Resetting "crawler".
		}
	}

	return message;
}

string handle_decoding_huffman(Huffman_Tree *huffman_tree, string encoded_message)
{
	try
	{
		return decoding_huffman(huffman_tree, encoded_message);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	string encoded_message {"101101101011010111010110000100001010011111111000"}, message {};

	Huffman_Tree *huffman_tree {handle_create_huffman_tree("Vaisakh Dileep")};

	message = handle_decoding_huffman(huffman_tree, encoded_message);

	cout<<encoded_message<<" --after decoding--> "<<message<<"\n";

	return 0;
}