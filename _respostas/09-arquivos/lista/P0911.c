// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0911 · ★★☆ · Só os aprovados vão para o outro arquivo

#include <stdio.h>

int main(void) {
    const char *turma = "/tmp/p0911_turma.txt";
    const char *aprovados = "/tmp/p0911_aprovados.txt";

    FILE *arq = fopen(turma, "w");
    if (arq == NULL) {
        perror(turma);
        return 1;
    }
    fprintf(arq, "Ana 7.0 8.0\nBeto 5.0 4.5\nCaio 6.0 6.0\nDani 9.5 8.5\nEdu 3.0 7.0\n");
    fclose(arq);

    FILE *ent = fopen(turma, "r");
    if (ent == NULL) {
        perror(turma);
        return 1;
    }
    FILE *sai = fopen(aprovados, "w");
    if (sai == NULL) {
        perror(aprovados);
        fclose(ent);
        return 1;
    }
    char nome[20];
    double n1, n2;
    int total = 0, passaram = 0;
    while (fscanf(ent, "%19s %lf %lf", nome, &n1, &n2) == 3) {
        total++;
        double media = (n1 + n2) / 2;
        if (media >= 6) {
            fprintf(sai, "%s %.2f\n", nome, media);
            passaram++;
        }
    }
    fclose(ent);
    fclose(sai);

    sai = fopen(aprovados, "r");
    if (sai == NULL) {
        perror(aprovados);
        return 1;
    }
    char linha[64];
    while (fgets(linha, sizeof linha, sai) != NULL) {
        printf("%s", linha);
    }
    fclose(sai);
    remove(turma);
    remove(aprovados);

    printf("Aprovados: %d de %d\n", passaram, total);
    return 0;
}
