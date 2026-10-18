// A322 · O mini-grep de verdade: arquivo, argumentos e algoritmo

#include <stdio.h>
#include <string.h>
#include "padroes.h"

#define LINHA 512

typedef struct {
    const char *nome;
    Busca busca;
} Algoritmo;

static const Algoritmo algs[] = {
    {"bruta", pb_forca_bruta},
    {"kmp", pb_kmp},
    {"horspool", pb_horspool},
    {"rk", pb_rabin_karp},
};

// sem arquivo na linha de comando, cria um de exemplo em /tmp
static const char *arquivo_exemplo(void) {
    const char *caminho = "/tmp/lpedc-pedidos.txt";
    FILE *f = fopen(caminho, "w");
    if (f == NULL) {
        return NULL;
    }
    fputs("pedido 101: pastel de queijo, caldo de cana\n", f);
    fputs("pedido 102: pastel de carne\n", f);
    fputs("pedido 103: caldo de cana grande, caldo de cana pequeno\n", f);
    fputs("pedido 104: tapioca de coco\n", f);
    fclose(f);
    return caminho;
}

// uso: A322 padrão [arquivo] [bruta|kmp|horspool|rk]
int main(int argc, char *argv[]) {
    const char *padrao = argc > 1 ? argv[1] : "caldo de cana";
    const char *caminho = argc > 2 ? argv[2] : arquivo_exemplo();
    const char *escolha = argc > 3 ? argv[3] : "horspool";

    const Algoritmo *alg = NULL;
    for (int a = 0; a < 4; a++) {
        if (strcmp(escolha, algs[a].nome) == 0) {
            alg = &algs[a];
        }
    }
    if (alg == NULL || caminho == NULL) {
        fprintf(stderr, "uso: %s padrão [arquivo] [bruta|kmp|horspool|rk]\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(caminho, "r");
    if (f == NULL) {
        perror(caminho);
        return 1;
    }

    char linha[LINHA];
    int m = (int) strlen(padrao), num = 0, linhas_com = 0, total = 0;
    long comp = 0;
    while (fgets(linha, sizeof linha, f) != NULL) {
        num++;
        int n = (int) strlen(linha);
        if (n > 0 && linha[n - 1] == '\n') {
            linha[--n] = '\0';
        }
        int pos[16];
        int k = alg->busca(linha, n, padrao, m, pos, 16, &comp);
        if (k > 0) {
            printf("%d:%s  (coluna", num, linha);
            for (int i = 0; i < k && i < 16; i++) {
                printf(" %d", pos[i] + 1);
            }
            printf(")\n");
            linhas_com++;
            total += k;
        }
    }
    fclose(f);
    printf("%s: %d ocorrência(s) em %d linha(s), %ld comparações\n",
            alg->nome, total, linhas_com, comp);
    return linhas_com > 0 ? 0 : 1;   // como o grep: 0 se achou, 1 se não
}
// Saída (sem argumentos):
// 1:pedido 101: pastel de queijo, caldo de cana  (coluna 31)
// 3:pedido 103: caldo de cana grande, caldo de cana pequeno  (coluna 13 35)
// horspool: 3 ocorrência(s) em 2 linha(s), 54 comparações
//
// Outros jeitos de rodar:
//   ~/LPEDC/rodar A322.c pastel /tmp/lpedc-pedidos.txt kmp
//   ~/LPEDC/rodar A322.c include ~/LPEDC/24-busca-de-padroes/0161-juntando-tudo/A322.c bruta
