#include <stdio.h>

// Să se scrie subprogramul C care permite plata unei sume  folosind 
// cît mai puține bancnote din tipurile (valorile) , știind că printre acestea 
// se află și bancnota cu valoare unitate. Sunt disponibile 
// cantități nelimitate din fiecare tip de bancnotă. 

void plata_unitate(int s, int* t, int n, int* sol) {
    int i, sr;
    sr = s;

    for (i = 0; i < n; i++) {
        sol[i] = sr / t[i];
        sr = sr % t[i];
    }
}

void main() {
    int s, t[20], n, sol[20], i, aux, ok;

    printf("n=");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("t[%d]=", i);
        scanf("%d", &t[i]);
    }

    printf("suma=");
    scanf("%d", &s);

    do {
        ok = 0;
        for(i = 0;i < n-1;i++)
            if (t[i] < t[i + 1]) {
                aux = t[i];
                t[i] = t[i + 1];
                t[i + 1] = aux;
                ok = 1;
            }
    } while (ok == 1);

    plata_unitate(s, t, n, sol);

    for (i = 0; i < n; i++)
        printf("%d*%d\n", sol[i], t[i]);

}