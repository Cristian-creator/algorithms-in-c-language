#include <stdio.h>

void suma_max(int v[], int n, int a[],int *k) {
    int i;
    *k = 0;

    for (i = 0; i < n; i++)
        if ((v[i] >= 0) && !(v[i] % 2)) {
            a[*k] = v[i];
            *k = *k + 1;
        }
}

void main() {
    int v[100], a[100];
    int i, n,k;

    printf("n=");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("v[%d]=", i);
        scanf("%i", &v[i]);
    }

    int smax = 0;
    
    suma_max(v, n, a, &k);

    for (i = 0; i < k; i++) {
        printf("%i ", a[i]);
        smax += a[i];
    }

    if (k == 0)
        printf("nu exista");
    else
        printf("\nSuma maxima este: %i ", smax);
}






