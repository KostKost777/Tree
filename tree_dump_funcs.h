#ifndef TREE_DUMP_FUNCS
#define TREE_DUMP_FUNCS

enum ErrorCodes
{
    BAD_SIZE = 1,
    BAD_SORT = 2
};

void PrintTree(const struct Node* node, FILE* graphiz_file);

int TreeVerifier(struct Tree* tree);

void PrintNameOfErrors(int code_err);

void TreeDump(struct Tree* tree,
              const int line, const char* func, const char* file);

void PrintGraphizNode(FILE* graphiz_file, const struct Node* node);

void PrintGraphizEdge(FILE* graphiz_file, const struct Node* node);

void PrintBazeNode(FILE* graphiz_file, const struct Tree* tree);

void PrintBazeEdge(FILE* graphiz_file, const struct Tree* tree);

void FillLogFile(char* image_file_name, struct Tree* tree, int file_counter);

static char* GetNewDotCmd(int file_counter);

static char* GetNewImageFileName(int file_counter);

#define TREE_VERIFIER(tree)                    \
        if (TreeVerifier(tree)) {              \
            TreeDump(tree, line, func, file);   \
            return NULL;                      \
        }                                      \

#define PRINT_DUMP_LOG(tree, message, ...)        \
        fprintf(log_file, message, ##__VA_ARGS__);          \
        TreeDump(tree, line, func, file);                    \

#endif
