#ifndef TREE_FUNCS
#define TREE_FUNCS

enum Status
{
    success = 0,
    error = 1
};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Tree
{
    int size;
    struct Node* root;
};

extern FILE* log_file;

void CloseLogFile();

void OpenLogFile(const char* log_file_name);

void DeleteNode(struct Node* node);

enum Status NodeCtor(struct Node** node, int data);

struct Node* Insert(struct Tree* tree, int value,
                    const int line, const char* func, const char* file);

void TreeDtor(struct Tree* tree);

void NodeDtor(struct Node* node);

#define INSERT(tree, value, exit_label)                                          \
    if ((ret_value = Insert(tree, value, __LINE__, __func__, __FILE__)) == NULL) {       \
        TreeDump(tree, __LINE__, __func__, __FILE__);                            \
        printf("Ошибка\n");                                                       \
        goto exit_label;                                                         \
    }

#define PRINT_DUMP_LOG(tree, message, value)        \
        fprintf(log_file, message, value);          \
        TreeDump(tree, line, func, file);                                                                          \



#endif
