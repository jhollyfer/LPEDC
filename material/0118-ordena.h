// ordena.h · as quatro ordenações do módulo, com contador de comparações
#ifndef ORDENA_H
#define ORDENA_H

// todas ordenam v[0..n-1] em ordem crescente
void ord_insertion(int v[], int n); // Θ(n²) no caso médio e no pior
void ord_merge(int v[], int n);     // Θ(n log n) sempre; usa um rascunho de n
void ord_heap(int v[], int n);      // Θ(n log n) sempre; in-place
void ord_quick(int v[], int n);     // Θ(n log n) em média; pivô = o do meio

// comparações entre elementos feitas desde o último ord_zera_contagem()
void ord_zera_contagem(void);
long ord_contagem(void);

// 1 se v[0..n-1] está em ordem crescente, 0 se não está
int ord_confere(const int v[], int n);

#endif
