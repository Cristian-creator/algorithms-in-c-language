#include <stdio.h>

// biggest divisor for 2 numbers
int biggestDivisor(int a, int b) {
    if(a == b) return a;
    else {
        if(a > b) return biggestDivisor(a - b, b);
        return biggestDivisor(a, b - a);
    } 
}

// biggest divisor for an array of numbers
// metoda reducerii
int biggestDivisor2(int v[], int n) {
    int result;
    if(n == 1) {
        result = v[0];
    }
    else {
        result = biggestDivisor(biggestDivisor2(v, n - 1), v[n - 1]);
    }

    return result;
}
// biggest divisor for an array of numbers
// metoda descompunerii
int biggestDivisor3(int v[], int left, int right) {
    if(left == right) return v[left]; 
    else {
        int middle = (left + right) / 2;
        return biggestDivisor(biggestDivisor3(v, left, middle), biggestDivisor3(v, middle + 1, right));
    }
}

void main() {
    // ----- for biggest divisor 2 num ----
    // int a = 16, b = 20;
    // int result = biggestDivisor(a, b);
    // printf("%i", result); 

    // ---- for biggest divisor for an array of numbers ----
    // int array[100] = {30, 30, 30, 20, 40};
    // int n = 5;
    // int result = biggestDivisor2(array, n);
    // printf("%i", result);

    // ---- for biggest divisor for an array of numbers -method2 ----
    int array[100] = {10, 30, 10, 20, 40};
    int n = 5;
    int result = biggestDivisor3(array, 0, n);
    printf("%i", result);
}