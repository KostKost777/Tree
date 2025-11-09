#include <TXLib.h>

#include<iostream>
#include <assert.h>

#include "tree_functions.h"
#include "tree_set_get_funcs.h"

//GET

struct Node* GetLeft(const struct Node* node)
{
    assert(node);

    return node->left;
}

struct Node* GetRight(const struct Node* node)
{
    assert(node);

    return node->right;
}

int  GetData(const struct Node* node)
{
    assert(node != NULL);

    return node->data;
}

struct Node* GetRoot(const struct Tree* tree)
{
    assert(tree);
    return tree->root;
}

int GetSize(const struct Tree* tree)
{
    assert(tree);

    return tree->size;
}

//SET

void SetLeft(struct Node* node, struct Node* new_left)
{
    assert(node);

    node->left = new_left;
}

void SetRight(struct Node* node, struct Node* new_right)
{
    assert(node);

    node->right = new_right;
}

void SetData(struct Node* node, int new_data)
{
    assert(node);

    node->data = new_data;
}

void SetRoot(struct Tree* tree, struct Node* new_root)
{
    assert(tree);

    tree->root = new_root;
}

void SetSize(struct Tree* tree, int new_size)
{
    assert(tree);

    tree->size = new_size;
}
