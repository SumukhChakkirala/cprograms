
#include <stdio.h>
#include <stdlib.h>
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;
void create(int A[], int n) {
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p) {
    while (p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;

    if (index == 0) {  
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        if (first) first->prev = t;
        first = t;
    } else {  
        for (i = 0; i < index - 1 && p; i++)
            p = p->next;

        if (p) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->next = p->next;
            t->prev = p;
            if (p->next) p->next->prev = t;
            p->next = t;
        }
    }
}
void deleteRear() {
    struct Node *p = first;
    if (first == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (first->next == NULL) {
        free(first);
        first = NULL;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
    }
}
void deleteAt(int pos) {
    struct Node *p = first;
    int i;
    if (first == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (pos == 0) {
        first = first->next;
        if (first) first->prev = NULL;
        free(p);
    } else {
        for (i = 0; i < pos && p != NULL; i++) {
            p = p->next;
        }
        if (p != NULL) {
            p->prev->next = p->next;
            if (p->next) {
                p->next->prev = p->prev;
            }
            free(p);
        } else {
            printf("Invalid position.\n");
        }
    }
}
void insertRear(int x) {
    struct Node *t, *p = first;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL) {
        t->prev = NULL;
        first = t;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
    }
}
void reverse(struct Node *p) {
    struct Node *temp;
    while (p) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p && p->next == NULL)
            first = p;
    }
}
int main() {
    int A[] = {1, 12, 13, 4, 5};
    create(A, 5);
    printf("Original List: ");
    display(first);
    insert(first, 0, 5);
    printf("After inserting 5 at the beginning: ");
    display(first);
    insert(first, 3, 25);
    printf("After inserting 25 at index 3: ");
    display(first);
    deleteRear();
    printf("After deleting the rear node: ");
    display(first);
    deleteAt(2); 
    printf("After deleting node at index 2: ");
    display(first);
    reverse(first);
    printf("Reversed List: ");
    display(first);
    printf("insert at rear: ");
    insertRear(70);
    display(first);
    return 0;
}
