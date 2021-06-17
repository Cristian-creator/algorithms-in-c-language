// Plata unei sume cu/fara bancnota unitate. Fie n tipuri de bancnote cu valori nominale t index i.
// Din fiecare tip este disponibila cantitatea nr indice i. Sa se det toate modalitatile
// prin care se poate plati o suma S folosind acele bancnote.
#include <stdio.h>

int valid(int poz, int nrb, int sp, int sc) {
	int rez;

	if (poz == nrb - 1)
		if (sp == sc)
			rez = 1;
		else
			rez = 0;
	else
		if (sp >= sc)
			rez = 1;
		else
			rez = 0;

	return rez;
}

void afisare(int v[], int n, int t[]) {
	int i,s=0;

	for (i = 0; i < n; i++) {
		printf("%d * %d\n", v[i], t[i]);
		s += v[i] * t[i];
	}

	printf("Suma in aceasta varianta este: %d\n\n", s);
}

void plata(int sp, int sc, int t[], int nrb, int nr[], int poz, int v[]) {
	int val;

	if (poz == nrb)
		afisare(v, nrb, t);
	else {
		for (val = 0; val <= nr[poz]; val++) {
			v[poz] = val;
			sc += val * t[poz];

			if (valid(poz, nrb, sp, sc))
				plata(sp, sc, t, nrb, nr, poz + 1, v);

			sc -= val * t[poz];
		}
	}
}

void main() {
	int nrb, t[10], nr[10], sp, i,v[10];
	
    printf("nrb=");
	scanf("%d", &nrb);

	for (i = 0; i < nrb; i++) {

		printf("t[%d]=",i);
		scanf("%d", &t[i]);

		printf("nr[%d]=",i);
		scanf("%d", &nr[i]);

	}

	printf("suma plata=");
	scanf("%d", &sp);

	plata(sp, 0, t, nrb, nr, 0, v);
}