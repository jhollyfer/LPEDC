// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0925 · ★★★ · Ordenar a fila da vacina dentro do arquivo

#include <stdio.h>

typedef struct {
    char nome[12];
    int idade;
} Paciente;

int leituras = 0, escritas = 0;

int le(FILE *arq, long i, Paciente *p) {
    fseek(arq, i * (long) sizeof(Paciente), SEEK_SET);
    leituras++;
    return fread(p, sizeof *p, 1, arq) == 1;
}

void grava(FILE *arq, long i, const Paciente *p) {
    fseek(arq, i * (long) sizeof(Paciente), SEEK_SET);
    escritas++;
    fwrite(p, sizeof *p, 1, arq);
}

void ordena(FILE *arq, long n) {
    for (long i = 0; i < n - 1; i++) {
        Paciente atual, maior, outro;
        le(arq, i, &atual);
        maior = atual;
        long pos_maior = i;
        for (long j = i + 1; j < n; j++) {
            le(arq, j, &outro);
            if (outro.idade > maior.idade) {
                maior = outro;
                pos_maior = j;
            }
        }
        if (pos_maior != i) {
            grava(arq, i, &maior);
            grava(arq, pos_maior, &atual);
        }
    }
}

int main(void) {
    const char *caminho = "/tmp/p0925_fila.bin";
    Paciente fila[6] = {{"Ana", 34}, {"Beto", 71}, {"Ceci", 18}, {"Davi", 65}, {"Eva", 80}, {"Fabio", 42}};

    FILE *arq = fopen(caminho, "wb+");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(fila, sizeof(Paciente), 6, arq);
    fseek(arq, 0, SEEK_END);
    long n = ftell(arq) / (long) sizeof(Paciente);

    ordena(arq, n);
    int l = leituras, e = escritas;

    rewind(arq);
    Paciente p;
    int k = 1;
    while (fread(&p, sizeof p, 1, arq) == 1) {
        printf("%d. %-6s %d anos\n", k++, p.nome, p.idade);
    }
    printf("Leituras: %d, escritas: %d\n", l, e);
    fclose(arq);
    remove(caminho);
    return 0;
}
