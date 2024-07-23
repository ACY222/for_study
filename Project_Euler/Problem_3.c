/*
Find the largest prime factor of 600851475143
*/
#include<stdio.h>
#include<math.h>

#define NUM 600851475143

/*
Question1: How to find the factor of a number?
if num mod x == 0, then x is a factor of num

Question2: How to find whether a number is prime number?
Wilson's theorem: if (p-1)!(mod p) == -1(mod p), then p is a prime number 
*/

int Wilson(int n){      // (fact(n - 1) + 1) % n == 0, 或 fact(n - 1) % n == n - 1
    int prod = 1;
    for(int i = 1; i < n; i++){
        prod *= i;
        prod %= n;      // in case that (n-1)! is out of range
    }
    if(prod == n - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int max_prime_factor = 1, i, sqrt_num = sqrt(NUM);
    for(i = 2; i < sqrt_num; i++){
        if(NUM % i == 0){
            max_prime_factor = Wilson(i) ? i : max_prime_factor;
        }
    }
    printf("%d", max_prime_factor);
    return 0;

}