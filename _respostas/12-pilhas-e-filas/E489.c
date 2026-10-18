// 0082 · Pilha
// Exercício E489 · ★★☆

#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0082-pilha/pilha.c"

int soma_pedido(Pilha *p) {
    Pilha *aux = pilha_cria();
    if (aux == NULL) {
        return -1;
    }
    int soma = 0;
    int preco;
    while (pilha_desempilha(p, &preco)) { // tira tudo, somando
        soma += preco;
        pilha_empilha(aux, preco);
    }
    while (pilha_desempilha(aux, &preco)) { // devolve na ordem original
        pilha_empilha(p, preco);
    }
    pilha_libera(aux);
    return soma;
}

int main(void) {
    Pilha *pedido = pilha_cria();
    if (pedido == NULL) {
        return 1;
    }
    pilha_empilha(pedido, 2590);
    pilha_empilha(pedido, 800);
    pilha_empilha(pedido, 1200);

    int total = soma_pedido(pedido);
    printf("Total: R$ %d,%02d\n", total / 100, total % 100);

    int topo;
    if (pilha_topo(pedido, &topo)) {
        printf("Topo continua: R$ %d,%02d (%d itens)\n", topo / 100, topo % 100, pilha_tamanho(pedido));
    }
    pilha_libera(pedido);
    return 0;
}
