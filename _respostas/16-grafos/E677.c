// 0113 · Juntando tudo: a central de entregas
// Exercício E677 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define N 20

const char *palavras[N] = {"GATO", "GATA", "RATO", "MATO", "MOTO", "BOTA", "ROTA", "ROSA", "BOLA", "COLA",
                           "PEIXE", "MOLA", "MALA", "SALA", "SOLA", "LATA", "LAMA", "CAMA", "CASA", "MATA"};

// vizinhas: mesmo tamanho e exatamente uma letra diferente
bool vizinhas(const char *a, const char *b) {
    if (strlen(a) != strlen(b)) return false;
    int diferentes = 0;
    for (size_t i = 0; a[i] != '\0'; i++) diferentes += a[i] != b[i];
    return diferentes == 1;
}

int indice(const char *p) {
    for (int i = 0; i < N; i++)
        if (strcmp(palavras[i], p) == 0) return i;
    return -1;
}

void escada(const char *de, const char *para) {
    int origem = indice(de), destino = indice(para);
    if (origem < 0 || destino < 0) {
        printf("%s -> %s: palavra fora da lista\n", de, para);
        return;
    }
    int pai[N], dist[N], fila[N], inicio = 0, fim = 0;
    for (int i = 0; i < N; i++) dist[i] = -1;
    dist[origem] = 0;
    pai[origem] = -1;
    fila[fim++] = origem;
    while (inicio < fim) {
        int u = fila[inicio++];
        for (int v = 0; v < N; v++) // o grafo é implícito: a aresta sai de uma conta
            if (dist[v] == -1 && vizinhas(palavras[u], palavras[v])) {
                dist[v] = dist[u] + 1;
                pai[v] = u;
                fila[fim++] = v;
            }
    }
    if (dist[destino] == -1) {
        printf("%s -> %s: impossível\n", de, para);
        return;
    }
    int rota[N], n = 0;
    for (int v = destino; v != -1; v = pai[v]) rota[n++] = v;
    printf("%s -> %s em %d passo(s):", de, para, dist[destino]);
    for (int i = n - 1; i >= 0; i--) printf(" %s", palavras[rota[i]]);
    printf("\n");
}

int main(void) {
    escada("GATO", "BOLA");
    escada("CASA", "ROSA");
    escada("MOTO", "CAMA");
    escada("GATO", "PEIXE");
    return 0;
}
