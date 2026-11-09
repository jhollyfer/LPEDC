// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0928 · ★★★ · A tabela do Barezão

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMES 20

typedef struct {
    char nome[16];
    int pontos;
    int vitorias;
    int saldo;
} Time;

int acha_ou_cria(Time t[], int *n, const char *nome) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(t[i].nome, nome) == 0) {
            return i;
        }
    }
    if (*n == MAX_TIMES) {
        return -1;
    }
    Time novo = {"", 0, 0, 0};
    strcpy(novo.nome, nome);
    t[*n] = novo;
    return (*n)++;
}

void resultado(Time *t, int feitos, int sofridos) {
    t->saldo += feitos - sofridos;
    if (feitos > sofridos) {
        t->pontos += 3;
        t->vitorias++;
    } else if (feitos == sofridos) {
        t->pontos += 1;
    }
}

int compara(const void *a, const void *b) {
    const Time *x = a, *y = b;
    if (x->pontos != y->pontos) {
        return y->pontos - x->pontos;
    }
    if (x->saldo != y->saldo) {
        return y->saldo - x->saldo;
    }
    return strcmp(x->nome, y->nome);
}

int main(void) {
    const char *jogos = "/tmp/p0928_jogos.txt";
    const char *tabela = "/tmp/p0928_tabela.txt";

    FILE *arq = fopen(jogos, "w");
    if (arq == NULL) {
        perror(jogos);
        return 1;
    }
    fprintf(arq, "Nacional 2 Fast 1\nManaus 1 Amazonas 1\nFast 0 Manaus 3\n");
    fprintf(arq, "Amazonas 2 Nacional 2\nNacional 1 Manaus 0\nAmazonas 3 Fast 1\n");
    fclose(arq);

    arq = fopen(jogos, "r");
    if (arq == NULL) {
        perror(jogos);
        return 1;
    }
    Time t[MAX_TIMES];
    int n = 0;
    char casa[16], fora[16];
    int gc, gf;
    while (fscanf(arq, "%15s %d %15s %d", casa, &gc, fora, &gf) == 4) {
        int a = acha_ou_cria(t, &n, casa);
        int b = acha_ou_cria(t, &n, fora);
        if (a < 0 || b < 0) {
            break;
        }
        resultado(&t[a], gc, gf);
        resultado(&t[b], gf, gc);
    }
    fclose(arq);

    qsort(t, n, sizeof(Time), compara);

    arq = fopen(tabela, "w");
    if (arq == NULL) {
        perror(tabela);
        remove(jogos);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(arq, "%d. %-9s %2d pts  %d V  saldo %+d\n", i + 1, t[i].nome, t[i].pontos,
                t[i].vitorias, t[i].saldo);
    }
    fclose(arq);

    arq = fopen(tabela, "r");
    if (arq != NULL) {
        char linha[100];
        while (fgets(linha, sizeof linha, arq) != NULL) {
            printf("%s", linha);
        }
        fclose(arq);
    }
    remove(jogos);
    remove(tabela);
    return 0;
}
