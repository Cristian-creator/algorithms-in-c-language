#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// metoda reducerii
int scalarProduct(int a[], int b[], int n) {
    int reducer;
    if(!n) {
        reducer = 0;
    } else reducer = scalarProduct(a, b, n-1) + a[n-1] * b[n-1];

    return reducer;
}

// metoda descompunerii
int scalarProduct2(int a[], int b[], int left, int right) {
    if(left == right) return a[left] * b[left];
    else {
        int middle = (left + right) / 2;
        return scalarProduct2(a, b, left, middle) + scalarProduct2(a, b, middle + 1, right);
    }
}

void main() {
    int a[100] = {4, 3, 7};
    int b[100] = {3, 2, 1};
    int n = 3;
    // const num = scalarProduct(a, b, n); // first method
    const num = scalarProduct2(a, b, 0, n); // second method
    printf("%i", num);
}