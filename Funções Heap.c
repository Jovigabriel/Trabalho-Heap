#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int tam = 0;

int indiceFilhoEsq(int indice) {
  int indFilho = (2 * indice) + 1;
  if (indice >= tam || indFilho >= tam)
    return -1;
  else
    return indFilho;
}

int indiceFilhoDir(int indice) {
  int indFilho = (2 * indice) + 2;
  if (indice >= tam || indFilho >= tam)
    return -1;
  else
    return indFilho;
}

int indicePai(int x) {
  int indice = (int)floor((x - 1) / 2);
  if (x = 0 || x >= tam) {
    return -1;
  } else {
    return indice;
  }
}

void AjustarSubindo(int *v, int pos) {
  if (pos != -1) {
    int pai = indicePai(pos);
    if (pai != -1) {
      if (v[pos] < v[pai]) {
        int aux = v[pos];
        v[pos] = v[pai];
        v[pai] = aux;
        AjustarSubindo(v, pai);
      }
    }
  }
}

void Inserir(int *v, int x) {
  v[tam] = x;
  tam++;

  AjustarSubindo(v, tam - 1);
}

void ajustarDescendo(int *v, int pos) {
  if (pos != -1 && indiceFilhoEsq(pos) != -1) {
    int IndiceMenorFilho = indiceFilhoEsq(pos);
    if (indiceFilhoDir(pos) != -1 &&
        v[indiceFilhoDir(pos)] < v[IndiceMenorFilho]) {
      IndiceMenorFilho = indiceFilhoDir(pos);
    }
    if(v[IndiceMenorFilho]<v[pos]){
      int aux = v[pos];
      v[pos] = v[IndiceMenorFilho];
      v[IndiceMenorFilho] = aux;
      ajustarDescendo(v, IndiceMenorFilho);
    }
  }
}

void imprimir(int *v, int tam) {
  for (int i = 0; i < tam; i++) {
    printf(" %d", v[i]);
  }
}

int remover(int *v) {
  if (tam == 0) {
    return -1;
  } else {
    int aux = v[0];
    v[0] = v[tam - 1];
    tam--;
    ajustarDescendo(v, 0);
    return aux;
  }
}
