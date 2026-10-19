#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int roll;
    struct Node *next;
} Node;

Node *head = NULL;

void insertEnd(int roll) {
    Node *n = malloc(sizeof(Node)), *p;
    if (!n) { printf("Memory allocation failed.\n"); return; }
    n->roll = roll; n->next = NULL;
    if (!head) { head = n; return; }
    for (p = head; p->next; p = p->next) {}
    p->next = n;
}

void insertBeginning(int roll) {
    Node *n = malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed.\n"); return; }
    n->roll = roll; n->next = head; head = n;
}

void display(void) {
    Node *p = head;
    printf("List: ");
    while (p) { printf("%d -> ", p->roll); p = p->next; }
    printf("NULL\n");
}

void searchRoll(int roll) {
    Node *p = head;
    while (p && p->roll != roll) p = p->next;
    if (p) printf("Roll number %d found.\n", roll);
    else printf("Roll number %d not found.\n", roll);
}

void deleteRoll(int roll) {
    Node *p = head, *prev = NULL;
    while (p && p->roll != roll) { prev = p; p = p->next; }
    if (!p) { printf("Roll number %d not available; nothing deleted.\n", roll); return; }
    if (prev) prev->next = p->next; else head = p->next;
    free(p);
    printf("Deleted roll number %d.\n", roll);
}

int main(void) {
    insertEnd(101); insertEnd(102); insertEnd(103);
    printf("Initial "); display();
    insertBeginning(100); printf("After insert at beginning "); display();
    insertEnd(104); printf("After insert at end "); display();
    searchRoll(103);
    deleteRoll(102); printf("After deletion "); display();
    searchRoll(999);
    deleteRoll(999);
    return 0;
}
