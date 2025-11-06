#ifndef TREE_SET_GET_FUNCS
#define TREE_SET_GET_FUNCS

//GET

struct Node* GetLeft(const struct Node* node);

struct Node* GetRight(const struct Node* node);

int  GetData(const struct Node* node);

struct Node* GetRoot(const struct Tree* tree);

int GetSize(const struct Tree* tree);

//SET

void SetLeft(struct Node* node, struct Node* new_left);

void SetRight(struct Node* node, struct Node* new_right);

void SetData(struct Node* node, int new_data);

void SetRoot(struct Tree* tree, struct Node* new_root);

void SetSize(struct Tree* tree, int new_size);


#endif
