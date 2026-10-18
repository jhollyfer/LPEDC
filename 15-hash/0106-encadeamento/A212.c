// A212 · Fim de feira: atualizar, remover e o fator de carga

#include <stdio.h>
#include "tabela.h"

#define BALDES 5

int main(void) {
    Tabela *estoque = tabela_cria(BALDES);
    if (estoque == NULL) {
        return 1;
    }
    tabela_insere(estoque, "banana", 12);
    tabela_insere(estoque, "uva", 30);
    tabela_insere(estoque, "pera", 8);

    tabela_insere(estoque, "banana", 18); // chave repetida: só troca o valor
    tabela_remove(estoque, "uva");        // a uva acabou
    tabela_insere(estoque, "limao", 9);   // chegou fruta nova
    tabela_mostra(estoque);

    int n = tabela_tamanho(estoque);
    printf("itens: %d, fator de carga: %.2f\n", n, (double)n / BALDES);

    if (!tabela_remove(estoque, "uva")) {
        printf("uva: já tinha saído\n");
    }
    tabela_libera(estoque);
    return 0;
}
// Saída:
// [0] -> limao:9
// [1]
// [2]
// [3]
// [4] -> pera:8 -> banana:18
// itens: 3, fator de carga: 0.60
// uva: já tinha saído
