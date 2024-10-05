#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int *p;
};

void create(struct queue *st,int size){
    st->front = st->rear = -1;
    st->size = size;
    st->p = (int*)malloc((st->size)*sizeof(int));
}
void enqueue(struct queue *st, int x){
    if(st->rear==st->size -1){
        printf("overflow");
    }else{
        st->rear++;
        st->p[st->rear]=x;
    }
}
void dequeue(struct queue *st){
    int x = -1;
    if(st->front=st->rear){
        printf("underfloww");
    }
    else{
        st->front++;
        x=st->p[st->front];
    }
    printf("%d",x);
}

void display(struct queue st){
    int i;
    for(i = st.front+1;i<=st.rear;i++){
        printf("%d",st.p[i]);
    }
    printf("\n");
}

int main(){
    struct queue st;
    create(&st,3);
    enqueue(&st,10);
    enqueue(&st,10);

    
}