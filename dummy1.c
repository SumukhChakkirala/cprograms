#include<stdio.h>
struct rectangle {
    int length;
    int breadth;
};
void initialize(struct rectangle *r, int l, int b){
    r->length= l;
    r->breadth=b;
}
int area(struct rectangle r){
    return r.length*r.breadth;
}
void changel(struct rectangle *r,int l){
    r->length= l;
}
void changeb(struct rectangle *r,int b){
    r->breadth= b;
}
int main(){
    struct rectangle r;
    initialize(&r,10,10);
    printf("%d",area(r));
    changel(&r,12);
    printf("%d",area(r));

}