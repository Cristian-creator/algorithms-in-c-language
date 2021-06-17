#include <stdio.h>

void afis(int v[], int n) {
	int i;

	for (i = 0;i < n;i++)
        printf("%d ", v[i]);

	printf("\n");
}

int valid(int v[], int poz) {
	int i,rez;
	i = 0;

	while (i < poz && v[i] != v[poz])
		i++;

	if (i < poz) rez = 0;
	else rez = 1;
	
    return rez;
}

void permutari(int v[], int n, int poz) {
	int val;

	if (poz == n) afis(v, n);
	else {
        for (val = 1;val <= n;val++) {
			v[poz] = val;

			if (valid(v, poz) == 1) permutari(v, n, poz+1);
		}
	}
}

void main() {
	int v[20], n;

	printf("n=");
	scanf("%d", &n);
    
	permutari(v, n, 0);
}