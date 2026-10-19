#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int v) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(1);
    n->data = v; n->left = n->right = NULL; return n;
}
Node *insert(Node *r, int v) {
    if (!r) return newNode(v);
    if (v < r->data) r->left = insert(r->left, v);
    else if (v > r->data) r->right = insert(r->right, v);
    return r;
}
void inorder(Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
Node *minNode(Node *r) { while (r && r->left) r = r->left; return r; }

Node *deleteNode(Node *r, int key) {
    if (!r) return NULL;
    if (key < r->data) r->left = deleteNode(r->left, key);
    else if (key > r->data) r->right = deleteNode(r->right, key);
    else {
        if (!r->left) { Node *t = r->right; free(r); return t; }
        if (!r->right) { Node *t = r->left; free(r); return t; }
        Node *t = minNode(r->right);
        r->data = t->data;
        r->right = deleteNode(r->right, t->data);
    }
    return r;
}
int main(void) {
    Node *root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80}, i;
    for (i = 0; i < 7; i++) root = insert(root, a[i]);

    printf("Before deletion: "); inorder(root); printf("\n");
    root = deleteNode(root, 30); 
    printf("After deleting 30 (two children): "); inorder(root); printf("\n");
    root = deleteNode(root, 20); 
    printf("After deleting 20 (leaf): "); inorder(root); printf("\n");
    root = deleteNode(root, 80); 
    root = deleteNode(root, 70);
    printf("After deleting 70 (one child): "); inorder(root); printf("\n");
    return 0;
}
