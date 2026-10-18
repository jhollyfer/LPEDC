// 0072 · Arquivos texto
// Exercício E432 · ★★★

#include <stdio.h>

int main(void) {
    const char *estoque = "/tmp/estoque.txt";
    const char *comprar = "/tmp/comprar.txt";

    FILE *arq = fopen(estoque, "w");
    if (arq == NULL) {
        perror(estoque);
        return 1;
    }
    fprintf(arq, "arroz 3\ncafe 0\nleite 8\novos 2\nsabao 6\n");
    fclose(arq);

    FILE *ent = fopen(estoque, "r");
    if (ent == NULL) {
        perror(estoque);
        return 1;
    }
    FILE *sai = fopen(comprar, "w");
    if (sai == NULL) {
        perror(comprar);
        fclose(ent); // não deixa o primeiro aberto
        return 1;
    }
    char nome[30];
    int qtd;
    while (fscanf(ent, "%29s %d", nome, &qtd) == 2) {
        if (qtd < 5) {
            fprintf(sai, "%s %d\n", nome, 5 - qtd);
        }
    }
    fclose(ent);
    fclose(sai);

    sai = fopen(comprar, "r");
    if (sai == NULL) {
        perror(comprar);
        return 1;
    }
    int itens = 0;
    printf("Comprar:\n");
    while (fscanf(sai, "%29s %d", nome, &qtd) == 2) {
        printf("- %s: %d\n", nome, qtd);
        itens++;
    }
    fclose(sai);
    printf("%d itens na lista\n", itens);
    return 0;
}
