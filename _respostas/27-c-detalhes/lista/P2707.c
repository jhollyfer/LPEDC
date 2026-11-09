// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2707 · ★☆☆ · A lista da feira no arquivo

#include <stdio.h>

int main(void) {
    const char *nomes[] = {"banana", "tomate", "alface", "queijo"};
    double precos[] = {6.50, 8.90, 3.00, 22.40};

    FILE *f = fopen("p2707_feira.txt", "w");
    if (f == NULL) {
        printf("não consegui criar o arquivo\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        fprintf(f, "%s;%.2f\n", nomes[i], precos[i]);
    }
    fclose(f);
    printf("gravados 4 itens\n");

    f = fopen("p2707_feira.txt", "r");
    if (f == NULL) {
        printf("não consegui abrir o arquivo\n");
        return 1;
    }
    char nome[32];
    double preco, total = 0;
    while (fscanf(f, " %31[^;];%lf", nome, &preco) == 2) {
        printf("%s: R$ %.2f\n", nome, preco);
        total += preco;
    }
    fclose(f);
    remove("p2707_feira.txt");
    printf("total da feira: R$ %.2f\n", total);
    return 0;
}
