// Se cere să se așeze 8 regine pe o tablă de șah astfel încât să nu existe două regine care să se atace. 
// Trebuie găsite toate posibilitățile de așezare a celor 8 regine pe tabla de șah. 

#include <stdio.h>

int validare(int v[], int poz) {
	int i;
	int rez = 1;

	i = 0;

	while (i < poz && v[poz] != v[i] && abs(i - poz) != abs(v[i] - v[poz]))
		i++;

	if (i < poz) rez = 0;

	return rez;
}

void afisare(int v[], int n) {
	int i,j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (v[i] == j) printf("%c", 'x');
			else printf("%c", '0');

		printf("\n");
	}

	printf("\n \n");
}

void regine(int n, int v[], int poz) {
	if (poz == n)
		afisare(v, n);
	else {
		for (int val = 0; val < n; val++) {
			v[poz] = val;

			if (validare(v, poz)) regine(n, v, poz+1);
		}
	}
}

void main() {
	int n, v[10];

	printf("n:");
	scanf("%d", &n);	
	
    regine(n, v, 0);
}