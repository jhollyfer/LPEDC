// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0909 · ★☆☆ · O boletim que lê o aluno errado
//
// O programa grava 4 alunos (matrícula e nota) em binário e depois lê os
// registros 2, 0 e 3 com a função le_registro. Ele compila sem aviso, mas
// mostra números sem sentido: a função tem um erro de propósito na conta da
// posição. Conserte para a saída ficar:
//
//   Saída esperada:
//   Registro 2: matrícula 2203, nota 7.5
//   Registro 0: matrícula 2201, nota 9.0
//   Registro 3: matrícula 2204, nota 4.0
//
// Dicas:
// 1. O fseek conta em BYTES, não em registros.
// 2. O registro i começa no byte i * sizeof(Aluno).
// 3. Resposta esperada: fseek(arq, i * (long) sizeof(Aluno), SEEK_SET). A
//    saída fica igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

typedef struct {
    int matricula;
    float nota;
} Aluno;

// lê o registro i (contando de 0); devolve 1 se conseguiu
int le_registro(FILE *arq, int i, Aluno *a) {
    if (fseek(arq, i, SEEK_SET) != 0) {
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
