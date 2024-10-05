#include<stdio.h>
#include<stdlib.h>

int main(){
    int i=0, n,sum=0 ,*ptr;
    printf("number of numbers to be added: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));

    if(ptr==NULL){
        printf("error");
        exit(0);
    }

    for( i =0;i<n;++i){
        scanf("%d", ptr+i);
        sum +=*(ptr+i);
    }
    printf("sum = %d\n",sum);
    free(ptr);
    
    return 0;
}