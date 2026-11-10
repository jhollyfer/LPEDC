// A139 · Apagar um registro do meio

#include <stdio.h>
#include <stdlib.h>

// Arquivo binário não tem "apagar a linha 2". O jeito clássico: copiar todos
// os registros, menos o que sai, para um arquivo temporário e depois trocar
// um pelo outro com rename. O número do registro vem pela linha de comando.
//
// Rode assim:  ~/LPEDC/rodar 09-arquivos/0070-juntando-tudo/A139.c 1

#define ARQUIVO "/tmp/caderneta.dat"
#define TEMPORARIO "/tmp/caderneta.tmp"

typedef struct {
    char categoria[20];
    double valor;
} Gasto;

void listar(const char *titulo) {
    FILE *arq = fopen(ARQUIVO, "rb");
    if (arq == NULL) {
        perror(ARQUIVO);
        return;
    }
    printf("%s\n", titulo);
    Gasto g;
    int i = 0;
    while (fread(&g, sizeof g, 1, arq) == 1) {
        printf("  %d  %-10s R$ %7.2f\n", i, g.categoria, g.valor);
        i++;
    }
    fclose(arq);
}

// copia tudo menos o registro "alvo"; devolve quantos copiou (-1 = erro)
int apagar(long alvo) {
    FILE *ent = fopen(ARQUIVO, "rb");
    if (ent == NULL) {
        perror(ARQUIVO);
        return -1;
    }
    FILE *sai = fopen(TEMPORARIO, "wb");
    if (sai == NULL) {
        perror(TEMPORARIO);
        fclose(ent);
        return -1;
    }
    Gasto g;
    long i = 0;
    int copiados = 0;
    while (fread(&g, sizeof g, 1, ent) == 1) {
        if (i != alvo) {
            fwrite(&g, sizeof g, 1, sai);
            copiados++;
        }
        i++;
    }
    fclose(ent);
    fclose(sai);                           // tudo no disco antes de trocar
    if (rename(TEMPORARIO, ARQUIVO) != 0) { // o temporário vira a caderneta
        perror("rename");
        return -1;
    }
    return copiados;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <registro>\n", argv[0]);
        return 1;
    }
    // uma caderneta de exemplo, recriada a cada execução
    Gasto gastos[4] = {
        {"mercado", 152.40}, {"luz", 98.75}, {"farmacia", 45.30}, {"gas", 120.00},
    };
    FILE *arq = fopen(ARQUIVO, "wb");
    if (arq == NULL) {
        perror(ARQUIVO);
        return 1;
    }
    fwrite(gastos, sizeof(Gasto), 4, arq);
    fclose(arq);

    char *fim;
    long alvo = strtol(argv[1], &fim, 10);
    if (fim == argv[1] || *fim != '\0' || alvo < 0 || alvo >= 4) {
        fprintf(stderr, "Registro inválido: %s (use 0 a 3)\n", argv[1]);
        remove(ARQUIVO);
        return 1;
    }

    listar("Antes:");
    int restantes = apagar(alvo);
    if (restantes < 0) {
        remove(ARQUIVO);
        return 1;
    }
    listar("Depois:");
    printf("Registro %ld apagado, sobraram %d\n", alvo, restantes);
    remove(ARQUIVO);
    return 0;
}
// $ rodar A139.c 1
// Antes:
//   0  mercado    R$  152.40
//   1  luz        R$   98.75
//   2  farmacia   R$   45.30
//   3  gas        R$  120.00
// Depois:
//   0  mercado    R$  152.40
//   1  farmacia   R$   45.30
//   2  gas        R$  120.00
// Registro 1 apagado, sobraram 3
//
// $ rodar A139.c 9
// Registro inválido: 9 (use 0 a 3)
