// 0102 · Heap e fila de prioridade
// Exercício E609 · ★★☆
//
// Na fila de prioridade, é comum tirar o máximo e logo em seguida colocar um
// valor novo. Fazer heap_remove e depois heap_insere dá duas descidas/subidas.
// Escreva troca_topo(h, x), que faz isso numa operação só: guarda o máximo,
// põe x na raiz (v[0]), faz x descer até o lugar certo e devolve o máximo
// antigo. Pode supor o heap não vazio. A struct Heap do heap.h tem os campos
// v e n à mostra, mas a função desce do heap.c é static: escreva a sua.
//
// O main insere 15, 35, 25, 45 e 5 e depois troca o topo duas vezes:
//
//   Saída esperada:
//   depois das 5 inserções: [45 35 25 15 5]
//   saiu 45, entrou 40: [40 35 25 15 5]
//   saiu 40, entrou 10: [35 15 25 10 5]
//
// Dicas:
// 1. A descida: enquanto 2i + 1 < n, escolha o MAIOR filho f; se v[i] já é
//    >= v[f], pare; senão troque v[i] com v[f] e siga com i = f.
// 2. Na segunda troca, o 10 desce duas vezes: primeiro troca com o 35 e
//    depois com o 15.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete troca_topo):

#include <stdio.h>
#include "heap.h"

int troca_topo(Heap *h, int x) {
    (void)h; // apague estas duas linhas quando escrever a função
    (void)x;
    return 0;
}

int main(void) {
    Heap *h = heap_cria(8);
    int valores[] = {15, 35, 25, 45, 5};
    for (int i = 0; i < 5; i++) {
        heap_insere(h, valores[i]);
    }
    printf("depois das 5 inserções: ");
    heap_mostra(h);
    printf("\n");

    int novos[] = {40, 10};
    for (int i = 0; i < 2; i++) {
        int saiu = troca_topo(h, novos[i]);
        printf("saiu %d, entrou %d: ", saiu, novos[i]);
        heap_mostra(h);
        printf("\n");
    }

    heap_libera(h);
    return 0;
}
