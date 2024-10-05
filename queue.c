#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size){
    q->size = size;
    q->front= q->rear=-1;
    q->Q= (int*)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1)
        printf("Queue is full ");
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q){
    int x = -1;
    if(q->front==q->rear)
        printf("queue is empty!");
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q){
    int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("%d\n",q.Q[i]);
    printf("\n");
}
int main(){
    struct Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    Display(q);
    printf("%d",dequeue(&q));
}
// C Program to implement queue using arrays
// #include <stdio.h>
// // Define the maximum size for the queue
// #define MAX_SIZE 100

// // Define a structure for the queue
// struct Queue {
//     int queue[MAX_SIZE];
//     int front;
//     int rear;
// };

// // Function to initialize the queue
// void initializeQueue(struct Queue *q) {
//     q->front = -1;
//     q->rear = -1;
// }

// // Function to check if the queue is empty
// int isEmpty(struct Queue *q) {
//     return (q->front == -1);
// }

// // Function to check if the queue is full
// int isFull(struct Queue *q) {
//     return (q->rear == MAX_SIZE - 1);
// }

// // Function to insert an element into the queue
// void enqueue(struct Queue *q, int data) {
//     if (isFull(q)) {
//         printf("Queue is full\n");
//         return;
//     }
//     if (isEmpty(q)) {
//         q->front = 0;
//     }
//     q->rear++;
//     q->queue[q->rear] = data;
//     printf("Enqueued %d in queue\n", data);
// }

// // Function to remove an element from the queue
// int dequeue(struct Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return -1;
//     }
//     int data = q->queue[q->front];
//     // If the queue is empty reset the pointers
//     if (q->front == q->rear) {
//         q->front = -1;
//         q->rear = -1;
//     } else {
//         q->front++;
//     }
//     printf("Deleted element: %d\n", data);
//     return data;
// }

// // Function to display the elements of the queue
// void display(struct Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return;
//     }
//     for (int i = q->front; i <= q->rear; i++) {
//         printf("%d ", q->queue[i]);
//     }
//     printf("\n");
// }

// int main() {
//    // Initialize a queue
//     struct Queue q;
//     initializeQueue(&q);

//     enqueue(&q, 10);
//     enqueue(&q, 20);
//     enqueue(&q, 30);
//     printf("Elements in the queue after enqueue operation: ");
//     display(&q);

//     dequeue(&q);
//     printf("Elements in the queue after dequeue operation: ");
//     display(&q);

//     return 0;
// }
