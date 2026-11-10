// Lista · Módulo 11 · Listas
// Exercício P1111 · ★★☆ · Juntar dois rankings já em ordem decrescente
//
// As notas das turmas A e B estão em listas CRESCENTES:
//
//   a: 2 -> 5 -> 8 -> 9 -> NULL
//   b: 1 -> 5 -> 7 -> 10 -> 12 -> NULL
//
// O mural precisa delas juntas, em ordem DECRESCENTE. Escreva
//
//   No *intercala_decrescente(No *a, No *b)
//
// que faz isso numa passada só, SEM criar nem liberar nó nenhum: a cada
// passo, tire da frente de a ou de b o nó de menor valor e ponha-o no
// INÍCIO da lista resultado. Libere o resultado no fim.
//
//   Saída esperada:
//   a: 2 -> 5 -> 8 -> 9 -> NULL
//   b: 1 -> 5 -> 7 -> 10 -> 12 -> NULL
//   mural: 12 -> 10 -> 9 -> 8 -> 7 -> 5 -> 5 -> 2 -> 1 -> NULL
//
// Dicas:
// 1. Inserir sempre no início inverte a ordem: se você tira os nós do
//    menor para o maior, eles ficam do maior para o menor.
// 2. No laço: escolha o nó (No *menor), avance a ou b, e faça
//    menor->prox = resultado; resultado = menor.
// 3. Quando uma lista acaba, continue tirando da outra (não dá para só
//    "pendurar" o resto, porque ele está na ordem errada).
// 4. Resposta esperada: a saída acima. São n + m passos: O(n + m).
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
    int va[4] = {2, 5, 8, 9};
    int vb[5] = {1, 5, 7, 10, 12};
    No *a = de_vetor(va, 4);
    No *b = de_vetor(vb, 5);
    printf("a: ");
    imprime(a);
    printf("b: ");
    imprime(b);

    // escreva intercala_decrescente acima do main e use-a aqui

    libera(a); // quando a intercalação existir, libere só o resultado
    libera(b);
    return 0;
}
