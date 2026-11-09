// Lista · Módulo 11 · Listas
// Exercício P1129 · ★★★ · Palíndromo com memória O(1)
//
// O código do bilhete premiado da quermesse é um palíndromo (lê-se igual
// nos dois sentidos). Os dígitos estão numa lista SIMPLES. Escreva
//
//   bool palindromo(No *inicio)
//
// sem vetor, sem pilha e sem lista nova: ache o meio (lento e rápido),
// INVERTA a segunda metade, compare as duas metades andando juntas e, no
// fim, desinverta a segunda metade para devolver a lista como estava.
// Teste com 1 2 3 2 1, 4 7 7 4, 1 2 3 1 e 9, mostrando a lista depois do
// teste (para provar que ela foi restaurada).
//
//   Saída esperada:
//   1 2 3 2 1: sim | depois: 1 2 3 2 1
//   4 7 7 4: sim | depois: 4 7 7 4
//   1 2 3 1: não | depois: 1 2 3 1
//   9: sim | depois: 9
//
// Dicas:
// 1. Lento e rápido começam no início; enquanto rapido->prox e
//    rapido->prox->prox existirem, lento anda 1 e rápido anda 2. A segunda
//    metade começa em lento->prox.
// 2. Inverta a partir de lento->prox (a inversão comum, que devolve o novo
//    início) e guarde esse início. Compare com a primeira metade até a
//    segunda acabar.
// 3. Restaure com lento->prox = inverte(inicio_da_segunda). Com n ímpar, o
//    nó do meio fica na primeira metade e não precisa ser comparado.
// 4. Resposta esperada: a saída acima. O(n) de tempo, O(1) de memória.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

// monta uma lista com os n valores do vetor, na mesma ordem
No *de_vetor(const int v[], int n) {
    No *inicio = NULL;
    for (int i = n - 1; i >= 0; i--) {
        No *novo = malloc(sizeof *novo);
        if (novo == NULL) {
            fprintf(stderr, "sem memória\n");
            exit(1);
        }
        novo->valor = v[i];
        novo->prox = inicio;
        inicio = novo;
    }
    return inicio;
}

void imprime(const No *inicio) {
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL\n");
}

void libera(No *inicio) {
    while (inicio != NULL) {
        No *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

int main(void) {

    return 0;
}
