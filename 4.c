#include<stdio.h>

int revNum=0, rem;
int reverse_function(int num){
    if(num){
        rem = num%10;
        revNum = revNum*10+rem;
        reverse_function(num/10);
    }
    else{
        return revNum;
    }
    return revNum;

}

void main(){
    int a,rev;
    printf("enter number: ");
    scanf("%d",&a);
    rev = reverse_function(a);
    printf("%d",rev);
}
