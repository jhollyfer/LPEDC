// Lista · Módulo 16 · Grafos
// Exercício P1603 · ★☆☆ · Da lista para a matriz: o cadastro torto
//
// A rede de amigos de um grupo de corrida está guardada em LISTA de adjacência
// (listas encadeadas com malloc). Amizade é recíproca, então toda ligação
// deveria aparecer nas duas listas. Só que alguém cadastrou uma amizade em um
// sentido só.
//
// Complete as duas funções:
//
//   void lista_para_matriz(No *lista[], int m[V][V]);
//   int confere_simetria(int m[V][V]);
//
// A primeira zera m e marca m[u][v] = 1 para cada nó v da lista de u. A
// segunda mostra cada par i < j com m[i][j] != m[j][i] e devolve quantos
// achou. O main já monta as listas, chama as duas funções, mostra a matriz e
// libera tudo.
//
//   Saída esperada:
//          A B C D E
//   Ana    0 1 1 0 0
//   Bruno  1 0 1 0 1
//   Carla  1 1 0 1 0
//   Davi   0 0 1 0 1
//   Eva    0 1 0 0 0
//   Torto: Davi e Eva
//   Pares tortos: 1
//
// Dicas:
// 1. Percorra a lista de cada u com um ponteiro: for (No *p = lista[u]; p;
//    p = p->prox) m[u][p->v] = 1;
// 2. A conversão custa O(V + E) para percorrer as listas, mais O(V²) para
//    zerar a matriz: a matriz sempre cobra V².
// 3. Na simetria, compare só a metade de cima (j > i): cada par aparece uma
//    vez.
// 4. Resposta esperada: a matriz acima e um único par torto, Davi e Eva.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct No {
    int v;
    struct No *prox;
} No;

const char *nomes[V] = {"Ana", "Bruno", "Carla", "Davi", "Eva"};

void insere(No *lista[], int u, int v) { // põe v no começo da lista de u
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->v = v;
    novo->prox = lista[u];
    lista[u] = novo;
}

void lista_para_matriz(No *lista[], int m[V][V]) {
    (void)lista; // apague e escreva a função
    (void)m;
}

int confere_simetria(int m[V][V]) {
    (void)m; // apague e escreva a função
    return 0;
}

int main(void) {
    No *lista[V] = {NULL};
    int amizades[][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {1, 4}};
    for (int k = 0; k < 5; k++) {
        insere(lista, amizades[k][0], amizades[k][1]);
        insere(lista, amizades[k][1], amizades[k][0]);
    }
    insere(lista, 3, 4); // o cadastro torto: só Davi -> Eva

    int m[V][V];
    lista_para_matriz(lista, m);
    printf("       A B C D E\n");
    for (int i = 0; i < V; i++) {
        printf("%-6s", nomes[i]);
        for (int j = 0; j < V; j++) printf(" %d", m[i][j]);
        printf("\n");
    }
    printf("Pares tortos: %d\n", confere_simetria(m));

    for (int u = 0; u < V; u++)
        while (lista[u]) {
            No *p = lista[u];
            lista[u] = p->prox;
            free(p);
        }
    return 0;
}
