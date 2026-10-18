// 0097 · Árvores
// Exercício E581 · ★★★
//
// Ache o bug. Este programa monta a árvore da família e deveria mostrar:
//
//   Saída esperada:
//   Altura da família: 2
//
// e terminar sem nenhum erro de memória. Ele tem DOIS bugs (de propósito):
// um dá o número errado e o outro faz o AddressSanitizer parar o programa
// com "heap-use-after-free". Rode, leia o relatório, ache os dois e conserte.
//
//   vovo
//   ├── mae
//   │   ├── voce
//   │   └── irma
//   └── tio
//
// Dicas:
// 1. Calcule à mão o que a altura devolve para uma folha. Pela convenção do
//    curso, folha tem altura 0.
// 2. No relatório do ASan, procure a linha do "READ" e a linha do "freed by".
//    Depois de free(n), ainda dá para ler n->qtd?
// 3. Resposta esperada: (1) "int maior = 0" faz a folha devolver 1 e a
//    árvore dar 3; o certo é começar com -1. (2) libera chama free(n) antes
//    de visitar os filhos e depois lê n->qtd e n->filhos de memória
//    devolvida; o free tem que vir depois do laço. Consertado: "Altura da
//    família: 2", sem erro.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4

typedef struct No {
    char nome[16];
    struct No *filhos[MAX_FILHOS];
    int qtd;
} No;

No *novo(const char *nome) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    strcpy(n->nome, nome);
    n->qtd = 0;
    return n;
}

No *adiciona(No *pai, const char *nome) {
    No *filho = novo(nome);
    pai->filhos[pai->qtd++] = filho;
    return filho;
}

int altura(const No *n) {
    int maior = 0;
    for (int i = 0; i < n->qtd; i++) {
        int h = altura(n->filhos[i]);
        if (h > maior) {
            maior = h;
        }
    }
    return maior + 1;
}

void libera(No *n) {
    No *atual = n;
    free(atual);
    for (int i = 0; i < n->qtd; i++) {
        libera(n->filhos[i]);
    }
}

int main(void) {
    No *vovo = novo("vovo");
    No *mae = adiciona(vovo, "mae");
    adiciona(vovo, "tio");
    adiciona(mae, "voce");
    adiciona(mae, "irma");

    printf("Altura da família: %d\n", altura(vovo));
    libera(vovo);
    return 0;
}
