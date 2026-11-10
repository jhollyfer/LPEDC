// Lista · Módulo 13 · Busca e ordenação
// Exercício P1328 · ★★★ · Merge sort na lista encadeada
//
// Os valores dos pedidos da lanchonete (em reais) estão numa lista
// encadeada: 58, 12, 97, 33, 12, 75, 4, 41, 66. Ordene a LISTA com merge
// sort, sem vetor auxiliar e sem malloc durante a ordenação:
//
// a) No *divide(No *l): corta a lista no meio com dois ponteiros (lento anda
//    1, rápido anda 2, rápido começa em l->prox) e devolve a segunda metade;
// b) No *intercala(No *a, No *b): junta duas listas ordenadas RELIGANDO os
//    nós (use um nó "cabeça" local para não tratar o primeiro à parte);
// c) No *merge_sort(No *l): lista vazia ou de um nó já está ordenada; senão,
//    divide, ordena as duas metades e intercala.
//
// Monte a lista com malloc, mostre antes e depois e libere tudo no fim.
//
//   Saída esperada:
//   antes : 58 12 97 33 12 75 4 41 66
//   depois: 4 12 12 33 41 58 66 75 97
//
// Dicas:
// 1. Para montar na ordem certa com insere_inicio, insira de trás para frente.
// 2. Nó cabeça local: No cabeca = {0, NULL}; No *fim = &cabeca; ... e no fim
//    devolva cabeca.prox.
// 3. Use <= na intercalação para o merge continuar estável.
// 4. Na lista, o merge sort é o algoritmo natural: não precisa de acesso por
//    índice e não gasta memória extra, ao contrário do vetor.
// 5. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

int main(void) {

    return 0;
}
