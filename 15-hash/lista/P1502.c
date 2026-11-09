// Lista · Módulo 15 · Tabelas hash
// Exercício P1502 · ★☆☆ · As encomendas nos escaninhos
//
// A portaria do prédio guarda as encomendas numa tabela hash com 7 baldes,
// h(k) = k % 7, e ENCADEAMENTO: cada balde é uma lista encadeada, e a
// encomenda nova entra no INÍCIO da lista do seu balde. Insira os códigos
// 40, 23, 17, 52, 11, 66, 5, 31, 26, mostre a tabela balde por balde e
// libere tudo.
//
//   Saída esperada:
//   0:
//   1:
//   2: 23
//   3: 31 66 52 17
//   4: 11
//   5: 26 5 40
//   6:
//
// Dicas:
// 1. A tabela é um vetor de ponteiros: No *tabela[7] = {NULL};
// 2. Inserir no início custa O(1): novo->prox = tabela[b]; tabela[b] = novo;
// 3. Por isso o último a chegar aparece primeiro na corrente.
// 4. Para liberar, percorra cada corrente guardando o prox antes do free.
// 5. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define M 7

typedef struct No {
    int codigo;
    struct No *prox;
} No;

int main(void) {

    return 0;
}
