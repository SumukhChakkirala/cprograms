#include<stdio.h>
struct Element{
    int i;
    int j;
    int x;
};
struct sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};
void main(){
    struct sparse s;
    create(&s);
}
void create(struct sparse *s){
    int i;
    printf("enter dimensions ");
    scanf("%d %d",&s->m,&s->n);
    scanf("%d",&s->num);
    s->e = new Element[s->num];
    printf("enter all elements ");
    for(i=0;i<s->num;i++)
        scanf("%d %d %d ",&s->e[i].i,&s->e[i].j,&s->e[i].x);
}
void display(){
    
}
