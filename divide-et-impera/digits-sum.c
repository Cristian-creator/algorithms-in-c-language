#include <stdio.h>

int digitsSum(int n) {
    int sum;
    if(!n) sum = 0;
    else {
        sum = digitsSum(n / 10) + n % 10;
    } 
}

int oddDigitsSum(int n) {
    int sum;
    if(!n) sum = 0;
    else {
        int isOdd = (n % 10 % 2) ? n % 10 : 0;
        sum = digitsSum(n / 10) + isOdd;
    }
}

void main() {
    // int n = 258;  
    // int result = digitsSum(n);
    // printf("%i\n", result);

    int n = 12345;  
    int result = oddDigitsSum(n);
    printf("%i\n", result);
}