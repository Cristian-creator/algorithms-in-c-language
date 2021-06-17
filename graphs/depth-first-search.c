#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int insereaza_stiva(int *stiva,int n, int vf) { 
    int i;
    
    for(i = n - 1;i >= 0;i--)
        stiva[i + 1] = stiva[i];
    
    stiva[0] = vf;
    n++;

    return n;
}

int sterge_stiva(int *stiva, int n) { 
    int i;

    for (i = 0;i < n - 1;i++)
        stiva[i] = stiva[i + 1];
    
    n--;
    
    return n;
}

int citeste_stiva(int *stiva, int n) {
    return stiva[0];
}

void depth_first(int v0,int **a,int n) { 
    int *stiva, *m, i, nr_c, gasit;
    // se aloca memorie pentru stiva si pentru m – n elemente
   
    stiva = (int*)malloc(n * sizeof(int));
    m=(int*)malloc(n * sizeof(int));
    
    for(int i = 0;i < n;m[i++] = 0);
    
    nr_c = 0;
    nr_c = insereaza_stiva(stiva,nr_c,v0);
    
    m[v0]=1;
    
    printf("\n%i",v0+1);
    
    while(nr_c) { 
        i = citeste_stiva(stiva,nr_c);
        gasit = 0;
        
        for(int k = 0;(k < n) && !gasit;k++)
        
        if((a[i][k]==1)&&(m[k]==0)) { 
            nr_c = insereaza_stiva(stiva,nr_c,k);
            m[k] = 1;
            printf("\n%i",k + 1);  
            gasit=1;
        }
        if(!gasit) nr_c=sterge_stiva(stiva,nr_c);
    }
    //eliberare memorie alocata – pentru stiva si pentru m;
    free(stiva); free(m);
}

void main() { 
    int n, v0, **a, m, i, j, vf1, vf2;

    printf("Numarul de virfuri:");
    scanf("%i",&n);
    
    a = (int **)malloc(n*sizeof(int*));

    for(i = 0;i < n;i++)
        a[i] = (int*)malloc(n*sizeof(int));
    
    for(i = 0;i < n;i++)
        for(j = 0;j <= i;j++) {
            a[j][i] = 0;
            a[i][j]=0;
        }

    printf("\nNumarul de muchii:");
    scanf("%i",&m);
    
    for(i = 0;i < m;i++) { 
        printf("Virf initial:");scanf("%i",&vf1);
        printf("Virf final:");scanf("%i",&vf2);
        a[vf1-1][vf2-1] = 1;
        a[vf2-1][vf1-1] = 1;
    }

    printf("\nVirful initial pentru parcurgerea DF ");
    scanf("%i",&v0);
 
    printf("\nOrdinea de vizitare a virfurilor grafului este:");
    depth_first(v0-1, a, n);

    for(i = 0;i < n;i++) free(a[i]);
    free(a);
    getch();
}