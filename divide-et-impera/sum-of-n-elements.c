#include <stdio.h>

int sumOfArrayElements(int arr[100], int left, int right) {
    // base case
    if(left == right) return arr[left];
    else {
        int middle = (left + right) / 2;                   // splitting problem      
        int sum1 = sumOfArrayElements(arr, left, middle);  // resolve first problem
        int sum2 = sumOfArrayElements(arr, middle + 1, right);  // resolve first problem
        return sum1 + sum2;
    } 
}

// sum of odd 
int sumOdd(int arr[100], int left, int right) {
    if(left == right && (arr[left] % 2)) return arr[left];
    else {
        int middle = (left + right) / 2;      
        return sumOfArrayElements(arr, middle + 1, right) + sumOfArrayElements(arr, left, middle);
    } 
}

// product of first n odd elements
int productFirstN(int n) {
    int product;
    if(!n) product = 1;
    else {
        product = productFirstN(n - 1) * (2 * n - 1);
    }

    return product;
}

// sum of even num placed on positions divisible by three
int sumEvenDivThree(int v[], int n) {
    int result;
    if(!n) result = 0;
    else {
        int over = !(v[n] % 2) && !(n % 3) ? v[n] : 0; 
        result = sumEvenDivThree(v, n - 1) + over;
    }
    return result;
}

// divide et impera
int sumEvenDivThree2(int v[], int left, int right) {
    if(left == right) return !(v[left] % 2) && !(left % 3 || left == 1)? v[left] : 0;
    else {
        // int over = ; 
        int middle = (left + right) / 2;
        return sumEvenDivThree2(v, left, middle) + sumEvenDivThree2(v, middle + 1, right);
    }
}

void main() {
    // int array[100] = {5, 4, 3, 7, 8};
    // int n = 5;
    // int result = sumOfArrayElements(array, 0, n);
    // printf("%i", result);

    // int array[100] = {5, 4, 3, 7, 8};
    // int n = 5;
    // int result = sumOdd(array, 0, n);
    // printf("%i", result);

//     int n = 5;  // 1 * 2 * 3 * 4 * 5
//     int result = productFirstN(n);
//     printf("%i\n", result);

    // int a[100] = {12, 2, 3, 4, 5, 6, 10, 8, 8, 20};
    // int result = sumEvenDivThree(a, 10);
    // printf("sum: %i\n", result);

    // int a[100] = {12, 2, 3, 4, 5, 6, 10, 8, 8, 20};
    int a[100] = {10, 8, 3, 12};
    int result = sumEvenDivThree2(a, 0, sizeof(a) / sizeof(a[0]));
    printf("sum: %i\n", result);

}