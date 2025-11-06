#include <TXLib.h>
#include<iostream>
#include <assert.h>

#include "tree_functions.h"
#include "tree_set_get_funcs.h"
#include "tree_dump_funcs.h"

FILE* log_file = NULL;

enum Status NodeCtor(struct Node** node, int data)
{
    *node = (struct Node*)calloc(1, sizeof(struct Node));

    if (*node == NULL) {

        fprintf(log_file, "Not allocate memory for tree\n");
        return error;
    }

    SetData(*node, data);

    return success;
}

struct Node* Insert(struct Tree* tree, int value,
                    const int line, const char* func, const char* file)
{
    assert(tree);

    PRINT_DUMP_LOG(tree, "DUMP: Before Insert(%d)", value);

    if (GetRoot(tree) == NULL) {

        tree->size++;
        NodeCtor(&tree->root, value);

        PRINT_DUMP_LOG(tree, "DUMP: After Insert(%d)", value);

        return tree->root;

    }

    struct Node* now_node = GetRoot(tree);

    while(true) {

        if (GetData(now_node) >= value) {

            if (GetLeft(now_node) == NULL) {

                tree->size++;
                NodeCtor(&now_node->left, value);

                printf("\nLEFT: %d\n", value);

                PRINT_DUMP_LOG(tree, "DUMP: After Insert(%d)", value);

                return now_node->left;

            }

            now_node = GetLeft(now_node);
        }

        else {

            if (GetRight(now_node) == NULL) {

                tree->size++;
                NodeCtor(&now_node->right, value);
                printf("\nRIGHT: %d\n", value);

                PRINT_DUMP_LOG(tree, "DUMP: After Insert(%d)", value);

                return now_node->right;

            }

            now_node = GetRight(now_node);
        }
    }

    PRINT_DUMP_LOG(tree, "DUMP: After Insert(%d)", value);

    return NULL;
}

void DeleteNode(struct Node* node)
{
    assert(node);

    if (GetLeft(node)) {
        DeleteNode(node->left);
    }

    free(node->left);
    node->left = NULL;

    if (GetRight(node)) {
        DeleteNode(node->right);
    }

    free(node->right);
    node->right = NULL;
}

void TreeDtor(struct Tree* tree)
{
    DeleteNode(tree->root);
    free(tree->root);
    tree->root = NULL;
}

void NodeDtor(struct Node* node)
{
    assert(node != NULL);

    free(node);

    node = NULL;
}

void CloseLogFile()
{
    fclose(log_file);
    printf("Logfile close");
}

void OpenLogFile(const char* log_file_name)
{
    log_file = fopen(log_file_name, "w");

    if (log_file != NULL)
        printf("Logfile open\n");

    else
        printf("Logfile open ERROR\n");

    fprintf(log_file, "<pre>\n");
}
