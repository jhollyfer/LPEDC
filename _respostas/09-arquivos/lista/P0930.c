// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0930 · ★★★ · O índice da biblioteca

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char titulo[24];
    int ano;
} Livro;

typedef struct {
    int codigo;
    int posicao; // número do registro no arquivo de dados
} Entrada;

int compara(const void *a, const void *b) {
    const Entrada *x = a, *y = b;
    return (x->codigo > y->codigo) - (x->codigo < y->codigo);
}

long procura(FILE *indice, int codigo, int *leituras) {
    fseek(indice, 0, SEEK_END);
    long ini = 0, fim = ftell(indice) / (long) sizeof(Entrada) - 1;
    *leituras = 0;
    while (ini <= fim) {
        long meio = (ini + fim) / 2;
        Entrada e;
        fseek(indice, meio * (long) sizeof(Entrada), SEEK_SET);
        if (fread(&e, sizeof e, 1, indice) != 1) {
            return -1;
        }
        (*leituras)++;
        if (e.codigo == codigo) {
            return e.posicao;
        }
        if (e.codigo < codigo) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    const char *caminho_dados = "/tmp/p0930_dados.bin";
    const char *caminho_indice = "/tmp/p0930_indice.bin";
    Livro acervo[6] = {
        {3071, "Vidas Secas", 1938}, {1150, "Macunaima", 1928}, {4420, "Iracema", 1865},
        {2088, "Dom Casmurro", 1899}, {1999, "O Cortico", 1890}, {3500, "Grande Sertao", 1956},
    };
    int n = 6;

    FILE *dados = fopen(caminho_dados, "wb+");
    if (dados == NULL) {
        perror(caminho_dados);
        return 1;
    }
    fwrite(acervo, sizeof(Livro), n, dados);

    Entrada ind[6];
    for (int i = 0; i < n; i++) {
        ind[i].codigo = acervo[i].codigo;
        ind[i].posicao = i;
    }
    qsort(ind, n, sizeof(Entrada), compara);

    FILE *indice = fopen(caminho_indice, "wb+");
    if (indice == NULL) {
        perror(caminho_indice);
        fclose(dados);
        remove(caminho_dados);
        return 1;
    }
    fwrite(ind, sizeof(Entrada), n, indice);
    printf("Índice:");
    for (int i = 0; i < n; i++) {
        printf(" %d", ind[i].codigo);
    }
    printf("\n");

    int procurados[3] = {2088, 4420, 1000};
    for (int k = 0; k < 3; k++) {
        int leituras;
        long pos = procura(indice, procurados[k], &leituras);
        const char *plural = leituras == 1 ? "leitura" : "leituras";
        Livro l;
        fseek(dados, pos * (long) sizeof(Livro), SEEK_SET);
        if (pos >= 0 && fread(&l, sizeof l, 1, dados) == 1) {
            printf("%d: %s (%d), registro %ld, %d %s no índice\n", procurados[k], l.titulo, l.ano, pos,
                   leituras, plural);
        } else {
            printf("%d: não cadastrado, %d %s no índice\n", procurados[k], leituras, plural);
        }
    }
    fclose(dados);
    fclose(indice);
    remove(caminho_dados);
    remove(caminho_indice);
    return 0;
}
