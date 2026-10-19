#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int value) {
    Node *n = malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed.\n"); exit(1); }
    n->data = value; n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int value) {
    if (!root) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root; /* Duplicate values are ignored */
}
void inorder(Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(Node *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

int search(Node *r, int value) {
    if (!r) return 0;
    if (r->data == value) return 1;
    return value < r->data ? search(r->left, value) : search(r->right, value);
}

int main(void) {
    Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int i, key = 60;
    for (i = 0; i < 7; i++) root = insert(root, values[i]);
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    printf("Search %d: %s\n", key, search(root, key) ? "Found" : "Not found");
    printf("Inorder is sorted because smaller values are placed left and larger values right.\n");
    return 0;
}
