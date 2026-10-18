// 0068 · Arquivos binários
// Exercício E408 · ★★★

#include <stdio.h>

typedef struct {
    char descricao[24];
    double valor;
} Lancamento;

int main(void) {
    const char *caminho = "/tmp/extrato.bin";
    Lancamento lancamentos[6] = {
        {"Salário", 3500.00},  {"Aluguel", -1200.00},  {"Mercado", -387.60},
        {"Pix da Ana", 45.00}, {"Farmácia", -62.30},   {"Padaria", -18.90},
    };

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(lancamentos, sizeof(Lancamento), 6, arq);
    fclose(arq);

    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    Lancamento l;
    printf("Últimos lançamentos:\n");
    for (long k = 1; k <= 3; k++) {
        fseek(arq, -k * (long) sizeof(Lancamento), SEEK_END);
        if (fread(&l, sizeof l, 1, arq) == 1) {
            printf("%-15s %+8.2f\n", l.descricao, l.valor);
        }
    }

    rewind(arq);
    double saldo = 0.0;
    while (fread(&l, sizeof l, 1, arq) == 1) {
        saldo += l.valor;
    }
    fclose(arq);
    remove(caminho);
    printf("Saldo: R$ %.2f\n", saldo);
    return 0;
}
