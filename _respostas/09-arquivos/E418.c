// 0070 · Juntando tudo
// Exercício E418 · ★★☆

#include <stdio.h>

typedef struct {
    char produto[16];
    int qtd;
    double preco;
} Venda;

int main(int argc, char *argv[]) {
    const char *binario = "/tmp/vendas.bin";
    const char *destino = argc >= 2 ? argv[1] : "/tmp/vendas.csv";
    Venda vendas[4] = {
        {"pastel", 30, 8.00},
        {"caldo de cana", 25, 6.50},
        {"tapioca", 12, 10.00},
        {"queijo", 4, 35.00},
    };

    FILE *arq = fopen(binario, "wb");
    if (arq == NULL) {
        perror(binario);
        return 1;
    }
    fwrite(vendas, sizeof(Venda), 4, arq);
    fclose(arq);

    FILE *ent = fopen(binario, "rb");
    if (ent == NULL) {
        perror(binario);
        return 1;
    }
    FILE *sai = fopen(destino, "w");
    if (sai == NULL) {
        perror(destino);
        fclose(ent);
        return 1;
    }
    fprintf(sai, "produto;qtd;total\n");
    Venda v;
    double total_geral = 0.0;
    while (fread(&v, sizeof v, 1, ent) == 1) {
        double total = v.qtd * v.preco;
        fprintf(sai, "%s;%d;%.2f\n", v.produto, v.qtd, total);
        total_geral += total;
    }
    fclose(ent);
    fclose(sai);
    remove(binario);

    sai = fopen(destino, "r");
    if (sai == NULL) {
        perror(destino);
        return 1;
    }
    char linha[100];
    while (fgets(linha, sizeof linha, sai) != NULL) {
        printf("%s", linha);
    }
    fclose(sai);
    printf("Total geral: R$ %.2f (gravado em %s)\n", total_geral, destino);
    return 0;
}
