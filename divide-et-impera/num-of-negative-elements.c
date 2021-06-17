#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// metoda reducerii
void negative1(int arr[], int n, int *num) {
    if(!n) *num = 0;
    else {
        negative1(arr, n - 1, num);
        if(arr[n - 1] < 0) *num = *num + 1;
    }   
}

// metoda descompunerii
int negative2(int arr[], int left, int right) {
    int nr;
    if(left == right) {
        if(arr[right] < 0) nr = 1;
        else nr = 0; 
    } else nr = negative2(arr, left, (left + right)/2) + negative2(arr, (left + right)/2 + 1, right);
}

void main() {
    int arr[100] = {1, 3, -7, 0, -3, -9, 10};
    int n = 7;
    int num;
    negative1(arr, n, &num);
    printf("%i", num);
}