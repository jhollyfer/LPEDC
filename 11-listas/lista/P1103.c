// Lista · Módulo 11 · Listas
// Exercício P1103 · ★☆☆ · Reajuste de preço achando o nó
//
// A lista do hortifruti guarda código e preço de cada produto. Escreva
//
//   Produto *busca(Produto *inicio, int codigo)
//
// que devolve o ENDEREÇO do nó com aquele código (ou NULL). Com esse
// ponteiro em mãos, o main muda o preço direto no nó, sem percorrer de novo.
// Monte a lista inserindo no início os produtos (40, 6.00), (30, 8.50),
// (20, 3.20) e (10, 12.00); reajuste o 30 em 10% e tente reajustar o 99.
//
//   Saída esperada:
//   Antes:  10: 12.00 | 20: 3.20 | 30: 8.50 | 40: 6.00 |
//   Código 30: 8.50 -> 9.35
//   Código 99: não encontrado
//   Depois: 10: 12.00 | 20: 3.20 | 30: 9.35 | 40: 6.00 |
//
// Dicas:
// 1. for (Produto *p = inicio; p != NULL; p = p->prox) if (p->codigo ==
//    codigo) return p;
// 2. Quem recebe o ponteiro pode alterar p->preco: o nó é o mesmo que está
//    na lista, não uma cópia.
// 3. Resposta esperada: a saída acima (8.50 * 1.10 = 9.35).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
    int codigo;
    double preco;
    struct produto *prox;
} Produto;

Produto *insere_inicio(Produto *inicio, int codigo, double preco) {
    Produto *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->codigo = codigo;
    novo->preco = preco;
    novo->prox = inicio;
    return novo;
}

void imprime(const char *rotulo, const Produto *inicio) {
    printf("%s", rotulo);
    for (const Produto *p = inicio; p != NULL; p = p->prox) {
        printf(" %d: %.2f |", p->codigo, p->preco);
    }
    printf("\n");
}

void libera(Produto *inicio) {
    while (inicio != NULL) {
        Produto *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

int main(void) {

    return 0;
}
