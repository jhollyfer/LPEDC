// A150 · Do texto para o binário

#include <stdio.h>
#include <stdlib.h>

// Converte uma lista de alunos em texto (fácil de editar) para um arquivo
// binário de registros fixos (fácil de consultar). Com um número na linha de
// comando, mostra só aquele aluno, indo direto ao registro com fseek.
//
// Rode assim:  ~/LPEDC/rodar 09-arquivos/0075-juntando-tudo/A150.c 2

typedef struct {
    char nome[20];
    double n1, n2;
} Aluno;

const char *TEXTO = "/tmp/turma.txt";
const char *BINARIO = "/tmp/turma.bin";

// lê o texto e grava o binário; devolve quantos alunos converteu (-1 = erro)
int converter(void) {
    FILE *ent = fopen(TEXTO, "r");
    if (ent == NULL) {
        perror(TEXTO);
        return -1;
    }
    FILE *sai = fopen(BINARIO, "wb");
    if (sai == NULL) {
        perror(BINARIO);
        fclose(ent);
        return -1;
    }
    Aluno a = {0};
    int n = 0;
    while (fscanf(ent, "%19s %lf %lf", a.nome, &a.n1, &a.n2) == 3) {
        fwrite(&a, sizeof a, 1, sai);
        n++;
    }
    fclose(ent);
    fclose(sai);
    return n;
}

void mostrar(int i, const Aluno *a) {
    printf("Aluno %d: %-6s média %.2f\n", i, a->nome, (a->n1 + a->n2) / 2);
}

int main(int argc, char *argv[]) {
    // 1. o arquivo texto, como alguém digitaria num editor
    FILE *arq = fopen(TEXTO, "w");
    if (arq == NULL) {
        perror(TEXTO);
        return 1;
    }
    fprintf(arq, "Ana 8.5 7.0\nBruno 6.0 5.5\nCarla 9.0 9.0\nDavi 7.5 8.0\n");
    fclose(arq);

    // 2. texto -> binário
    int total = converter();
    if (total < 0) {
        return 1;
    }
    printf("%d alunos convertidos (%zu bytes cada)\n", total, sizeof(Aluno));

    // 3. consulta: um aluno direto pelo número, ou todos
    arq = fopen(BINARIO, "rb");
    if (arq == NULL) {
        perror(BINARIO);
        return 1;
    }
    Aluno a;
    if (argc == 2) {
        char *fim;
        long i = strtol(argv[1], &fim, 10);
        if (*fim != '\0' || fim == argv[1] || i < 0 || i >= total) {
            fprintf(stderr, "Não existe o aluno %s (use 0 a %d)\n", argv[1], total - 1);
        } else {
            fseek(arq, i * (long) sizeof(Aluno), SEEK_SET);
            if (fread(&a, sizeof a, 1, arq) == 1) {
                mostrar((int) i, &a);
            }
        }
    } else {
        int i = 0;
        while (fread(&a, sizeof a, 1, arq) == 1) {
            mostrar(i, &a);
            i++;
        }
    }
    fclose(arq);
    remove(TEXTO);
    remove(BINARIO);
    return 0;
}
// $ rodar A150.c
// 4 alunos convertidos (40 bytes cada)
// Aluno 0: Ana    média 7.75
// Aluno 1: Bruno  média 5.75
// Aluno 2: Carla  média 9.00
// Aluno 3: Davi   média 7.75
//
// $ rodar A150.c 2
// 4 alunos convertidos (40 bytes cada)
// Aluno 2: Carla  média 9.00
