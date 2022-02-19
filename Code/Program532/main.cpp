/*
Created by  : Vaisakh Dileep
Date        : 19, February, 2022
Description : This program helps to understand how to represent an n-ary tree.
*/

#include<vector>

using namespace std;

struct Node
{
    int data;

    vector<Node *> children;
};

struct N_ary_Tree
{
    Node *root;
};

int main()
{
    N_ary_Tree tree {new Node {1, vector<Node *> {}}};

    tree.root->children = vector<Node *> {new Node {2, vector<Node *> {}}, new Node {3, vector<Node *> {}}, new Node {4, vector<Node *> {}}};

    tree.root->children.at(0)->children = vector<Node *> {new Node {5, vector<Node *> {}}, new Node {6, vector<Node *> {}}, new Node {7, vector<Node *> {}}};
    tree.root->children.at(1)->children = vector<Node *> {new Node {8, vector<Node *> {}}, new Node {9, vector<Node *> {}}, new Node {10, vector<Node *> {}}};
    tree.root->children.at(2)->children = vector<Node *> {new Node {11, vector<Node *> {}}, new Node {12, vector<Node *> {}}, new Node {13, vector<Node *> {}}};

    return 0;
}