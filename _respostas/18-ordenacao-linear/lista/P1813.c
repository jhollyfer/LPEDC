// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1813 · ★★☆ · Três chaves, três passadas estáveis

#include <stdio.h>

#define N 8

typedef struct {
    int id, prioridade, setor, minuto;
} Chamado;

int por_minuto(const Chamado *c) { return c->minuto; }
int por_setor(const Chamado *c) { return c->setor; }
int por_prioridade(const Chamado *c) { return c->prioridade; }

void counting(Chamado v[], int n, int (*chave)(const Chamado *), int k) {
    int c[60] = {0}; // k <= 60
    Chamado saida[N];
    for (int i = 0; i < n; i++) c[chave(&v[i])]++;
    for (int x = 1; x < k; x++) c[x] += c[x - 1];
    for (int i = n - 1; i >= 0; i--) saida[--c[chave(&v[i])]] = v[i]; // estável
    for (int i = 0; i < n; i++) v[i] = saida[i];
}

void mostra(const char *rotulo, const Chamado v[], int n) {
    printf("%-15s", rotulo);
    for (int i = 0; i < n; i++) printf(" #%d", v[i].id);
    printf("\n");
}

int main(void) {
    Chamado v[N] = {{1, 0, 3, 12}, {2, 1, 2, 33}, {3, 0, 1, 15}, {4, 1, 2, 5},
                    {5, 3, 0, 8},  {6, 0, 1, 40}, {7, 2, 4, 20}, {8, 1, 0, 59}};

    counting(v, N, por_minuto, 60);
    mostra("por minuto:", v, N);
    counting(v, N, por_setor, 5);
    mostra("por setor:", v, N);
    counting(v, N, por_prioridade, 4);
    mostra("por prioridade:", v, N);
    for (int i = 0; i < N; i++)
        printf("  #%d prioridade %d, setor %d, minuto %2d\n", v[i].id, v[i].prioridade, v[i].setor, v[i].minuto);
    return 0;
}
