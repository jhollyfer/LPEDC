// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0921 · ★★★ · A agenda que se mantém em ordem no disco

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[16];
    char fone[16];
} Contato;

long conta(FILE *arq) {
    fseek(arq, 0, SEEK_END);
    return ftell(arq) / (long) sizeof(Contato);
}

int le(FILE *arq, long i, Contato *c) {
    fseek(arq, i * (long) sizeof(Contato), SEEK_SET);
    return fread(c, sizeof *c, 1, arq) == 1;
}

void grava(FILE *arq, long i, const Contato *c) {
    fseek(arq, i * (long) sizeof(Contato), SEEK_SET);
    fwrite(c, sizeof *c, 1, arq);
}

void insere(FILE *arq, const Contato *novo, int *deslocados) {
    long n = conta(arq);
    long pos = n;
    Contato c;
    for (long i = 0; i < n; i++) { // primeira posição com nome maior
        if (le(arq, i, &c) && strcmp(c.nome, novo->nome) > 0) {
            pos = i;
            break;
        }
    }
    for (long i = n - 1; i >= pos; i--) { // do fim para trás
        if (le(arq, i, &c)) {
            grava(arq, i + 1, &c);
            (*deslocados)++;
        }
    }
    grava(arq, pos, novo);
}

int busca(FILE *arq, const char *nome, Contato *achado, int *leituras) {
    long ini = 0, fim = conta(arq) - 1;
    *leituras = 0;
    while (ini <= fim) {
        long meio = (ini + fim) / 2;
        Contato c;
        if (!le(arq, meio, &c)) {
            return 0;
        }
        (*leituras)++;
        int cmp = strcmp(c.nome, nome);
        if (cmp == 0) {
            *achado = c;
            return 1;
        }
        if (cmp < 0) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return 0;
}

int main(void) {
    const char *caminho = "/tmp/p0921_agenda.bin";
    Contato novos[5] = {
        {"Marta", "92 99100-0001"}, {"Bia", "92 99100-0002"}, {"Rui", "92 99100-0003"},
        {"Caio", "92 99100-0004"}, {"Ana", "92 99100-0005"},
    };

    FILE *arq = fopen(caminho, "wb+");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    int deslocados = 0;
    for (int i = 0; i < 5; i++) {
        insere(arq, &novos[i], &deslocados);
    }

    long n = conta(arq);
    for (long i = 0; i < n; i++) {
        Contato c;
        if (le(arq, i, &c)) {
            printf("%ld %-7s %s\n", i, c.nome, c.fone);
        }
    }
    printf("Deslocamentos: %d\n", deslocados);

    const char *procurados[2] = {"Caio", "Zeca"};
    for (int k = 0; k < 2; k++) {
        Contato c;
        int leituras;
        if (busca(arq, procurados[k], &c, &leituras)) {
            printf("%s: %s (%d leitura%s)\n", procurados[k], c.fone, leituras, leituras == 1 ? "" : "s");
        } else {
            printf("%s: não está na agenda (%d leitura%s)\n", procurados[k], leituras,
                   leituras == 1 ? "" : "s");
        }
    }
    fclose(arq);
    remove(caminho);
    return 0;
}
