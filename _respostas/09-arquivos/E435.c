// 0073 · Arquivos binários
// Exercício E435 · ★★☆

#include <stdio.h>

typedef struct {
    int numero;
    double saldo;
} Conta;

const char *CAMINHO = "/tmp/contas.bin";

void listar(void) {
    FILE *arq = fopen(CAMINHO, "rb");
    if (arq == NULL) {
        perror(CAMINHO);
        return;
    }
    Conta c;
    while (fread(&c, sizeof c, 1, arq) == 1) {
        printf("%d  R$ %8.2f\n", c.numero, c.saldo);
    }
    fclose(arq);
}

int depositar(int posicao, double valor) {
    FILE *arq = fopen(CAMINHO, "rb+");
    if (arq == NULL) {
        perror(CAMINHO);
        return 0;
    }
    Conta c;
    if (fseek(arq, posicao * (long) sizeof(Conta), SEEK_SET) != 0 ||
        fread(&c, sizeof c, 1, arq) != 1) {
        fclose(arq);
        return 0;
    }
    c.saldo += valor;
    fseek(arq, -(long) sizeof(Conta), SEEK_CUR); // volta para o começo do registro
    size_t ok = fwrite(&c, sizeof c, 1, arq);
    fclose(arq);
    return ok == 1;
}

int main(void) {
    Conta contas[3] = {{1001, 250.00}, {1002, 80.50}, {1003, 1200.00}};
    FILE *arq = fopen(CAMINHO, "wb");
    if (arq == NULL) {
        perror(CAMINHO);
        return 1;
    }
    fwrite(contas, sizeof(Conta), 3, arq);
    fclose(arq);

    printf("Antes:\n");
    listar();
    if (!depositar(1, 100.00)) {
        printf("Depósito falhou\n");
    }
    printf("Depois:\n");
    listar();
    remove(CAMINHO);
    return 0;
}
