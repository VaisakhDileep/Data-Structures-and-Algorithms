/*
Created by  : Vaisakh Dileep
Date        : 18, October, 2021
Description : This program creates an AVL tree.
*/

#include<iostream>

using namespace std;

struct AVL_Tree_Node
{
    AVL_Tree_Node *left_child;

    int data;

    int height;

    AVL_Tree_Node *right_child;
};

struct AVL_Tree
{
    AVL_Tree_Node *root;
};

int AVL_tree_node_height(AVL_Tree_Node *p) // For AVL tree height is found by counting the number of nodes.
{
    int height_left {}, height_right {};

    if((p != nullptr) and (p->left_child != nullptr))
    {
        height_left = p->left_child->height;
    }
    else
    {
        height_left = 0;
    }

    if((p != nullptr) and (p->right_child != nullptr))
    {
        height_right = p->right_child->height;
    }
    else
    {
        height_right = 0;
    }

    return (height_left > height_right) ? height_left + 1 : height_right + 1;
}

int AVL_tree_balance_factor(AVL_Tree_Node *p)
{
    int height_left {}, height_right {};

    if((p != nullptr) and (p->left_child != nullptr))
    {
        height_left = p->left_child->height;
    }
    else
    {
        height_left = 0;
    }

    if((p != nullptr) and (p->right_child != nullptr))
    {
        height_right = p->right_child->height;
    }
    else
    {
        height_right = 0;
    }

    return height_left - height_right;
}

AVL_Tree_Node* LL_rotation(AVL_Tree_Node *root, AVL_Tree_Node *p)
{
    AVL_Tree_Node *p_left {p->left_child};

    AVL_Tree_Node *p_left_right {p_left->right_child};

    p_left->right_child = p;

    p->left_child = p_left_right;

    p->height = AVL_tree_node_height(p);

    p_left->height = AVL_tree_node_height(p_left);

    if(root == p)
    {
        root = p_left;
    }

    return p_left;
}

AVL_Tree_Node* RR_rotation(AVL_Tree_Node *root, AVL_Tree_Node *p)
{
    AVL_Tree_Node *p_right {p->right_child};

    AVL_Tree_Node *p_right_left {p_right->left_child};

    p_right->left_child = p;

    p->right_child = p_right_left;

    p->height = AVL_tree_node_height(p);

    p_right->height = AVL_tree_node_height(p_right);

    if(root == p)
    {
        root = p_right;
    }

    return p_right;
}

AVL_Tree_Node* LR_rotation(AVL_Tree_Node *root, AVL_Tree_Node *p)
{
    AVL_Tree_Node *p_left {p->left_child};

    AVL_Tree_Node *p_left_right {p_left->right_child};

    p_left->right_child = p_left_right->left_child;

    p->left_child = p_left_right->right_child;

    p_left_right->left_child = p_left;

    p_left_right->right_child = p;

    p->height = AVL_tree_node_height(p);

    p_left->height = AVL_tree_node_height(p_left);

    p_left_right->height = AVL_tree_node_height(p_left_right);

    if(root == p)
    {
        root = p_left_right;
    }

    return p_left_right;
}

AVL_Tree_Node* RL_rotation(AVL_Tree_Node *root, AVL_Tree_Node *p)
{
    AVL_Tree_Node *p_right {p->right_child};

    AVL_Tree_Node *p_right_left {p_right->left_child};

    p_right->left_child = p_right_left->left_child;

    p->right_child = p_right_left->right_child;

    p_right_left->left_child = p;

    p_right_left->right_child = p_right;

    p->height = AVL_tree_node_height(p);

    p_right->height = AVL_tree_node_height(p_right);

    p_right_left->height = AVL_tree_node_height(p_right_left);

    if(root == p)
    {
        root = p_right_left;
    }

    return p_right_left;
}

AVL_Tree_Node* insert_node_AVL_tree(AVL_Tree *AVL_tree, AVL_Tree_Node *p, int key)
{
    if(p == nullptr)
    {
        AVL_Tree_Node *temp {new AVL_Tree_Node {nullptr, key, 1, nullptr}};

        return temp;
    }

    if(key < p->data)
    {
        p->left_child = insert_node_AVL_tree(AVL_tree, p->left_child, key);
    }
    else if(key > p->data)
    {
        p->right_child = insert_node_AVL_tree(AVL_tree, p->right_child, key);
    }

    p->height = AVL_tree_node_height(p);

    if((AVL_tree_balance_factor(p) == 2) and (AVL_tree_balance_factor(p->left_child) == 1))
    {
        return LL_rotation(AVL_tree->root, p);
    }

    if((AVL_tree_balance_factor(p) == 2) and (AVL_tree_balance_factor(p->left_child) == -1))
    {
        return LR_rotation(AVL_tree->root, p);
    }

    if((AVL_tree_balance_factor(p) == -2) and (AVL_tree_balance_factor(p->right_child) == -1))
    {
        return RR_rotation(AVL_tree->root, p);
    }

    if((AVL_tree_balance_factor(p) == -2) and (AVL_tree_balance_factor(p->right_child) == 1))
    {
        return RL_rotation(AVL_tree->root, p);
    }

    return p;
}

AVL_Tree* create_AVL_tree(int *A, int size)
{
    AVL_Tree *AVL_tree {new AVL_Tree {}};

    for(int i {0}; i < size; i++)
    {
        AVL_tree->root = insert_node_AVL_tree(AVL_tree, AVL_tree->root, A[i]); // Make sure to update the root of AVL_tree 
    }

    return AVL_tree;
}

void display_AVL_tree(AVL_Tree_Node *node) // in-order traversal
{
    if(node != nullptr)
    {
        display_AVL_tree(node->left_child);

        cout<<node->data<<" ";

        display_AVL_tree(node->right_child);
    }
}

void handle_display_AVL_tree(AVL_Tree *AVL_tree)
{
    display_AVL_tree(AVL_tree->root);
}

int main()
{
    AVL_Tree *AVL_tree {};

    AVL_tree = create_AVL_tree(new int[10] {7, 9, 10, 12, 43, 2, 1, 5, 9, 43}, 10);

    cout<<"display_AVL_tree(AVL_tree): ";
    handle_display_AVL_tree(AVL_tree);
    cout<<"\n";

    return 0;
}