// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0913 · ★★☆ · Busca binária no cadastro do cursinho

#include <stdio.h>

typedef struct {
    int matricula;
    char nome[16];
} Aluno;

int busca(FILE *arq, int n, int matricula, Aluno *achado, int *leituras) {
    int ini = 0, fim = n - 1;
    *leituras = 0;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        Aluno a;
        fseek(arq, meio * (long) sizeof(Aluno), SEEK_SET);
        if (fread(&a, sizeof a, 1, arq) != 1) {
            return 0;
        }
        (*leituras)++;
        if (a.matricula == matricula) {
            *achado = a;
            return 1;
        }
        if (a.matricula < matricula) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return 0;
}

int main(void) {
    const char *caminho = "/tmp/p0913_alunos.bin";
    Aluno turma[8] = {
        {2003, "Ana"}, {2007, "Bruna"}, {2015, "Caue"}, {2022, "Duda"},
        {2030, "Enzo"}, {2041, "Kaio"}, {2048, "Lara"}, {2056, "Malu"},
    };

    FILE *arq = fopen(caminho, "wb+");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(turma, sizeof(Aluno), 8, arq);

    fseek(arq, 0, SEEK_END);
    int n = (int) (ftell(arq) / (long) sizeof(Aluno));
    printf("%d alunos no arquivo\n", n);

    int procuradas[3] = {2041, 2007, 2050};
    for (int k = 0; k < 3; k++) {
        Aluno a;
        int leituras;
        if (busca(arq, n, procuradas[k], &a, &leituras)) {
            printf("%d: %s (%d leituras)\n", procuradas[k], a.nome, leituras);
        } else {
            printf("%d: não encontrada (%d leituras)\n", procuradas[k], leituras);
        }
    }
    fclose(arq);
    remove(caminho);
    return 0;
}
