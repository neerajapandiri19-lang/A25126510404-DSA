#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Page {
    char name[40];
    struct Page *prev, *next;
} Page;

Page *head = NULL, *tail = NULL;

void insertPage(const char *name) {
    Page *p = malloc(sizeof(Page));
    if (!p) { printf("Memory allocation failed.\n"); return; }
    snprintf(p->name, sizeof(p->name), "%s", name);
    p->next = NULL; p->prev = tail;
    if (tail) tail->next = p; else head = p;
    tail = p;
    printf("Added page: %s\n", name);
}

void displayForward(void) {
    Page *p = head;
    printf("Forward: ");
    while (p) { printf("%s", p->name); if (p->next) printf(" <-> "); p = p->next; }
    printf("\n");
}

void displayBackward(void) {
    Page *p = tail;
    printf("Backward: ");
    while (p) { printf("%s", p->name); if (p->prev) printf(" <-> "); p = p->prev; }
    printf("\n");
}

void deletePage(const char *name) {
    Page *p = head;
    while (p && strcmp(p->name, name) != 0) p = p->next;
    if (!p) { printf("Page %s not found.\n", name); return; }
    if (p->prev) p->prev->next = p->next; else head = p->next;
    if (p->next) p->next->prev = p->prev; else tail = p->prev;
    free(p);
    printf("Deleted page: %s\n", name);
}

int main(void) {
    insertPage("Home"); insertPage("Search"); insertPage("Profile");
    displayForward(); displayBackward();
    printf("Move forward: Home -> Search\n");
    printf("Move backward: Profile -> Search\n");
    deletePage("Search");
    displayForward(); displayBackward();
    deletePage("Settings");
    return 0;
}
