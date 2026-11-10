// Lista · Módulo 11 · Listas
// Exercício P1120 · ★★☆ · Girar a escala de plantão
//
// A escala de plantão da semana é a lista 1 -> 2 -> 3 -> 4 -> 5. Girar k
// posições para a direita leva os k últimos para a frente: com k = 2, fica
// 4 -> 5 -> 1 -> 2 -> 3. Escreva
//
//   No *gira(No *inicio, int k)
//
// que faz isso só religando nós (sem malloc, sem trocar valores) e devolve
// o novo início. k pode ser maior que o tamanho: girar 7 numa lista de 5 é
// o mesmo que girar 2. Aplique, um depois do outro, k = 2, k = 7 e k = 0.
//
//   Saída esperada:
//   escala: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
//   k = 2:  4 -> 5 -> 1 -> 2 -> 3 -> NULL
//   k = 7:  2 -> 3 -> 4 -> 5 -> 1 -> NULL
//   k = 0:  2 -> 3 -> 4 -> 5 -> 1 -> NULL
//
// Dicas:
// 1. Primeira passada: conte n e ache o último. Faça k = k % n; se der 0,
//    devolva o início sem mexer.
// 2. Ligue o último no primeiro (a lista vira circular por um instante).
//    Ande n - k nós a partir do último: esse nó é o novo último. O seguinte
//    dele é o novo início; corte o círculo com novo_ultimo->prox = NULL.
// 3. Resposta esperada: a saída acima. O(n) e memória O(1).
//
// Escreva sua resposta abaixo:

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
