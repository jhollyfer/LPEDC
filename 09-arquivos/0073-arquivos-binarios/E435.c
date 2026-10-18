// 0073 · Arquivos binários
// Exercício E435 · ★★☆
//
// Atualizar um registro no meio do arquivo, sem reescrever o resto. O
// arquivo /tmp/contas.bin tem 3 contas (número e saldo). Complete a função
// depositar: ela abre o arquivo em "rb+" (ler e escrever sem apagar), vai
// até o registro da posição pedida, lê, soma o valor ao saldo, volta para o
// começo do mesmo registro e grava por cima. Devolve 1 se deu certo e 0 se
// não.
//
// O main deposita R$ 100.00 na conta da posição 1 e lista tudo de novo:
//
//   Antes:
//   1001  R$   250.00
//   1002  R$    80.50
//   1003  R$  1200.00
//   Depois:
//   1001  R$   250.00
//   1002  R$   180.50
//   1003  R$  1200.00
//
// Dicas:
// 1. Posição do registro i: i * sizeof(Conta). Use fseek com SEEK_SET.
// 2. Depois do fread, o arquivo está no FIM do registro. Para gravar por cima,
//    volte: fseek(arq, -(long) sizeof(Conta), SEEK_CUR).
// 3. Entre uma leitura e uma escrita no mesmo FILE, o C exige um fseek (ou
//    fflush). A volta da dica 2 já resolve isso.
// 4. Resposta esperada: só a conta 1002 muda, de 80.50 para 180.50.
//
// Escreva sua resposta abaixo (complete onde está o TODO):

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
    // TODO: abrir com "rb+", fseek, fread, somar, voltar, fwrite, fechar
    (void) posicao; // apague estas duas linhas quando usar os parâmetros
    (void) valor;
    return 0;
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
