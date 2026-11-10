// A101 · O backup que copia qualquer coisa

#include <stdio.h>
#include <string.h>

// copia tam bytes de origem para destino; const void *: só lê a origem.
// Devolve destino, como o memcpy da string.h
void *copia_bytes(void *destino, const void *origem, size_t tam) {
    unsigned char *d = destino;
    const unsigned char *o = origem;
    for (size_t i = 0; i < tam; i++) {
        d[i] = o[i];
    }
    return destino;
}

int main(void) {
    int itens = 7;
    double total = 184.35;
    int qtd[4] = {2, 1, 6, 3}; // quantidade de cada produto no carrinho

    int itens_bkp;
    double total_bkp;
    int qtd_bkp[4];

    copia_bytes(&itens_bkp, &itens, sizeof itens);  // 4 bytes
    copia_bytes(&total_bkp, &total, sizeof total);  // 8 bytes
    copia_bytes(qtd_bkp, qtd, sizeof qtd);          // o vetor inteiro: 16 bytes

    qtd[2] = 0; // o cliente tirou os 6 iogurtes; o backup não muda
    printf("itens: %d, total: %.2f\n", itens_bkp, total_bkp);
    printf("qtd agora:  %d %d %d %d\n", qtd[0], qtd[1], qtd[2], qtd[3]);
    printf("qtd backup: %d %d %d %d\n", qtd_bkp[0], qtd_bkp[1], qtd_bkp[2], qtd_bkp[3]);

    // o void * devolvido precisa voltar ao tipo certo para ser lido
    int *volta = copia_bytes(qtd, qtd_bkp, sizeof qtd); // restaura o carrinho
    printf("restaurado: %d (o mesmo endereço de qtd? %d)\n", volta[2], volta == qtd);

    // a biblioteca já tem essa função pronta
    memcpy(&itens, &itens_bkp, sizeof itens);
    printf("memcpy: %d\n", itens);
    return 0;
}
// Saída:
// itens: 7, total: 184.35
// qtd agora:  2 1 0 3
// qtd backup: 2 1 6 3
// restaurado: 6 (o mesmo endereço de qtd? 1)
// memcpy: 7
