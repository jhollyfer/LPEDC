// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0909 · ★☆☆ · O boletim que lê o aluno errado

#include <stdio.h>

typedef struct {
    int matricula;
    float nota;
} Aluno;

// lê o registro i (contando de 0); devolve 1 se conseguiu
int le_registro(FILE *arq, int i, Aluno *a) {
    if (fseek(arq, i * (long) sizeof(Aluno), SEEK_SET) != 0) { // bytes, não registros
        return 0;
    }
    return fread(a, sizeof *a, 1, arq) == 1;
}

int main(void) {
    const char *caminho = "/tmp/p0909_alunos.bin";
    Aluno turma[4] = {{2201, 9.0f}, {2202, 6.5f}, {2203, 7.5f}, {2204, 4.0f}};

    FILE *arq = fopen(caminho, "wb+");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(turma, sizeof(Aluno), 4, arq);

    int pedidos[3] = {2, 0, 3};
    for (int k = 0; k < 3; k++) {
        Aluno a;
        if (le_registro(arq, pedidos[k], &a)) {
            printf("Registro %d: matrícula %d, nota %.1f\n", pedidos[k], a.matricula, a.nota);
        }
    }
    fclose(arq);
    remove(caminho);
    return 0;
}
