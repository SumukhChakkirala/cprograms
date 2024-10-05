#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *left;
    struct Node *right;
    int data;
}*root = NULL;

struct Node * createNode(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

void insert(int value) {
    struct Node *node, *tail, *present;
    present = root;
    if(!present) {
        root = createNode(value);
        return;
    }
    while(present) {
        tail = present;
        if(present->data > value) {
            present = present->left;
        } else if(present->data < value) {
            present = present->right;
        } else {
            return; // Value already exists, no need to insert
        }
    }
    if(tail->data > value) {
        tail->left = createNode(value);
    } else {
        tail->right = createNode(value);
    }
}

struct Node * search(int value) {
    struct Node *present = root;
    while(present) {
        if(present->data > value) {
            present = present->left;
        } else if(present->data < value) {
            present = present->right;
        } else {
            return present; // Value found
        }
    }
    return NULL; // Value not found
}

void inorder(struct Node *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main() {
    insert(20);
    insert(10);
    insert(30);
    insert(5);
    insert(25);
    inorder(root);
    if(search(80)) {
        printf("\nElement is found\n");
    } else {
        printf("\nElement is not found\n");
    }

    return 0;
}
