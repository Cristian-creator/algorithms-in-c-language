#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//varianta continua
void rucsac_c(float q, int n, float* c, float* b)
{
    float qr;
    int i, j;
    qr = q;
    i = 0;
    while(i<n && qr>0)
        if (c[i] < qr)
        {
            b[i] = 1;
            qr = qr - c[i];
            i++;
        }
        else {
            b[i] = qr / c[i];
            qr = 0;
            for (j = i + 1; j < n; j++)
                b[j] = 0;

        }
}

void main() {
    float q, c[20], b[20],v[20],aux,vt;
    int n,i,ok;
    printf("n=");
    scanf("%d", &n);
    printf("q=");
    scanf("%f", &q);
    for (i = 0; i < n; i++) {
        printf("c[%d]=", i);
        scanf("%f", &c[i]);
        printf("v[%d]=", i);
        scanf("%f", &v[i]);
    }
    // find locally optimal choice
    do {
        ok = 0;
        for(i=0;i<n-1;i++)
            if(v[i]/c[i]<v[i+1]/c[i+1])  {
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
    for (i = 0; i < n; i++) {
        vt = vt + v[i] * b[i];
        printf("capacitate obiect=%f venit obiect=%f selectat=%f\n", c[i], v[i], b[i]);
    }

    printf("venit  total=%f\n", vt);
}