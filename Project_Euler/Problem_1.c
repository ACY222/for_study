/*
Find the sum of all the multiples of 3 or 5 below 1000
*/

#include<stdio.h>

#define UPPER 1000

// find the sum of multiples of x in (1, n)
int sum_multiple_x(int x, int n){
    int i, sum = 0;
    for(i = 1; i < n; i++){
        if(i % x == 0){      // i is the multiple of x
            sum += i;
        }
    }    
    return sum;
}


int main(){
    int sum = 0, sum1 = sum_multiple_x(3, UPPER), sum2 = sum_multiple_x(5, UPPER), sum3 = sum_multiple_x(15, UPPER);
    sum = sum1 + sum2 - sum3;
    printf("%d", sum);
    return 0;
}