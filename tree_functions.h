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
    int code_err;
    struct Node* root;
};

enum Son
{
    LEFT = 0,
    RIGHT = 1
};

extern FILE* log_file;

void CloseLogFile();

void OpenLogFile(const char* log_file_name);

void DeleteNode(struct Tree* tree, struct Node* node);

struct Node* DeleteBranch(struct Tree* tree, struct Node* node, enum Son son,
                          const int line, const char* func, const char* file);

enum Status NodeCtor(struct Node** node, int data);

struct Node* Insert(struct Tree* tree, int value,
                    const int line, const char* func, const char* file);

void TreeDtor(struct Tree* tree);

void CheckTreeSorted(struct Node* node, bool* is_correct);

#define INSERT(tree, value, exit_label)                                          \
    if ((ret_value = Insert(tree, value, __LINE__, __func__, __FILE__)) == NULL) {       \
        TreeDump(tree, __LINE__, __func__, __FILE__);                            \
        printf("Ошибка\n");                                                       \
        goto exit_label;                                                         \
    }

#define DELETE_BRANCH(tree, node, son, exit_label)                                          \
    if (DeleteBranch(tree, node, son, __LINE__, __func__, __FILE__)) {       \
        TreeDump(tree, __LINE__, __func__, __FILE__);                            \
        printf("Ошибка\n");                                                       \
        goto exit_label;                                                         \
    }

#endif
