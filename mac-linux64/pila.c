#include <stdio.h>

typedef struct
{
  int *v;
  int topo;
  int max;
} pilha;

int pilhaVazia (pilha  p)
{
  return p.topo;
}

pilha * ciraPilha (int max)
{
  pilha * p;
  p = malloc (sizeof (pilha));
  p -> v = malloc (max sizeof (int));
  p -> topo = 0;
  p -> max = max;
  return p;
}

void empilha (pilha * p, int x)
{
  if(p -> topo == p -> max )
    realocaPilha(p);
  p -> v[p -> topo] = x;
  p -> topo ++;
}

void realocaPilha (pilha * p)
{
  int maxNovo = p -> max * 1.2;
  int * w, i;
  w = malloc(maxNovo * sizeof (int);
  for (i=0;i < p -> max; i++)
    w[i]=p -> v[i];
  free(p -> v);
  p -> v = w;
}


