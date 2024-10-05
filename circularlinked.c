#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN
struct Node {
    int data;
    struct Node *next;
};
struct Node *Head = NULL;
void create(int A[], int n) {
    int i;
    struct Node *t, *last;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head; 
    last = Head;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = Head; 
        last->next = t;       
        last = t;             
    }
    last->next = Head;  // Close the circular loop
}
void display(struct Node *h) {
    struct Node *p = h;
    if (h == NULL) return;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != h);
    printf("\n");
}
void insert(struct Node *h, int position, int value) {
    struct Node *t, *p = h;
    int i;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    if (position == 0) {
        while (p->next != Head) {
            p = p->next;
        }
        t->next = Head;
        p->next = t;
        Head = t;
    } else {
        for (i = 0; i < position - 1 && p->next != Head; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int count(struct Node *p) {
    int c = 0;
    if (p == NULL) return c;
    do {
        c++;
        p = p->next;
    } while (p != Head);
    return c;
}

int sum(struct Node *p) {
    int s = 0;
    if (p == NULL) return s;
    do {
        s += p->data;
        p = p->next;
    } while (p != Head);
    return s;
}
int search(struct Node *p, int target) {
    int c = 0;
    if (p == NULL) return -1;
    do {
        if (p->data == target) {
            return c;
        }
        p = p->next;
        c++;
    } while (p != Head);
    return -1; // Return -1 if not found
}
int max(struct Node *p) {
    if (p == NULL) return INT_MIN; // Return a minimum value indicator
    int maxVal = p->data;
    p = p->next;
    while (p != Head) {
        if (p->data > maxVal) {
            maxVal = p->data;
        }
        p = p->next;
    }
    return maxVal;
}
void displayRec(struct Node *p) {
    static int flag = 0;
    if (p == Head && flag == 1) {
        return;
    }
    if (flag == 0) {
        flag = 1;
    }
    printf("%d ", p->data);
    displayRec(p->next);
}
void deleteNode(int position) {
    if (Head == NULL) return; // Empty list

    struct Node *temp = Head;
    struct Node *prev = NULL;

    if (position == 0) {
        // Handle deletion of head node
        if (Head->next == Head) {
            // Only one node in the list
            free(Head);
            Head = NULL;
        } else {
            while (temp->next != Head) {
                temp = temp->next;
            }
            prev = Head;
            Head = Head->next;
            temp->next = Head;
            free(prev);
        }
    } else {
        for (int i = 0; i < position - 1 && temp->next != Head; i++) {
            temp = temp->next;
        }
        if (temp->next != Head) {
            prev = temp->next;
            temp->next = prev->next;
            free(prev);
        }
    }
}
int main() {
    int A[] = {20, 13, 14, 5, 61};
    create(A, 5);
    display(Head);
    insert(Head, 4, 10);
    display(Head);
    printf("Count: %d\n", count(Head));
    printf("Sum: %d\n", sum(Head));
    int foundAt = search(Head, 2);
    if (foundAt != -1) {
        printf("Found at index: %d\n", foundAt);
    } else {
        printf("Not found\n");
    }
    printf("Maximum value: %d\n", max(Head));
    printf("recursive display: \n");
    deleteNode(0); // Delete head node
    displayRec(Head);
    return 0;
}


