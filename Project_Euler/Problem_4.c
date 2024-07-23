/*
A palindrome number reads the same both ways.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include<stdio.h>
#include<math.h>

#define max 999
#define min 100

int get_digit(int x, int n){    // get a number starting from the nth digit of the lowest
    return (int)(x / pow(10, n - 1)) % 10;
}

int test(int num, int n){       // test if the num of n digits is a palindrome number
    int flag = 1;
    for(int i = 1; i < n + 1 - i; i++){
        if(get_digit(num, i) != get_digit(num, n + 1 - i)){
            flag = 0;
        }
    }
    return flag;
}

int main(){
    int i, j, prod, res = 1;
    for(i = max; i >= min; i--){
        for(j = max; j >= min; j--){
            prod = i * j;   // range from 10000-998001
            if(prod / 100000){     // 100000 <= prod < 998001, namely 6 digits
                if(test(prod, 6) && prod > res){
                    res = prod;
                    break;
                }
            }
            else{               // 10000 < prod < 100000, namely 5 digits
                if(test(prod, 5) && prod > res){
                    res = prod;
                    break;
                }
            }
        }
        
    }
    printf("%d", res);
    return 0;
}