#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void rucsac_d(float q, int n, float* c, int* b){
	float qr;
	int i, l;
	qr = q;

	for (i = 0;i < n;i++)
		if (qr >= c[i]) {
			b[i] = 1;
			qr = qr - c[i];
		} else b[i] = 0;
}

void main()
{
    float q, c[20], b[20],v[20],aux,vt;
    int n,i,ok;

    printf("n=");
    scanf("%d", &n);
    printf("q=");
    scanf("%f", &q);
    for (i = 0; i < n; i++)
    {
       
        printf("c[%d]=", i);
        scanf("%f", &c[i]);
        printf("v[%d]=", i);
        scanf("%f", &v[i]);
    }

    // find locally optimal choice
    do {
        ok = 0;
        for(i=0;i<n-1;i++)
            if(v[i]/c[i]<v[i+1]/c[i+1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                aux = c[i];
                c[i] = c[i + 1];
                c[i + 1] = aux;
                ok = 1;
            }
    } while (ok == 1);
    
    rucsac_c(q, n, c, b);
    vt = 0;
    for (i = 0; i < n; i++)
    {
        vt = vt + v[i] * b[i];
        printf("capacitate obiect=%f venit obiect=%f selectat=%f\n", c[i], v[i], b[i]);
    }

    printf("venit  total=%f\n", vt);
}