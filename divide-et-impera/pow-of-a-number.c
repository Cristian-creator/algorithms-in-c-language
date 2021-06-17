#include <stdio.h>

// metoda reducerii
long powNum(int num, int power) {
    int result;
    if(!power) result = 1;
    else {
        result = powNum(num, power - 1) * num;
    }
    return result;
}

void main() {
    int num = 2, power = 3;
    long result = powNum(num, power);

    printf("%lu", result);
}