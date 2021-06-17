#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include<malloc.h>

int insereaza_coada(int *coada,int n, int vf)
{ coada[n]=vf;
  n++;
  return n;
}

int extrage_coada(int *coada,int n, int *vf)
{ int i;
  *vf=coada[0];
  for(i=0;i<n-1;i++)
    coada[i]=coada[i+1];
  n--;
  return n;
}

void breadth_first(int v0,int **a,int n)
{ int *coada, *m,i,nr_c,k;
  coada=(int*) malloc(n*sizeof(int));
  m=(int*) malloc (n*sizeof(int));
  for(i=0;i<n;m[i++]=0);
  nr_c=0;
  nr_c=insereaza_coada(coada,nr_c,v0);
  m[v0]=1;
  while(nr_c)
  { nr_c=extrage_coada(coada,nr_c,&i);
    printf("\n%i",i+1);
    for(k=0;k<n;k++)
     if((a[i][k]==1)&&(m[k]==0))
     { nr_c=insereaza_coada(coada,nr_c,k);
       m[k]=1;
     }
  }
  free(coada);
  free(m);
}

void main()
{ int n,v0,**a,m,i,j,vf1,vf2;
printf("Numarul de virfuri:");
  scanf("%i",&n);
  //se va aloca memorie pentru matricea a
  a=(int **)malloc(n*sizeof(int*));
  for(i=0;i<n;i++)
    a[i]=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    for(j=0;j<=i;j++)
      a[j][i]=a[i][j]=0;
  printf("\nNumarul de muchii:");
  scanf("%i",&m);
  for(i=0;i<m;i++)
  { printf("Virf initial:");scanf("%i",&vf1);
    printf("Virf final:");scanf("%i",&vf2);
    a[vf1-1][vf2-1]=a[vf2-1][vf1-1]=1;
  }
  printf("\nVirful initial pentru parcurgerea BF ");
  scanf("%i",&v0);
  printf("\nOrdinea de vizitare a virfurilor grafului este:");
  breadth_first(v0-1,a,n);
  //se va elibera zona de memorie alocata pentru matricea a
  for(i=0;i<n;i++) free(a[i]);
  free(a);
}
