// A149 · Caderneta de gastos no terminal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Uma caderneta de gastos que sobrevive entre execuções: cada "novo" grava um
// registro binário no fim de /tmp/gastos.dat; "lista" lê tudo de volta;
// "exporta" gera um CSV de texto; "limpa" apaga o arquivo.
//
// Rode assim:  ~/LPEDC/rodar 09-arquivos/0075-juntando-tudo/A149.c lista

#define ARQUIVO "/tmp/gastos.dat"

typedef struct {
    char categoria[20];
    double valor;
} Gasto;

void uso(const char *programa) {
    fprintf(stderr, "Uso: %s novo <categoria> <valor>\n", programa);
    fprintf(stderr, "     %s lista | exporta <arquivo.csv> | limpa\n", programa);
}

int novo(const char *categoria, const char *texto_valor) {
    Gasto g;
    char *fim;
    g.valor = strtod(texto_valor, &fim);
    if (*fim != '\0' || g.valor <= 0) {
        fprintf(stderr, "Valor inválido: %s\n", texto_valor);
        return 1;
    }
    memset(g.categoria, 0, sizeof g.categoria);          // sem lixo no arquivo
    strncpy(g.categoria, categoria, sizeof g.categoria - 1);

    FILE *arq = fopen(ARQUIVO, "ab"); // binário, sempre no fim
    if (arq == NULL) {
        perror(ARQUIVO);
        return 1;
    }
    if (fwrite(&g, sizeof g, 1, arq) != 1) {
        perror(ARQUIVO);
        fclose(arq);
        return 1;
    }
    long registro = ftell(arq) / (long) sizeof(Gasto) - 1;
    fclose(arq);
    printf("Gravado: %s R$ %.2f (registro %ld)\n", g.categoria, g.valor, registro);
    return 0;
}

int lista(void) {
    FILE *arq = fopen(ARQUIVO, "rb");
    if (arq == NULL) {
        printf("Nenhum gasto ainda.\n");
        return 0;
    }
    Gasto g;
    int n = 0;
    double total = 0.0;
    while (fread(&g, sizeof g, 1, arq) == 1) {
        printf("%d  %-12s R$ %8.2f\n", n, g.categoria, g.valor);
        total += g.valor;
        n++;
    }
    fclose(arq);
    printf("Total: R$ %.2f em %d gastos\n", total, n);
    return 0;
}

int exporta(const char *destino) {
    FILE *ent = fopen(ARQUIVO, "rb");
    if (ent == NULL) {
        perror(ARQUIVO);
        return 1;
    }
    FILE *sai = fopen(destino, "w"); // texto, para abrir na planilha
    if (sai == NULL) {
        perror(destino);
        fclose(ent);
        return 1;
    }
    fprintf(sai, "categoria;valor\n");
    Gasto g;
    int n = 0;
    while (fread(&g, sizeof g, 1, ent) == 1) {
        fprintf(sai, "%s;%.2f\n", g.categoria, g.valor);
        n++;
    }
    fclose(ent);
    fclose(sai);
    printf("%d gastos exportados para %s\n", n, destino);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        uso(argv[0]);
        return 1;
    }
    const char *comando = argv[1];

    if (strcmp(comando, "novo") == 0 && argc == 4) {
        return novo(argv[2], argv[3]);
    }
    if (strcmp(comando, "lista") == 0 && argc == 2) {
        return lista();
    }
    if (strcmp(comando, "exporta") == 0 && argc == 3) {
        return exporta(argv[2]);
    }
    if (strcmp(comando, "limpa") == 0 && argc == 2) {
        remove(ARQUIVO);
        printf("Caderneta apagada.\n");
        return 0;
    }
    uso(argv[0]);
    return 1;
}
// $ rodar A149.c limpa
// Caderneta apagada.
// $ rodar A149.c novo mercado 152.40
// Gravado: mercado R$ 152.40 (registro 0)
// $ rodar A149.c novo luz 98.75
// Gravado: luz R$ 98.75 (registro 1)
// $ rodar A149.c novo farmacia 45.30
// Gravado: farmacia R$ 45.30 (registro 2)
// $ rodar A149.c lista
// 0  mercado      R$   152.40
// 1  luz          R$    98.75
// 2  farmacia     R$    45.30
// Total: R$ 296.45 em 3 gastos
// $ rodar A149.c exporta /tmp/gastos.csv
// 3 gastos exportados para /tmp/gastos.csv
