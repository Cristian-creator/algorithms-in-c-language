#include <stdio.h>

void readData(char fileName[], int m[20][20], int *num, int *power) {
    FILE *file = fopen(fileName, "rt");

    fscanf(file, "%i", num);
    fscanf(file, "%i", power);
    
    for (int i = 0;i < *num;i++) {
        for (int j = 0;j < *num;j++) {
            fscanf(file, "%i", &m[i][j]);
        }
    }
    
    fclose(file);
}

void printData(int m[20][20], int num) {
    for(int i = 0;i < num;i++) {
        for(int j = 0;j < num;j++) {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }
}

// int matrixToPow(int m[20][20], int num, int power, int poz1, int poz2) {
//     if(poz1!) { 
//         return 
//         // for(int i = 0;i < num;i++) {

//         // }
//     }
//     else {
//         for(int i = 0;i < num;i++) {
//             m[poz1 + i][poz2] = matrixToPow(m, num, power, poz1++, poz2);
//         }
//     }
// }

// void matrixToPow2(int m[20][20], int result[20][20], int num, int poz1, poz2) {
//     if(num/sqrt(num)) {
//         // return m[poz][num-poz];
//         // int sumOfProducts = 0;
//         // poz = num;
//         // for(int i = 0;i < num;i++, poz--) {
//         //     sumOfProducts += m[i][poz];
//         // }
//         // result[poz][poz] = sumOfProducts;
//     }
// }
void main() {
    int power, num, m[20][20];
    char fileName[30]="matrix.txt";
    
    // printf("numele fisierului: ");
    // scanf("%s", fileName);

    readData(fileName, m, &num, &power);
    printData(m, num);
    
    printf("-------\n");
    matrixToPow(m, num, power, 0, 0);
}