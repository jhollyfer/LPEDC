// Lista · Módulo 11 · Listas
// Exercício P1117 · ★★☆ · Pares na frente, sem mudar a ordem
//
// As senhas do guichê chegaram nesta ordem: 7, 2, 9, 4, 4, 1, 6. O guichê
// par vai atender primeiro, então as senhas pares devem vir antes das
// ímpares, mas cada grupo mantendo a ordem de chegada (uma partição
// ESTÁVEL). Escreva
//
//   No *pares_primeiro(No *inicio)
//
// que reorganiza a lista só religando os nós (sem malloc, sem free, sem
// trocar valores) e devolve o novo início.
//
//   Saída esperada:
//   antes:  7 -> 2 -> 9 -> 4 -> 4 -> 1 -> 6 -> NULL
//   depois: 2 -> 4 -> 4 -> 6 -> 7 -> 9 -> 1 -> NULL
//
// Dicas:
// 1. Monte duas listas enquanto percorre: a dos pares e a dos ímpares,
//    cada uma com ponteiro para o início e para o fim. Cada nó vai para o
//    FIM da sua lista (é isso que mantém a ordem).
// 2. No fim, ligue o fim dos pares no início dos ímpares e ponha NULL no
//    fim dos ímpares. Cuidado com as listas que ficarem vazias.
// 3. Resposta esperada: a saída acima. Uma passada: O(n).
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
    int senhas[7] = {7, 2, 9, 4, 4, 1, 6};
    No *guiche = de_vetor(senhas, 7);
    printf("antes:  ");
    imprime(guiche);

    // escreva pares_primeiro acima do main e use-a aqui

    libera(guiche);
    return 0;
}
