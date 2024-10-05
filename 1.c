#include <stdio.h>


void main(){
    int a;
    int sum =0;
    printf("enter number of numbers: ");
    scanf("%d",&a);
    for(int i=1; i<=a;i++){
        sum=sum+i;
    }
    printf("%d",sum);

}
//sum of n natural numbers by allocating memory in heap