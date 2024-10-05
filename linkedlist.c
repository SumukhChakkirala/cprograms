
#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n) {
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node)); 
    first->data = A[0];  
    first->next = NULL;
    last = first;
    
    for (i = 1; i < n; i++) {
        t = (struct node *)malloc(sizeof(struct node)); 
        t->data = A[i];  
        t->next = NULL;
        last->next = t; 
        last = t;  
    }
}
void Display(struct node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Insert(int position, int value) {
    struct node *t, *p;
    int i;
    
    if (position == 0) {  
        t = (struct node *)malloc(sizeof(struct node));
        t->data = value;
        t->next = first;
        first = t;
    } else if (position > 0) { 
        p = first;
        for (i = 0; i < position - 1 && p != NULL; i++) {
            t +=t->data;
            p = p->next;
        }
        if (p != NULL) {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = value;
            t->next = p->next;
            p->next = t;
        }
    }
}
int count(struct node *p){
    int c=0;
    while(p!= NULL){
        c++;
        p=p->next;
    }
    return c;
}


int sum(struct node *p) {
    int sum = 0;
    while (p != NULL) {
        sum += p->data; 
        p = p->next; 
    }
    return sum; 
}
int search(int value,struct node *p){
     int c = 1;
    while(p!=NULL){
        if(value == p->data)
            return c;
        c++;
         p= p->next;
    }
    return 0;
}
void DisplayR(struct node *p) {
    if (p==NULL){
        return 0;
    }
     printf("%d ",p->data);
    DisplayR(p->next);
}
int sumR(struct node *p) {
    if (p == NULL) {
        return 0; // Base case: if the list is empty, return 0
    }
    return p->data + sumR(p->next); // Recursive case: sum the data and the sum of the rest of the list
}
int Delete(int position) {
    struct node *p, *q = NULL;
    int x = -1, i;

    // Check for invalid position or empty list
    if (position < 1 || first == NULL) {
        return x;  
    }

    if (position == 1) {
        p = first;
        first = first->next;
        x = p->data;
        free(p);
    } else {
        p = first;
        for (i = 0; i < position - 1 && p != NULL; i++) {
            q = p;
            p = p->next;
        }

        if (p != NULL && q != NULL) {
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
}

int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);  
    
    //printf("Original List: ");
    //Display(first);  
    //Insert(0,12);
    //printf("Recursive display after insertion of 12: ");
    Delete(0);
    DisplayR(first);
    //printf("the sum is: %d\n",sum(first));
    // printf("the sum recursive is: %d\n",sumR(first));
    //printf("the count is: %d\n",count(first));
    //printf("the position is: %d\n",search(25,first));


    return 0;
}
