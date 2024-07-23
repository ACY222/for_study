/*
Find the sum of the even-valued terms in Fibonacci sequence 
that do not exceed four million.
*/
#include<stdio.h>

#define UPPER 4e6



int main(){
    int fib1 = 1, fib2 = 1, fib3 = fib1 + fib2, sum = 0;
    while(fib3 <= UPPER){
        sum += fib3 % 2 ? 0 : fib3;
        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib1 + fib2;
    }
    printf("%d", sum);
    return 0;
}