#include <stdio.h>

int validare(int vectorSolutie[], int pozitieVerificata) {
    int rez = 1;
    
    for(int i = 0;i < pozitieVerificata;i++) {
        if(vectorSolutie[i] == vectorSolutie[pozitieVerificata]) rez = 0;
    }

    return rez; 
}

void afisare(int vector[], int n) {
    for(int i = 0;i < n;i++) {
        printf("v[%i] = %i\n", i + 1, vector[i]);
    }
    printf("\n");
}

void aranjamente(int n, int k, int vectorSolutie[], int pozitieCurenta) {

    if(pozitieCurenta == k) afisare(vectorSolutie, k);
    else {

        int val;
        for(val = 1;val <= n;val++) {
            vectorSolutie[pozitieCurenta] = val;
            if(validare(vectorSolutie, pozitieCurenta)) aranjamente(n, k,vectorSolutie, pozitieCurenta + 1);
        }

    }
}

void main() {
    int n, v[10], k;
    printf("n = ");
    scanf("%d", &n);

    printf("k = ");
    scanf("%d", &k);

    aranjamente(n, k, v, 0);
}