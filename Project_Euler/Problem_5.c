/*
What is the smallest positive number that is evenly divisible
by all of the numbers from 1 to 20
*/
#include<stdio.h>
#include<math.h>

#define UPPER 20

// factorize num into prime factors, and store the results in list
void get_prime_factors(int *list, int num){ 
    for(int i = 2; i < UPPER; i++){
        if(num == 1){
            return;
        }
        if(num % i == 0){
            list[i] += 1;
            num = num / i;
            i--;
        }
    }
}

int main(){
    int list[UPPER] = {0}, tmp_list[UPPER] = {0}, num, i;
    int prod = 1;
    for(num = 2; num <= UPPER; num++){
        get_prime_factors(tmp_list, num);
        for(i = 2; i < UPPER; i++){
            list[i] = tmp_list[i] > list[i] ? tmp_list[i] : list[i];
            tmp_list[i] = 0;
        }
    }
    for(i = 2; i < UPPER; i++){
        if(list[i] != 0){
            for(int j = 0; j < list[i]; j++){
                prod *= i;
            }
        }
    }
    printf("%d", prod);
}