// 0072 · Arquivos texto
// Exercício E430 · ★★☆

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/turma.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "Bruna 9.0 7.5\n");
    fprintf(arq, "Diego 4.0 7.0\n");
    fprintf(arq, "Lia 6.5 7.5\n");
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }

    char nome[20];
    double n1, n2;
    double soma_medias = 0.0;
    int alunos = 0;
    while (fscanf(arq, "%19s %lf %lf", nome, &n1, &n2) == 3) {
        double media = (n1 + n2) / 2;
        printf("%-8s média %.2f  %s\n", nome, media, media >= 7.0 ? "aprovada(o)" : "reprovada(o)");
        soma_medias += media;
        alunos++;
    }
    if (alunos > 0) {
        printf("Média da turma: %.2f\n", soma_medias / alunos);
    }

    fclose(arq);
    remove(caminho);
    return 0;
}
