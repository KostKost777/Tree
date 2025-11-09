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

    TREE_VERIFIER(tree)
    PRINT_DUMP_LOG(tree, "<h3>DUMP: Before Insert(%d)</h3>", value);

    if (GetRoot(tree) == NULL) {

        tree->size++;

        NodeCtor(&tree->root, value);

        TREE_VERIFIER(tree)
        PRINT_DUMP_LOG(tree, "<h3>DUMP: After Insert(%d)</h3>", value);

        return tree->root;

    }

    struct Node* now_node = GetRoot(tree);

    while(true) {

        if (GetData(now_node) >= value) {

            if (GetLeft(now_node) == NULL) {

                tree->size++;
                NodeCtor(&now_node->left, value);

                printf("\nLEFT: %d\n", value);

                TREE_VERIFIER(tree)
                PRINT_DUMP_LOG(tree, "<h3>DUMP: After Insert(%d)</h3>", value);

                return now_node->left;

            }

            now_node = GetLeft(now_node);
        }

        else {

            if (GetRight(now_node) == NULL) {

                tree->size++;
                NodeCtor(&now_node->right, value);
                printf("\nRIGHT: %d\n", value);

                TREE_VERIFIER(tree)
                PRINT_DUMP_LOG(tree, "<h3>DUMP: After Insert(%d)</h3>", value);

                return now_node->right;

            }

            now_node = GetRight(now_node);
        }
    }

    TREE_VERIFIER(tree);
    PRINT_DUMP_LOG(tree, "<h3>DUMP: After Insert(%d)</h3>", value);

    return NULL;
}

struct Node* DeleteBranch(struct Tree* tree, struct Node* node, enum Son son,
                          const int line, const char* func, const char* file)
{
    assert(node);

    TREE_VERIFIER(tree);
    PRINT_DUMP_LOG(tree, "<h3>DUMP: Before Delete(%p) Son is: %d (l - 0, r - 1)</h3>",
                                                                           node, son);

    if (son == LEFT) {

        DeleteNode(tree, node->left);
        free(node->left);
        tree->size--;
        node->left = NULL;
    }

    else {

        DeleteNode(tree, node->right);
        free(node->right);
        tree->size--;
        node->right = NULL;
    }

    TREE_VERIFIER(tree);
    PRINT_DUMP_LOG(tree, "<h3>DUMP: After Delete(%p) Son is: %d (l - 0, r - 1)</h3>",
                                                                          node, son);

    return node;

}

void DeleteNode(struct Tree* tree, struct Node* node)
{
    assert(node);

    if (GetLeft(node)) {
        DeleteNode(tree, node->left);
    }

    if (node->left != NULL)
        tree->size--;

    free(node->left);
    node->left = NULL;

    if (GetRight(node)) {
        DeleteNode(tree, node->right);
    }

    if (node->right != NULL)
        tree->size--;

    free(node->right);
    node->right = NULL;
}

void TreeDtor(struct Tree* tree)
{
    DeleteNode(tree, tree->root);
    free(tree->root);
    tree->root = NULL;
    tree->size = 0;
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
