#include<stdio.h>

void INSERTION_SORT1(int *A, int n){     // Non-decreasing
    int i, j, key;
    for(j = 1; j < n; j++){
        key = A[j];
        for(i = j - 1; i >= 0 && A[i] > key; i--){
            A[i + 1] = A[i];
        }
        A[i + 1] = key;
    }
    return;
}

void INSERTION_SORT2(int *A, int n){        // Non-incremental
    int i, j, key;
    for(j = 1; j < n; j++){
        key = A[j];
        for(i = j - 1; i >= 0 && A[i] < key; i--){
            A[i + 1] = A[i];
        }
        A[i + 1] = key;
    }
    return;
}

int main(){
    int A[7] = {5, 2, 4, 3, 9, 8, 7};
    INSERTION_SORT1(A, 7);
    for(int i = 0; i < 7; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");
    INSERTION_SORT2(A, 7);
    for(int i = 0; i < 7; i++){
        printf("%d, ", A[i]);
    }
    return 0;
}