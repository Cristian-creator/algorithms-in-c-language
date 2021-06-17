#include <stdio.h>

int valid(int v[], int poz) {
	int i, rez;
	rez = 1;

	if (poz > 0 && v[poz] <= v[poz - 1])
		rez = 0;

	return rez;
}

void afis(int v[], int n) {
	int i;

	for (i = 0;i < n;i++)
		printf("%d ", v[i]);

	printf("\n");
}

void combinari(int v[], int n, int poz, int k) {
	int val;

	if (poz == k)
		afis(v, k);
	else {
        for (val = 1;val <= n;val++) {
            v[poz] = val;
			if (valid(v, poz) == 1) combinari(v, n, poz + 1, k);
		}
	}
}

void main() {
	int v[20], n, k;

	printf("n=");
	scanf("%d", &n);
	printf("k=");
	scanf("%d", &k);
	combinari(v, n, 0, k);
}

