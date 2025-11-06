#include <TXLib.h>

#include <iostream>
#include <assert.h>

#include "tree_functions.h"
#include "tree_set_get_funcs.h"
#include "tree_dump_funcs.h"


int main()
{
    atexit(CloseLogFile);
    OpenLogFile("tree_log_file.html");

    struct Node* ret_value = NULL;
    struct Tree tree = {};

    struct Node* node_7 = NULL;

    INSERT(&tree, 10, exit_label);

    INSERT(&tree, 5, exit_label);

    INSERT(&tree, 20, exit_label);

    node_7 = ret_value;

    INSERT(&tree, 3, exit_label);

    INSERT(&tree, 7, exit_label);

    INSERT(&tree, 6, exit_label);

    INSERT(&tree, 15, exit_label);

    INSERT(&tree, 16, exit_label);

    printf("PTR: %p\n", node_7);

    DeleteNode(node_7);

    TreeDump(&tree, __LINE__, __func__, __FILE__);

    exit_label:

        TreeDtor(&tree);

        if (ret_value == NULL) {
            printf("END WITH ERROR\n");
            return 1;
        }

        printf("END SUCCESS\n");
        return 0;
}
