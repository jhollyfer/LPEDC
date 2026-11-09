// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0918 · ★★☆ · Salvar e carregar o orçamento da reforma

#include <stdio.h>

typedef struct {
    char descricao[20];
    int quantidade;
    double preco;
} Item;

int salva(const char *caminho, const Item *itens, int n) {
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        return 0;
    }
    fprintf(arq, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(arq, "%s %d %.2f\n", itens[i].descricao, itens[i].quantidade, itens[i].preco);
    }
    fclose(arq);
    return 1;
}

int carrega(const char *caminho, Item *itens, int max) {
    FILE *arq = fopen(caminho, "r");
    if (arq == NULL) {
        return -1;
    }
    int n, i = 0;
    if (fscanf(arq, "%d", &n) != 1) {
        fclose(arq);
        return 0;
    }
    while (i < n && i < max &&
           fscanf(arq, "%19s %d %lf", itens[i].descricao, &itens[i].quantidade, &itens[i].preco) == 3) {
        i++;
    }
    fclose(arq);
    return i;
}

int main(void) {
    const char *caminho = "/tmp/p0918_orcamento.txt";
    Item obra[3] = {{"cimento", 10, 32.90}, {"areia", 3, 120.00}, {"tijolo", 500, 0.85}};

    if (!salva(caminho, obra, 3)) {
        printf("Não salvou\n");
        return 1;
    }
    Item lidos[10];
    int n = carrega(caminho, lidos, 10);
    remove(caminho);
    if (n < 0) {
        printf("Não carregou\n");
        return 1;
    }
    printf("Carregados: %d itens\n", n);
    double total = 0;
    for (int i = 0; i < n; i++) {
        double sub = lidos[i].quantidade * lidos[i].preco;
        printf("%-10s %4d x R$ %6.2f = R$ %7.2f\n", lidos[i].descricao, lidos[i].quantidade,
               lidos[i].preco, sub);
        total += sub;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
