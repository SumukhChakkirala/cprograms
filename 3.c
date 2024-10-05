#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,i,sum = 0, *ptr;
    printf("enter numberr: ");
    scanf("%d",&a);
    ptr = (int*)calloc(a,sizeof(int));
    if(ptr == NULL){
        printf("error");
        exit(0);
    }


    for(i =0;i<a;++i){
        scanf("%d",ptr+i);
        sum+= *(ptr+i);
    }
    printf("sum = %d",sum);
    free(ptr);

    
    return 0;
}